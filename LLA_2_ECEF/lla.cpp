#include "lla.h"
#include "globals.h"

Lla::Lla(const GeoNumber &latitude, const GeoNumber &longitude, const GeoNumber &altitude)
: latitude_(latitude), longitude_(longitude), altitude_(altitude)
{
    
}

Lla::Lla(const Lla &other) 
: latitude_(other.latitude_), longitude_(other.longitude_), altitude_(other.altitude_)
{
    
}

Lla::~Lla()
{
    
}

const GeoNumber & Lla::GetLatitude() const
{
    return latitude_;
}
const GeoNumber & Lla::GetLongitude() const
{
    return longitude_;
}
const GeoNumber & Lla::GetAltitude() const
{
    return altitude_;
}
