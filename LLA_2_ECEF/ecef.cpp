#include "ecef.h"
#include "lla.h"
#include <math.h>
#include <iostream>
#include <iomanip>
#include "globals.h"

Ecef::Ecef(GeoNumber x, GeoNumber y, GeoNumber z) : x_(x), y_(y), z_(z)
{
}

Ecef::Ecef(const Ecef &other) : x_(other.x_), y_(other.y_), z_(other.z_)
{
}

GeoNumber Ecef::Calculate_N(GeoNumber &phi, GeoNumber &sin_phi)
{
    GeoNumber one("1.0");
    GeoNumber N = GeoNumber::WGS84_A / (one - (GeoNumber::WGS84_E2 * (sin_phi * sin_phi))).sqrt();
    
    /*GeoNumber sin_phi2 = sin_phi * sin_phi;
    GeoNumber E2_m_sinPhi2 = GeoNumber::WGS84_E2 * sin_phi2;
    GeoNumber one("1.0");
    GeoNumber oneMinus_E2_m_sinPhi2 = one - E2_m_sinPhi2;
    GeoNumber sqrt_oneMinus_E2_m_sinPhi2 = oneMinus_E2_m_sinPhi2.sqrt();
    GeoNumber N = GeoNumber::WGS84_A / sqrt_oneMinus_E2_m_sinPhi2;*/

    // mpfr_mul(sin_phi2.get(), sin_phi.get(), sin_phi.get(), MPFR_RNDN);
    // mpfr_mul(E2_m_sinPhi2.get(), GeoNumber::WGS84_E2.get(), sin_phi2.get(), MPFR_RNDN);
    // mpfr_sub(oneMinus_E2_m_sinPhi2.get(), one.get(), E2_m_sinPhi2.get(), MPFR_RNDN);
    // mpfr_sqrt(sqrt_oneMinus_E2_m_sinPhi2.get(), oneMinus_E2_m_sinPhi2.get(), MPFR_RNDN);
    // mpfr_div(N.get(), GeoNumber::WGS84_A.get(), sqrt_oneMinus_E2_m_sinPhi2.get(), MPFR_RNDN);

    return N;
}

Ecef::Ecef(const Lla &lla)
{
    GeoNumber phi = lla.GetLatitude() * GeoNumber::_RADIAN_FACTOR;
    GeoNumber lambda = lla.GetLongitude() * GeoNumber::_RADIAN_FACTOR;
    GeoNumber h = lla.GetAltitude() * GeoNumber::_1000;

    GeoNumber sin_phi = phi.sin();
    GeoNumber cos_phi = phi.cos();
    GeoNumber N = Calculate_N(phi, sin_phi);

    
    GeoNumber N_plus_height = N + h;
    x_ = N_plus_height * (cos_phi*lambda.cos());
    GeoNumber cos_phi_m_sin_lambda = cos_phi*lambda.sin();
    y_ = N_plus_height * cos_phi_m_sin_lambda;
    // z
    GeoNumber wgs84_b2_div_wgs84_a2 = GeoNumber::WGS84_B2 / GeoNumber::WGS84_A2;
    GeoNumber wgs84_b2_div_wgs84_a2_m_N = wgs84_b2_div_wgs84_a2 * N;
    GeoNumber wgs84_b2_div_wgs84_a2_m_N_plus_h= wgs84_b2_div_wgs84_a2_m_N + h;
    z_ = wgs84_b2_div_wgs84_a2_m_N_plus_h * sin_phi;
    

  
    // mpfr_mul(phi.get(), lla.GetLatitude().get(), GeoNumber::_RADIAN_FACTOR.get(), MPFR_RNDN);
    // mpfr_mul(lambda.get(), lla.GetLongitude().get(), GeoNumber::_RADIAN_FACTOR.get(), MPFR_RNDN);
    // mpfr_mul(h.get(), lla.GetAltitude().get(), GeoNumber::_1000.get(), MPFR_RNDN);
    // mpfr_sin(sin_phi.get(), phi.get(), MPFR_RNDN);
    // mpfr_cos(cos_phi.get(), phi.get(), MPFR_RNDN);
    // mpfr_sin(sin_lambda.get(), lambda.get(), MPFR_RNDN);
    // mpfr_cos(cos_lambda.get(), lambda.get(), MPFR_RNDN);
    // mpfr_mul(cos_phi_m_cos_lambda.get(), cos_phi.get(), cos_lambda.get(), MPFR_RNDN);
    //mpfr_add(N_plus_height.get(), N.get(), h.get(), MPFR_RNDN);
    // mpfr_mul(x_.get(), N_plus_height.get(), cos_phi_m_cos_lambda.get(), MPFR_RNDN);
    // mpfr_mul(cos_phi_m_sin_lambda.get(), cos_phi.get(), sin_lambda.get(), MPFR_RNDN);
    //mpfr_mul(y_.get(), N_plus_height.get(), cos_phi_m_sin_lambda.get(), MPFR_RNDN);
    // z
    // mpfr_div(wgs84_b2_div_wgs84_a2.get(), GeoNumber::WGS84_B2.get(), GeoNumber::WGS84_A2.get(), MPFR_RNDN);
    // mpfr_mul(wgs84_b2_div_wgs84_a2_m_N.get(), wgs84_b2_div_wgs84_a2.get(), N.get(), MPFR_RNDN);
    // mpfr_add(wgs84_b2_div_wgs84_a2_m_N_plus_h.get(), wgs84_b2_div_wgs84_a2_m_N.get(), h.get(), MPFR_RNDN);
    // mpfr_mul(z_.get(), wgs84_b2_div_wgs84_a2_m_N_plus_h.get(), sin_phi.get(), MPFR_RNDN);
}

GeoNumber Ecef::getX() const
{
    return x_;
}
GeoNumber Ecef::getY() const
{
    return y_;
}
GeoNumber Ecef::getZ() const
{
    return z_;
}
