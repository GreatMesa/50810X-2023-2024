#include "main.h"
using namespace okapi;
//Controller
pros::Controller master(master);
//Motors
Motor LU_FRONT(6,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor LU_BACK(9,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RU_FRONT(5,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RU_BACK(2,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor LD_FRONT(7,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor LD_BACK(8,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RD_FRONT(4,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RD_BACK(3,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);

Motor FlywheelL(1,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor FlywheelR(10,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
//Motor Groups
MotorGroup LeftDrive({LU_FRONT, LD_FRONT, LU_BACK, LD_BACK});
MotorGroup RightDrive({RU_FRONT, RD_FRONT, RU_BACK, RD_BACK});
MotorGroup Flywheel({FlywheelL, FlywheelR});
//Chassis
std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
    .withMotors(LeftDrive, RightDrive)
    .withDimensions({AbstractMotor::gearset::blue, 1.333}, {{2.75_in,12_in}, imev5BlueTPR})
    .build();
//Sensors
std::shared_ptr<okapi::IMU> Imu(new IMU(5));
//Solenoid
model::Solenoid lift('A',false);
model::Solenoid wingsL('B',false);
model::Solenoid wingsR('C',false);
