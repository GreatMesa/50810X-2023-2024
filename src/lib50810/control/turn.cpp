#include "turn.hpp"
namespace lib50810
{
    using namespace okapi;
    turnPID::turnPID(std::shared_ptr<okapi::IMU> Imu,
                     std::shared_ptr<ChassisController> ichassis,
                     double imerror,
                     double itime,
                     double ikp,
                     double iki,
                     double ikd)
    {
        this->imu = std::move(Imu);
        this->left = std::move(std::static_pointer_cast<SkidSteerModel>(ichassis->getModel())->getLeftSideMotor());
        this->right = std::move(std::static_pointer_cast<SkidSteerModel>(ichassis->getModel())->getRightSideMotor());
        this->merror = imerror;
        this->maxTime = itime;
        this->kp = ikp;
        this->ki = iki;
        this->kd = ikd;
    }
    double turnPID::step(double ierror, double iprevError, double min, double max)
    {
        double P = (ierror) * kp;
        double D = (ierror - iprevError) * kd;
        return std::clamp(P + D, min, max);
    }
    double turnPID::getError()
    {
        return error;
    }
    void turnPID::turn(QAngle iangle)
    {
        double angle = iangle.convert(degree);
        ifSettled = false;
        double time = 0;
        while(!ifSettled)
        {
            error = math::angleWrap180(imu->get() - angle);
            std::cout <<"Time: "<< time<<",error: "<< error << std::endl;
            power = step(error,lastError,-12.0,12.0);
            left->moveVoltage(power * 1000);
            right->moveVoltage(power * -1000);
            if(fabs(error) < merror || maxTime < time)
            {
                std::cout << "" << std::endl;
                ifSettled = true;
            }
            lastError = error;
            pros::delay(20);
            time += 0.02;
        }
        std::cout << error << std::endl;
        std::cout << "DONE" << std::endl;
        left->moveVoltage(0);
        right->moveVoltage(0);
    }
    void turnPID::turnExec(okapi::QAngle iangle, std::function<void()> function)
    {
        turn(iangle);
        function();
        turn(-iangle);
    }
}