#ifndef LLA_CLASS_H
#define LLA_CLASS_H

#include <ostream>
#include "geoNumber.h"

class Lla
{
private:
    GeoNumber latitude_;
    GeoNumber longitude_;
    GeoNumber altitude_;

public:
    Lla(const GeoNumber& latit, const GeoNumber& longit, const GeoNumber& altit);
    Lla(const Lla &other);
    ~Lla();
    friend std::ostream &operator<<(std::ostream &os, const Lla &lla)
    {
        os << "latitude=" << lla.latitude_.getAsStr() << " longitude=" << lla.longitude_.getAsStr() << " altitude=" << lla.altitude_.getAsStr() << std::endl;
        return os;
    }

    const GeoNumber& GetLatitude() const;
    const GeoNumber& GetLongitude() const;
    const GeoNumber& GetAltitude() const;
};

#endif