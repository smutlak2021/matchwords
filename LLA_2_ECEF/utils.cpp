#include "utils.h"
#include <iostream>
#include <string>
#include <fstream>

void removeSpaces(std::string& str){
    std::string ret;
    for(std::size_t i=0; i<str.length(); i++){
        //std::cout << str[i] <<std::endl;
        if(str[i] != '\t' && str[i] != ' '){
            //str.erase(str.begin()+i);
            ret += str[i];
        }
    }
    str = ret;
    str.shrink_to_fit();
}

GeoNumber linearInterpolation(std::pair<double, GeoNumber> p0, std::pair<double, GeoNumber> p1, double val){
    //time is x axis
    //(y0(x1-x) + y1(x-x0))/x1-x0
    GeoNumber y0 = p0.second;
    GeoNumber x0 = p0.first;
    GeoNumber y1 = p1.second;
    GeoNumber x1 = p1.first;
    GeoNumber x(val);

    return (y0*(x1-x) + y1*(x-x0))/(x1-x0);
    /*
    double x1_minus_x = p1.first - x;
    double x_minus_x0 = x - p0.first;
    double x1_minus_x0 = p1.first - p0.first;

    GeoNumber geo_x1_minus_x(x1_minus_x);
    GeoNumber geo_x_minus_x0(x_minus_x0);
    GeoNumber geo_x1_minus_x0(x1_minus_x0);

    GeoNumber y0_m_x1_minus_x;
    mpfr_mul(y0_m_x1_minus_x.get(), y0.get(), geo_x1_minus_x.get(), MPFR_RNDN);

    GeoNumber y1_m_x_minus_x0;
    mpfr_mul(y1_m_x_minus_x0.get(), y1.get(), geo_x_minus_x0.get(), MPFR_RNDN);

    GeoNumber numerator;
    mpfr_add(numerator.get(), y0_m_x1_minus_x.get(), y1_m_x_minus_x0.get(), MPFR_RNDN);
    
    GeoNumber ret;
    mpfr_div(ret.get(), numerator.get(), geo_x1_minus_x0.get(), MPFR_RNDN);
    

    return ret;*/
}

