#include "llaTrajectory.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "utils.h"
#include <math.h>

// constexpr GeoNumber RADIAN_FACTOR = (22.0L/7.0L)/180.0L;

LlaTrajectory::LlaTrajectory()
{
}

long LlaTrajectory::LoadFromCSV(std::string csvFile)
{
    const char delimiter = ',';
    std::ifstream csv(csvFile);
    if (!csv.is_open())
    {
        return 0;
    }

    std::string line;
    while (std::getline(csv, line))
    {
        double tim=0.0;
        GeoNumber lat=0.0;
        GeoNumber lon=0.0;
        GeoNumber alt=0.0;

        removeSpaces(line);
        // std::cout << "aa" <<line << std::endl;
        std::size_t start = 0;
        std::size_t end = line.find_first_of(delimiter);
        int cnt = 0;
        while (end != std::string::npos)
        {
            std::string value = line.substr(start, end - start);
            // std::cout << "value: "<< value << std::endl;

            start = end + 1;
            end = line.find_first_of(delimiter, start);

            switch (cnt)
            {
            case 0:
                tim = std::stod(value);
                // tim.set(value);
                break;
            case 1:
                // lat = std::stold(value)*RADIAN_FACTOR;
                lat.set(value);
                break;
            case 2:
                // lon = std::stold(value)*RADIAN_FACTOR;
                lon.set(value);
                break;
            }

            cnt++;
        }
        
        // alt = std::stold(line.substr(start))*1000;
        alt.set(line.substr(start));
        // std::cout << "bb" << line << std::endl;
        // std::cout << std::setprecision(26) << "tim=" << tim << " lat=" << lat<< " lon=" << lon<< " alt=" << alt << std::endl;
        trajectory.push_back({tim, Lla(lat, lon, alt)});
    }
    csv.close();
    return trajectory.size();
}

const std::vector<std::pair<double, Lla>>& LlaTrajectory::getTrajectory(){
    return trajectory;
}


