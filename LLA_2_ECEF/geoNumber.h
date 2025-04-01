#ifndef GEO_NUMBER_CLASS_H
#define GEO_NUMBER_CLASS_H

#include <ostream>
#include <mpfr.h>

class GeoNumber
{
private:
    mpfr_t value_;

public:
    inline static const long MPFR_PREC = 1024;
    inline static const char *MPFR_PREC_FMT = "%.24Rf";

    /************************ common ************************/
    static GeoNumber _180;
    static GeoNumber _1000;
    static GeoNumber _PI;
    static GeoNumber _RADIAN_FACTOR;

    /************************ wgs84 ************************/
    static GeoNumber WGS84_A;
    static GeoNumber WGS84_A2;
    static GeoNumber WGS84_B;
    static GeoNumber WGS84_B2;
    static GeoNumber WGS84_E2;

    // constexpr long double wgs84_b = 6356752.314L;
    // constexpr long double wgs84_a2 = wgs84_a * wgs84_a;
    // constexpr long double wgs84_b2 = wgs84_b * wgs84_b;
    // constexpr long double f = 1.0L/298.257223563L;
    // const long double wgs84_e2 = 2*f-(f*f);

    // const long double wgs84_e = sqrt((wgs84_a2 - wgs84_b2) / wgs84_a2);
    // const long double wgs84_e2 = (wgs84_e * wgs84_e);

    static GeoNumber init_PI()
    {
        GeoNumber inst;
        mpfr_const_pi(inst.get(), MPFR_RNDN);
        return inst;
    };

    static GeoNumber init_180()
    {
        GeoNumber inst("180.0");
        return inst;
    };

    static GeoNumber init_1000()
    {
        GeoNumber inst("1000.0");
        return inst;
    };
    static GeoNumber init_RADIAN_FACTOR()
    {
        GeoNumber inst;
        mpfr_div(inst.get(), GeoNumber::_PI.get(), GeoNumber::_180.get(), MPFR_RNDN);
        return inst;
    };

    static GeoNumber init_WGS84_A()
    {
        GeoNumber inst("6378137.000");
        return inst;
    };

    static GeoNumber init_WGS84_B()
    {
        GeoNumber inst("6356752.314");
        return inst;
    };

    static GeoNumber init_WGS84_A2()
    {
        GeoNumber inst;
        mpfr_mul(inst.get(), GeoNumber::WGS84_A.get(), GeoNumber::WGS84_A.get(), MPFR_RNDN);
        return inst;
    };

    static GeoNumber init_WGS84_B2()
    {
        GeoNumber inst;
        mpfr_mul(inst.get(), GeoNumber::WGS84_B.get(), GeoNumber::WGS84_B.get(), MPFR_RNDN);
        return inst;
    };

    static GeoNumber init_WGS84_E2()
    {
        // 2*f-(f*f)
        GeoNumber f;
        GeoNumber numerator("1.0");
        GeoNumber denominator("298.257223563");
        mpfr_div(f.get(), numerator.get(), denominator.get(), MPFR_RNDN);

        GeoNumber f2;
        mpfr_mul(f2.get(), f.get(), f.get(), MPFR_RNDN);

        GeoNumber fm2;
        GeoNumber two("2.0");

        mpfr_mul(fm2.get(), two.get(), f.get(), MPFR_RNDN);

        GeoNumber inst;
        mpfr_sub(inst.get(), fm2.get(), f2.get(), MPFR_RNDN);
        return inst;
    };

public:
    GeoNumber();
    GeoNumber(std::string val);
    GeoNumber(double);
    GeoNumber(const GeoNumber &object);
    ~GeoNumber();

    friend std::ostream &operator<<(std::ostream &os, const GeoNumber &number)
    {
        os << number.value_;
        return os;
    }

    void set(std::string str);
    GeoNumber &operator=(const GeoNumber &object);
    mpfr_t &get();
    const mpfr_t &get() const;
    std::string getAsStr() const;

    GeoNumber operator+(const GeoNumber& other) const;
    GeoNumber operator-(const GeoNumber& other) const;
    GeoNumber operator*(const GeoNumber& other) const;
    GeoNumber operator/(const GeoNumber& other) const;
    GeoNumber sin() const;
    GeoNumber cos() const;
    GeoNumber sqrt() const;
 };

#endif