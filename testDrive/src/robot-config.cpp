#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor rightF = motor(PORT12, ratio6_1, true);
motor rightBB = motor(PORT2, ratio6_1, true);
motor rightTB = motor(PORT4, ratio6_1, false);
motor leftF = motor(PORT13, ratio6_1, false);
motor leftBB = motor(PORT7, ratio6_1, false);
motor leftTB = motor(PORT10, ratio6_1, true);
controller Controller1 = controller(primary);
motor frontIntake = motor(PORT21, ratio6_1, true);
digital_out valve = digital_out(Brain.ThreeWirePort.A);
limit limitSwitch = limit(Brain.ThreeWirePort.H);
motor thwacker = motor(PORT5, ratio18_1, true);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller1LeftShoulderControlMotorsStopped = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // check the ButtonL1/ButtonL2 status to control rightF
      if (Controller1.ButtonL1.pressing()) {
        rightF.spin(forward);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (Controller1.ButtonL2.pressing()) {
        rightF.spin(reverse);
        Controller1LeftShoulderControlMotorsStopped = false;
      } else if (!Controller1LeftShoulderControlMotorsStopped) {
        rightF.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller1LeftShoulderControlMotorsStopped = true;
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}