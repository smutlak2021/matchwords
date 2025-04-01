#ifndef UTILS_H
#define UTILS_H

#include <string>
#include "geoNumber.h"
#include "ecefTrajectoy.h"
#include "ecef.h"

void removeSpaces(std::string& str);
GeoNumber linearInterpolation(std::pair<double, GeoNumber> point1, std::pair<double, GeoNumber> point2, double x);
#endif
