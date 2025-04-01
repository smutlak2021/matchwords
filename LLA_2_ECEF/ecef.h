#ifndef ECEF_CLASS_H
#define ECEF_CLASS_H

#include <ostream>
#include "lla.h"

class Ecef{
    private:
        GeoNumber x_;
        GeoNumber y_;
        GeoNumber z_;
    
        

    public:
        Ecef(GeoNumber x, GeoNumber y, GeoNumber z);
        Ecef(const Ecef& other);
        Ecef(const Lla& lla);
        friend std::ostream& operator<<(std::ostream &os, const Ecef& ecef){
        os << "x=" << ecef.x_.getAsStr() << " y="<< ecef.y_.getAsStr() << " z=" << ecef.z_.getAsStr() << std::endl;
        return os;
    }
    static GeoNumber Calculate_N(GeoNumber& phi, GeoNumber& sin_phi);
    GeoNumber getX() const;
    GeoNumber getY() const;
    GeoNumber getZ() const;
};

#endif