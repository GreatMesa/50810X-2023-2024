#include "pathfollower.hpp"
namespace lib50810
{
    using namespace okapi;
    pathFollower::pathFollower(std::shared_ptr<ChassisController> ichassis,trapezoidalProfile iprofile,FFController ifeedfoward)
    {
        this->chassis = ichassis;
        this->profile = iprofile;
        this->ff = ifeedfoward;
        this->leftMotor = std::move(std::static_pointer_cast<SkidSteerModel>(chassis->getModel())->getLeftSideMotor());
        this->rightMotor = std::move(std::static_pointer_cast<SkidSteerModel>(chassis->getModel())->getRightSideMotor());
    }
    void pathFollower::move(QLength distance)
    {
        double lpow, rpow;
        leftMotor->tarePosition();
        rightMotor->tarePosition();
        
        std::vector<profilePoint> path = profile.generateProfile(distance);
        for(int i = 0; i < path.size(); i++)
        {
            double leftpos = math::tickToFt(leftMotor->getPosition(),chassis->getChassisScales(),chassis->getGearsetRatioPair());
            double leftvel = math::rpmToftps(leftMotor->getActualVelocity(),chassis->getChassisScales(),chassis->getGearsetRatioPair());
            double rightpos = math::tickToFt(rightMotor->getPosition(),chassis->getChassisScales(),chassis->getGearsetRatioPair());
            double rightvel = math::rpmToftps(rightMotor->getActualVelocity(),chassis->getChassisScales(),chassis->getGearsetRatioPair());

            std::cout<<path[i].leftpos * 12<<leftpos * 12<<" error: "<<(path[i].leftpos - leftpos) * 12<<std::endl;
            lpow = ff.step(path[i].leftpos,path[i].leftvel,path[i].leftaccel,leftpos,leftvel);
            rpow = ff.step(path[i].rightpos,path[i].rightvel,path[i].rightaccel,rightpos,rightvel);
            chassis->getModel()->tank(lpow,rpow);
            pros::delay(profile.divs * 1000);
        }
        chassis->getModel()->tank(0,0);
        std::cout << "Done" << std::endl;
    }
    void pathFollower::turn(QAngle angle)
    {
        double lpow, rpow;
        leftMotor->tarePosition();
        rightMotor->tarePosition();
        QLength distance = (angle.convert(radian) * chassis->getChassisScales().wheelTrack/2);
        std::vector<profilePoint> path = profile.generateProfile(distance);
        for(int i = 0; i < path.size(); i++)
        {
            double leftpos = math::tickToFt(leftMotor->getPosition(),chassis->getChassisScales(),chassis->getGearsetRatioPair());
            double leftvel = math::rpmToftps(leftMotor->getActualVelocity(),chassis->getChassisScales(),chassis->getGearsetRatioPair());
            double rightpos = math::tickToFt(rightMotor->getPosition(),chassis->getChassisScales(),chassis->getGearsetRatioPair());
            double rightvel = math::rpmToftps(rightMotor->getActualVelocity(),chassis->getChassisScales(),chassis->getGearsetRatioPair());

            std::cout<<path[i].leftpos * 12<<leftpos * 12<<" error: "<<(path[i].leftpos - leftpos) * 12<<std::endl;
            lpow = ff.step(path[i].leftpos,path[i].leftvel,path[i].leftaccel,leftpos,leftvel);
            rpow = ff.step(-path[i].rightpos,-path[i].rightvel,-path[i].rightaccel,-rightpos,-rightvel);
            chassis->getModel()->tank(lpow,rpow);
            pros::delay(profile.divs * 1000);
        }
    }
}