#include "config.hpp"
using namespace lib50810;
ChassisConstraint constraint(7_ftps,10_ftps2,10_ftps2);
FFController feedfoward(0.24,0.02,0.02,0.05,0);
pathFollower profile(chassis,trapezoidalProfile(constraint,0.02),feedfoward);
turnPID turnController(Imu,chassis,0.5,2,0.15,0,0.18);
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button()
{
	
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous()
{
	LeftDrive.setBrakeMode(AbstractMotor::brakeMode::brake);
	RightDrive.setBrakeMode(AbstractMotor::brakeMode::brake);
	profile.move(35_in);
	profile.move(-10_in);
 }

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol()
{
	Catapult.moveRelative(360,300);
	LeftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
	RightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
	//Joystick Values
	double A1 = 0;
	double A2 = 0;
	double A3 = 0;
	double A4 = 0;
	while(true){
	//Collecting Controller Values
	A1 = master.getAnalog(ControllerAnalog::leftY);
	A3 = master.getAnalog(ControllerAnalog::rightX);
	//Setting up Driver Control
	chassis->getModel()->arcade(-A1,-(A3 * A3));
	
	pros::delay(20);
	}
}