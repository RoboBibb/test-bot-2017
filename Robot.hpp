/*
 * Robot.hpp
 *
 *  Created on: Feb 7, 2017
 *      Author: team
 */

#ifndef SRC_ROBOT_HPP_
#define SRC_ROBOT_HPP_
#include <iostream>
#include <memory>
#include <string>

#include "WPILib.h"

class Robot: public frc::IterativeRobot {
private:
	RobotDrive drive;
	Joystick stickojoy;
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;

public:
	Robot();
	void RobotInit();

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit();

	void AutonomousPeriodic();

	void TeleopInit();

	void TeleopPeriodic();

	void TestPeriodic();


};

namespace utils{
	float removeghost(float ghost){
		if(ghost<.15&&ghost>-.15){
			return 0.0f;
		}else{
			return ghost;
		}
	}
}



#endif /* SRC_ROBOT_HPP_ */
