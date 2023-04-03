#include "globals.hpp"
//Controller        
Controller master(ControllerId::master);
Controller partner(ControllerId::partner);
//DriveBase
// MOTORS
Motor Drive1(1, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 
Motor Drive2(2, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 
Motor Drive3(3, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 
Motor Drive4(8, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 
Motor Drive5(9, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees); 
Motor Drive6(10, true, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
MotorGroup LeftDrive({Drive1,Drive2,Drive3});
MotorGroup RightDrive({Drive4,Drive5,Drive6});
Motor Test(11,false,AbstractMotor::gearset::green, AbstractMotor::encoderUnits::degrees);

// SENSORS
IMU imu(4);
ADIEncoder Center (1, 2, false);

std::shared_ptr<ChassisController> chassis = ChassisControllerBuilder()
    .withMotors(LeftDrive, RightDrive)
    .withDimensions({AbstractMotor::gearset::blue, 3.6/6}, {{3.25_in, 1.294_ft}, imev5BlueTPR})
    .withSensors(Motor{2},Motor{5},ADIEncoder{'A', 'B', true})
    .build();