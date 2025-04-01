#include "geoNumber.h"
#include <string.h>
#include <mpfr.h>
#include "globals.h"

GeoNumber GeoNumber::_PI = GeoNumber::init_PI();
GeoNumber GeoNumber::_180 = GeoNumber::init_180();
GeoNumber GeoNumber::_1000 = GeoNumber::init_1000();
GeoNumber GeoNumber::_RADIAN_FACTOR = GeoNumber::init_RADIAN_FACTOR();
GeoNumber GeoNumber::WGS84_A = GeoNumber::init_WGS84_A();
GeoNumber GeoNumber::WGS84_A2 = GeoNumber::init_WGS84_A2();
GeoNumber GeoNumber::WGS84_B = GeoNumber::init_WGS84_B();
GeoNumber GeoNumber::WGS84_B2 = GeoNumber::init_WGS84_B2();
GeoNumber GeoNumber::WGS84_E2 = GeoNumber::init_WGS84_E2();

GeoNumber::GeoNumber()
{
    mpfr_init2(value_, MPFR_PREC);
}

GeoNumber::GeoNumber(double val)
{
    mpfr_init2(value_, MPFR_PREC);
    mpfr_set_d(value_, val, MPFR_RNDN);
}

GeoNumber::GeoNumber(std::string val)
{
    mpfr_init2(value_, MPFR_PREC);
    mpfr_set_str(value_, val.c_str(), 10, MPFR_RNDN);
}

GeoNumber::GeoNumber(const GeoNumber &object)
{
    mpfr_init2(value_, MPFR_PREC);
    mpfr_set(value_, object.value_, MPFR_RNDN);
}

GeoNumber::~GeoNumber()
{
    mpfr_clear(value_);
}

GeoNumber &GeoNumber::operator=(const GeoNumber &object)
{
    if (this != &object)
    {                       // Check for self-assignment
        mpfr_clear(value_); // Clear existing value
        mpfr_init2(value_, mpfr_get_prec(object.value_));
        mpfr_set(value_, object.value_, MPFR_RNDN);
    }
    return *this;
}

mpfr_t &GeoNumber::get()
{
    return value_;
}
const mpfr_t &GeoNumber::get() const
{
    return value_;
}

void GeoNumber::set(std::string str)
{
    mpfr_set_str(value_, str.c_str(), 10, MPFR_RNDN);
}

std::string GeoNumber::getAsStr() const
{
    std::string ret = "";
    char *str = NULL;
    mpfr_asprintf(&str, MPFR_PREC_FMT, value_);
    ret = str;
    mpfr_free_str(str);
    return ret;
}

GeoNumber GeoNumber::operator+(const GeoNumber &other) const
{
    GeoNumber ret;
    mpfr_add(ret.value_, this->value_, other.value_, MPFR_RNDN);
    return ret;
}

GeoNumber GeoNumber::operator-(const GeoNumber &other) const
{
    GeoNumber ret;
    mpfr_sub(ret.value_, value_, other.value_, MPFR_RNDN);
    return ret;
}
GeoNumber GeoNumber::operator*(const GeoNumber &other) const
{
    GeoNumber ret;
    mpfr_mul(ret.value_, value_, other.value_, MPFR_RNDN);
    return ret;
}
GeoNumber GeoNumber::operator/(const GeoNumber &other) const
{
    GeoNumber ret;
    mpfr_div(ret.value_, value_, other.value_, MPFR_RNDN);
    return ret;
}

GeoNumber GeoNumber::sin() const
{
    GeoNumber ret;
    mpfr_sin(ret.value_, value_, MPFR_RNDN);
    return ret;
}
GeoNumber GeoNumber::cos() const
{
    GeoNumber ret;
    mpfr_cos(ret.value_, value_, MPFR_RNDN);
    return ret;
}

GeoNumber GeoNumber::sqrt() const{
    GeoNumber ret;
    mpfr_sqrt(ret.value_, value_, MPFR_RNDN);
    return ret;
}
