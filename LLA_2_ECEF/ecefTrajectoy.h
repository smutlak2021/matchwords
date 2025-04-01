#ifndef ECEF_Trajectory_CLASS_H
#define ECEF_Trajectory_CLASS_H
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "ecef.h"
#include "llaTrajectory.h"

class EcefTrajectory
{
private:
    // std::unordered_map<GeoNumber, Lla *> trajectory;
    std::vector<std::pair<double, Ecef>> trajectory;
public:
    EcefTrajectory();
    // long LoadFromCSV(std::string csvFile);

    friend std::ostream& operator<<(std::ostream &os, const EcefTrajectory& traj)
    {
        int max = 10;
        os << "count: " << traj.trajectory.size() << std::endl;
        for (const auto &pair : traj.trajectory)
        {
            std::cout << std::setprecision(26) << pair.first << ": " << pair.second << std::endl;
            max--;
            // if(max<=0) break;
        }
        return os;
    }

    long Load(LlaTrajectory& llaTrajectory);
    std::pair<int,int> findClosest(double time);
    std::pair<double, Ecef> get(int index);
    int find(double time);
    int writeToCSV(std::string filename);
    void add(int index, double time, GeoNumber x, GeoNumber y, GeoNumber z);
    
};

#endif