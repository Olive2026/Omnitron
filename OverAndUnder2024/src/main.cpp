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


// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// may add another controller
//controller Controller1 = controller(primary);

motor_group left_motors(leftF, leftTB, leftBB);
motor_group right_motors(rightF, rightTB, rightBB);

double wheel_diameter = 4;
double wheel_circumference = 2 * (wheel_diameter/2) * 3.14; // 2 * r * PI
double wheel_distance = 12; // 14 inches
double wheel_base = 12.5;
double gearRat = 4/7;

drivetrain robot(left_motors, right_motors, wheel_circumference, wheel_distance, wheel_base, distanceUnits::in, gearRat);
//night
void pre_auton(void) {
  left_motors.setStopping(hold);
  right_motors.setStopping(hold);
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




// void solonoid(){
//   if(valve.value() == 1){
//     valve.set(false);
//   } else if(valve.value() == 0) {
//     valve.set(true);
//   }
// }
void solonoid(){
  if(valve.value() == 1){
    valve.set(false);
  } else if(valve.value() == 0) {
    valve.set(true);
  }
}
void skillAuton(void)
{
  robot.setDriveVelocity(50, percent);
  
  thwacker.setVelocity(70, percent);

//Testing
  //robot.driveFor(forward, 1000, inches);

//BEFORE RUN, SCALING MUST BE DONE- I may come in if possible and do that
  robot.driveFor(forward, 36, inches);
  robot.turnFor(30, degrees);
  robot.driveFor(forward, 7, inches);
  robot.driveFor(forward, -7, inches);
  robot.driveFor(forward, 7, inches);
  robot.driveFor(forward, -9, inches);
  robot.turnFor(60, degrees);
  robot.driveFor(forward, 12, inches);
  robot.turnFor(60, degrees);
  robot.driveFor(forward, 7, inches);
  robot.driveFor(forward, -7, inches);
  robot.driveFor(forward, 7, inches);
  robot.driveFor(forward, -7, inches);
  robot.driveFor(forward, 7, inches);
  robot.driveFor(forward, -11, inches);

  //TODO: wait for 35 secs
  wait(30, sec); // msec is also possible for milliseconds precision

  //stop catapult, toggle off
  runCata();//slowdownCata();
  //goforward
  // robot.driveFor(directionType::fwd, 25, distanceUnits::in);
  // //add thwacker lower, 400 degrees??
  // robot.driveFor(directionType::fwd, 35, distanceUnits::in);
  // robot.turnFor(145, rotationUnits::deg);

/*
Thwacker section- 30 seconds, running

--------------------------------------------------------

 go forward 3 ft
 turn 30ish, go forward, back up, forward, back up
 turn 60, and go forward 1ft
 turn 30- trying to go forward
 back, forward, back, forward
*/
//robot.driveFor(forward, 1000, , 70, percent);
  

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
      int drivetrainRightSideSpeed = Controller1.Axis2.position() - Controller1.Axis4.position()* 0.5; // may change multiplier
      
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

  //Sets up the if statement for testing
  //int val = 2;

  thwacker.setVelocity(60, percent);
  //competition Comp;
  //Comp.autonomous(skillAuton);
  //Comp.drivercontrol(usercontrol);
  
  //skillAuton();

  // Run the pre-autonomous function.
  int val  = 2;
  if(val==1)
  {
    autonomous();
  }
  else if(val==2)
  {
    skillAuton();
  }
  else if(val==3)
  {
    usercontrol();
  }
  
  

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
