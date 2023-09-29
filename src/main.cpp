#include "config.hpp"

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
void autonomous() {}

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
	LeftDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
	RightDrive.setBrakeMode(AbstractMotor::brakeMode::coast);
	while(true){
	chassis->getModel()->arcade(master.getAnalog(ControllerAnalog::leftY) * master.getAnalog(ControllerAnalog::leftY),master.getAnalog(ControllerAnalog::rightX) * master.getAnalog(ControllerAnalog::rightX));
	if(master[ControllerDigital::L1].changedToPressed())
		{
			Catapult.moveRelative(-1080,300);
		}
	if(master[ControllerDigital::up].changedToPressed())
		{
			Catapult.moveRelative(-120,300);
		}
	if(master[ControllerDigital::A].changedToPressed())
		{
			Catapult.moveVoltage(-6500);
		}
	if(master[ControllerDigital::B].changedToPressed())
		{
			Catapult.moveVoltage(0);
		}
	if(master[ControllerDigital::R2].changedToPressed())
		{
			claw.toggle();
		}
	if(master[ControllerDigital::L2].changedToPressed())
		{
			wings.toggle();
		}
	pros::delay(20);
	}
}