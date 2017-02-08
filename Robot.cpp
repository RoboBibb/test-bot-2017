#include "Robot.hpp"
Robot::Robot(): drive(2,3,0,1),stickojoy(0) {
	drive.SetExpiration(0.1);
}
void Robot::RobotInit() {
	chooser.AddDefault(autoNameDefault, autoNameDefault);
	chooser.AddObject(autoNameCustom, autoNameCustom);
	frc::SmartDashboard::PutData("Auto Modes", &chooser);
}

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
void Robot::AutonomousInit()  {
	autoSelected = chooser.GetSelected();
	// std::string autoSelected = SmartDashboard::GetString("Auto Selector", autoNameDefault);
	std::cout << "Auto selected: " << autoSelected << std::endl;

	if (autoSelected == autoNameCustom) {
		// Custom Auto goes here
	} else {
		// Default Auto goes here
	}
}

void Robot::AutonomousPeriodic() {
	if (autoSelected == autoNameCustom) {
		// Custom Auto goes here
	} else {
		// Default Auto goes here
	}
}

void Robot::TeleopInit() {
	drive.SetSafetyEnabled(false);
	std::cout<<"@$$"<<std::endl;
}

void Robot::TeleopPeriodic() {
	drive.ArcadeDrive(utils::removeGhost(stickojoy.GetRawAxis(1)),utils::removeGhost(-stickojoy.GetRawAxis(4)));
}

void Robot::TestPeriodic() {
	lw->Run();
}


START_ROBOT_CLASS(Robot)
