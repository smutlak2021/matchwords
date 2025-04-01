#include <iostream>
#include "llaTrajectory.h"
#include "ecefTrajectoy.h"
#include "utils.h"
#include <limits>

int main()
{
    LlaTrajectory llaTrajectory;
    int count = llaTrajectory.LoadFromCSV("SciTec_code_problem_data.csv");
    std::cout << "(" << count << ") read" << std::endl;
    // std::cout << llaTrajectory << std::endl;

    EcefTrajectory ecefTrajectory;
    count = ecefTrajectory.Load(llaTrajectory);
    std::cout << "(" << count << ") Converted to ECEF" << std::endl;
    // std::cout << ecefTrajectory << std::endl;
    std::cout << "Writing to result.csv ...";
    count = ecefTrajectory.writeToCSV("result.csv");
    std::cout << count << " was written" << std::endl;

    // 1532334000
    // 1532335268
    int cnt = 0;
    double requiredTime;
    while (true)
    {
        if (cnt == 0)
            requiredTime = 1532334000.0;
        if (cnt == 1)
            requiredTime = 1532335268.0;
        std::cout << "Enter epoch time:";
        if (cnt <= 1 || std::cin >> requiredTime)
        {
            std::cout << "process " << std::setprecision(25) << requiredTime << std::endl;
            int index = ecefTrajectory.find(requiredTime);
            if (index >= 0)
            {
                std::pair<double, Ecef> item = ecefTrajectory.get(index);
                std::cout << "Exact Match found(" << index << ")" << std::endl;
                // "):"<< item.first << " " << item.second << std::endl;
            }
            else
            {
                std::pair<int, int> closest = ecefTrajectory.findClosest(requiredTime);
                if (closest.first == -1 || closest.second == -1)
                {
                    std::cout << "Unable to process(out of range), try another value..." << std::endl;
                }
                else
                {
                    // std::cout << closest.first << "," << closest.second << std::endl;
                    std::pair<double, Ecef> first = ecefTrajectory.get(closest.first);
                    std::pair<double, Ecef> second = ecefTrajectory.get(closest.second);
                    // std::cout << "Between(" << closest.first << "):" << first.first << " " << first.second << std::endl;
                    // std::cout << "and("  << closest.second << "):" <<  second.first << " " << second.second << std::endl;

                    GeoNumber x = linearInterpolation({first.first, first.second.getX()}, {second.first, second.second.getX()}, requiredTime);
                    GeoNumber y = linearInterpolation({first.first, first.second.getY()}, {second.first, second.second.getY()}, requiredTime);
                    GeoNumber z = linearInterpolation({first.first, first.second.getZ()}, {second.first, second.second.getZ()}, requiredTime);
                    std::cout << "x =" << x.getAsStr() << " y=" << y.getAsStr() << " z=" << z.getAsStr() << std::endl;

                    // add location
                    ecefTrajectory.add(closest.second, requiredTime, x, y, z);
                    std::cout << "New ECEF location add to (index=" << closest.second << ")" << std::endl;
                    // re-write csv file
                    std::cout << "Writing to result.csv ...";
                    count = ecefTrajectory.writeToCSV("result.csv");
                    std::cout << count << " was written" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Invalid input. Exit! Good bye" << std::endl;
            break;
        }
        cnt++;
    }

    // std::pair<int, int> closest = ecefTrajectory.findClosest(1532334000.00);
    // std::cout << closest.first << "," << closest.second << std::endl;

    // // std::cout << "running ..." << std::endl;
    // // calc ECEF velocity vector at 1532334000
    // // std::cout <<"CEF velocity vector at 1532334000"<< std::endl;
    // // calc ECEF velocity vector at 1532335268
    // // std::cout <<"ECEF velocity vector at 1532335268"<< __cplusplus <<std::endl;
    // std::cout << "Size of long double: " << sizeof(long double) << " bytes" << std::endl;
    // std::cout << "Precision of long double: " << std::numeric_limits<long double>::digits10 << " decimal digits" << std::endl;
    return 0;
}