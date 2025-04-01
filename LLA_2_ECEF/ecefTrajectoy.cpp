#include "ecefTrajectoy.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "utils.h"
#include "llaTrajectory.h"
#include "ecef.h"
#include <algorithm>

EcefTrajectory::EcefTrajectory()
{
}

long EcefTrajectory::Load(LlaTrajectory &llaTrajectory)
{
    const std::vector<std::pair<double, Lla>> &llaTraj = llaTrajectory.getTrajectory();
    for (const auto &pair : llaTraj)
        this->trajectory.push_back({pair.first, Ecef(pair.second)});
    return trajectory.size();
}

int EcefTrajectory::find(double time)
{
    double tolerance = 0.001;
    auto it = std::find_if(this->trajectory.begin(), this->trajectory.end(),
                           [&time, &tolerance](const std::pair<double, Ecef> &p)
                           {
                               return std::abs(p.first - time) < tolerance;
                           });
    if (it != this->trajectory.end())
        return it - trajectory.begin();
    else
        return -1;
}

std::pair<int, int> EcefTrajectory::findClosest(double time)
{
    auto it = std::lower_bound(trajectory.begin(), trajectory.end(), time,
                               [](const std::pair<double, Ecef> &pair, double v)
                               {
                                   return pair.first < v;
                               });

    if (it == trajectory.begin())
        return {-1, 0};
    if (it == trajectory.end())
        return {trajectory.size() - 1, -1};

    int upper_idx = it - trajectory.begin();
    int lower_idx = upper_idx - 1;

    return {lower_idx, upper_idx};
}

std::pair<double, Ecef> EcefTrajectory::get(int index)
{
    return trajectory[index];
}

int EcefTrajectory::writeToCSV(std::string filename)
{
    int ret = 0;
    std::ofstream outfile(filename); //std::ios::app
    if (outfile.is_open())
    {
        outfile << "x,y,z" << std::endl;
        for (const auto &pair : trajectory)
        {
            outfile << std::fixed << std::setprecision(2) << pair.first << ",";
            outfile << pair.second.getX().getAsStr() << ",";
            outfile << pair.second.getY().getAsStr() << ",";
            outfile << pair.second.getZ().getAsStr();
            outfile << std::endl;
            ret++;
        }
        outfile.close();
    }

    return ret;
}

void EcefTrajectory::add(int index, double time, GeoNumber x, GeoNumber y, GeoNumber z){
    trajectory.insert(trajectory.begin() + index, {time, Ecef(x, y, z)});
}

