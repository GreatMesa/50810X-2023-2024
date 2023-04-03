#pragma once
#include "okapi/api/units/RQuantity.hpp"
#include "okapi/api/units/QLength.hpp"
#include "okapi/api/units/QAngularSpeed.hpp"
#include "okapi/api/units/QAngularAcceleration.hpp"
#include "okapi/api/units/QArea.hpp"
#include "okapi/api/units/QTime.hpp"
#include "okapi/api/units/QSpeed.hpp"
#include "okapi/api/units/QAcceleration.hpp"
#include "okapi/api/units/QJerk.hpp"
#include "okapi/api/units/QAngularJerk.hpp"

namespace okapi{
// Predegined Number unit
constexpr Number pct = number / 100;

// Predefined Length Units
constexpr QLength court = 12 * foot;

// Predefined Speed Unit
constexpr QSpeed ftps = foot / second;

// Predefined Acceleration Unit
constexpr QAcceleration ftps2 = ftps / second;

// Predefined Jerk Unit
constexpr QJerk mps3 = mps2 / second;
constexpr QJerk ftps3 = ftps2 / second;
//Predifined Angular Speed Unit
constexpr QAngularSpeed degps = degree/second;
//Predifined Angular Acceleration Unit
constexpr QAngularAcceleration radps2 = radps / second;
constexpr QAngularAcceleration degps2 = degps / second;
//Predifined Angular Jerk Unit
constexpr QAngularJerk radps3 = radps2 / second;
constexpr QAngularJerk degps3 = degps2 / second;
inline namespace literals{
// number unit literals
constexpr Number operator"" _pct(long double x) { return static_cast<double>(x)*pct; }
constexpr Number operator"" _pct(unsigned long long int x) { return static_cast<double>(x)*pct; }

// Length Unit Literals
constexpr QLength operator"" _court(long double x) { return static_cast<double>(x)*court; }
constexpr QLength operator"" _court(unsigned long long int x) { return static_cast<double>(x)*court; }

// Predefined Speed Unit
constexpr QSpeed operator"" _ftps(long double x) { return static_cast<double>(x)*ftps; }
constexpr QSpeed operator"" _ftps(unsigned long long int x) { return static_cast<double>(x)*ftps; }

// Predefined Acceleration Unit
constexpr QAcceleration operator"" _ftps2(long double x) { return static_cast<double>(x)*ftps2; }
constexpr QAcceleration operator"" _ftps2(unsigned long long int x) { return static_cast<double>(x)*ftps2; }

// Jerk Literals
constexpr QJerk operator"" _mps3(long double x) { return static_cast<double>(x)*mps3; }
constexpr QJerk operator"" _mps3(unsigned long long int x) { return static_cast<double>(x)*mps3; }
constexpr QJerk operator"" _ftps3(long double x) { return static_cast<double>(x)*ftps3; }
constexpr QJerk operator"" _ftps3(unsigned long long int x) { return static_cast<double>(x)*ftps3; }

//Angular Speed Literal
constexpr QAngularSpeed operator"" _degps(long double x) { return static_cast<double>(x)*degps; }
constexpr QAngularSpeed operator"" _degps(unsigned long long int x) { return static_cast<double>(x)*degps; }
//Angular Acceleration Literal 
constexpr QAngularAcceleration operator"" _degps2(long double x) { return static_cast<double>(x)*degps2; }
constexpr QAngularAcceleration operator"" _degps2(unsigned long long int x) { return static_cast<double>(x)*degps2; }
constexpr QAngularAcceleration operator"" _radps2(long double x) { return static_cast<double>(x)*radps2; }
constexpr QAngularAcceleration operator"" _radps2(unsigned long long int x) { return static_cast<double>(x)*radps2; }
//Angular Jerk Literal
constexpr QAngularJerk operator"" _degps3(long double x) { return static_cast<double>(x)*degps3; }
constexpr QAngularJerk operator"" _degps3(unsigned long long int x) { return static_cast<double>(x)*degps3; }
constexpr QAngularJerk operator"" _radps3(long double x) { return static_cast<double>(x)*radps3; }
constexpr QAngularJerk operator"" _radps3(unsigned long long int x) { return static_cast<double>(x)*radps3; }
} // namespace literals
} // namespace okapi