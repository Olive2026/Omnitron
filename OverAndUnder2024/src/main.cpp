/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       goldenolives                                              */
/*    Created:      1/13/2024, 12:26:41 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// rightMotor1           motor         1               
// rightMotor2           motor         9               
// rightMotor3           motor         2               
// leftMotor1            motor         11              
// lefttMotor2           motor         4               
// lefttMotor3           motor         19

// Controller1          controller                    
// frontIntake          motor         15              
// valve                digital_out   A               
// limitSwitch          limit         H               
// thwacker             motor         10               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
bool cataRunning = false;
void runCata()
{
  cataRunning = !cataRunning;
  if(cataRunning)
  {
    thwacker.spin(forward);
  }
  else 
  {
    thwacker.stop();
  }
}
void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  vexcodeInit();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  
  // ..........................................................................

  
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// may add another controller
//controller Controller1 = controller(primary);

motor_group left_motors(leftMotor1, leftMotor2, leftMotor3);
motor_group right_motors(rightMotor1, rightMotor2, rightMotor3);

double wheel_diameter = 4;
double wheel_circumference = 2 * wheel_diameter/2 * 3.14; // 2 * r * PI
double wheel_distance = 12; // 14 inches
double wheel_base = 12.5;
double gearRat = 4/7;

drivetrain robot(left_motors, right_motors, wheel_circumference, wheel_distance, wheel_base, distanceUnits::in, gearRat);

// void solonoid(){
//   if(valve.value() == 1){
//     valve.set(false);
//   } else if(valve.value() == 0) {
//     valve.set(true);
//   }
// }

void skillAuton(void)
{
  robot.setDriveVelocity(50, percentUnits::pct);
  thwacker.setVelocity(60, percentUnits::pct);
  runCata();
  //TODO: wait for 35 secs
  wait(30, sec); // msec is also possible for milliseconds precision

  //stop catapult, toggle off
  runCata();
  //goforward
  robot.driveFor(directionType::fwd, 30, distanceUnits::in);
  robot.turnFor(60, rotationUnits::deg);
  robot.driveFor(directionType::fwd, 50, distanceUnits::in);
  valve.set(true);
  robot.driveFor(directionType::fwd, 10, distanceUnits::in);
  robot.driveFor(directionType::fwd, -10, distanceUnits::in);
  robot.driveFor(directionType::fwd, 10, distanceUnits::in);
}
void usercontrol(void) {
  // define a task that will handle monitoring inputs from Controller1
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis2 + Axis4
      // right = Axis2 - Axis4
      int drivetrainLeftSideSpeed = Controller1.Axis2.position() + Controller1.Axis4.position();
      int drivetrainRightSideSpeed = Controller1.Axis2.position() - Controller1.Axis4.position()* 0.7; // may change multiplier
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          left_motors.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          right_motors.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        left_motors.setVelocity(drivetrainLeftSideSpeed, percent);
        left_motors.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        right_motors.setVelocity(drivetrainRightSideSpeed, percent);
        right_motors.spin(forward);
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
}


//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.


  thwacker.setVelocity(60, percent);

  // Run the pre-autonomous function.
  autonomous();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
