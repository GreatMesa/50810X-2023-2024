#include "Math.hpp"
namespace lib50810
{
    using namespace okapi;
    namespace math
    {
        template <typename T>
        T clamp(T val, T min, T max)
        {
            return std::max(std::min(max, val), min);
        }
        double ftToTick(double ft, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset)
        {
            return ft * 12 / (scale.wheelDiameter.convert(okapi::inch) * 3.14159) * (gearset.ratio) * scale.tpr;
        }
        double tickToFt(double tick, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset)
        {
            return (tick / scale.tpr) / (gearset.ratio) * (scale.wheelDiameter.convert(okapi::inch) * 3.14159) / 12;
        }
        double getNewEqnRange(double val, double olimit, double nlimit)
        {
            double factor = nlimit / olimit;
            return factor * val;
        }
        double ftpsTorpm(double ftps, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset)
        {
            return ftps * 12 / (scale.wheelDiameter.convert(okapi::inch) * 3.14159) * gearset.ratio * 60;
        }

        double rpmToftps(double rpm, okapi::ChassisScales scale, okapi::AbstractMotor::GearsetRatioPair gearset)
        {
            return rpm / 60 / gearset.ratio * (scale.wheelDiameter.convert(okapi::inch) * 3.14159) / 12;
        }
        double angleWrap180(double angle){
            return angle - 360.0 * std::floor((angle + 180.0) * (1.0 / 360.0));
        }
    }
}
