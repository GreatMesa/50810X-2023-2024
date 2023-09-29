#include "main.h"
using namespace okapi;
//Controller
okapi::Controller master(ControllerId::master);
//Motors
Motor LeftFront(1,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor LeftMiddle(2,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor LeftBack(3,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RightFront(6,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RightMiddle(7,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor RightBack(8,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor Catapult1(5,false,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
Motor Catapult2(10,true,AbstractMotor::gearset::blue,AbstractMotor::encoderUnits::degrees);
//Motor Groups
MotorGroup LeftDrive({LeftFront, LeftMiddle, LeftBack});
MotorGroup RightDrive({RightFront, RightMiddle, RightBack});
MotorGroup Catapult({Catapult1,Catapult2});
//Chassis
std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
    .withMotors(LeftDrive, RightDrive)
    .withDimensions({AbstractMotor::gearset::blue, 1.667}, {{3.25_in, 1.294_ft}, imev5BlueTPR})
    .build();
//Solenoid
model::Solenoid claw('A',false);
model::Solenoid wings('B',false);