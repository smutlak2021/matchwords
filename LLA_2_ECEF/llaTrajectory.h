#ifndef LLA_Trajectory_CLASS_H
#define LLA_Trajectory_CLASS_H
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <string>
#include "lla.h"

class LlaTrajectory
{
private:
    // std::unordered_map<GeoNumber, Lla *> trajectory;
    std::vector<std::pair<double, Lla>> trajectory;
public:
    LlaTrajectory();
    long LoadFromCSV(std::string csvFile);

    friend std::ostream& operator<<(std::ostream &os, const LlaTrajectory& traj)
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

    const std::vector<std::pair<double, Lla>>& getTrajectory();
};

#endif