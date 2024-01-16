#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;



// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftMotor1           motor         1               
// leftMotor2           motor         2               
// leftMotor3           motor         3               
// rightMotor1          motor         4               
// rightMotor2          motor         5               
// rightMotor3          motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----
// Add more


// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftMotor1 = motor(PORT1, ratio6_1, false);
motor leftMotor2 = motor(PORT2, ratio6_1, false);
motor leftMotor3 = motor(PORT3, ratio6_1, false);
motor rightMotor1 = motor(PORT4, ratio6_1, false);
motor rightMotor2 = motor(PORT5, ratio6_1, false);
motor rightMotor3 = motor(PORT6, ratio6_1, false);
motor catapult = motor(PORT7, ratio36_1, false);

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}