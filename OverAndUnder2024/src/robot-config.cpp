#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;



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
// Add more


// A global instance of brain used for printing to the V5 Brain screen

// VEXcode device constructors
motor leftMotor1 = motor(PORT11, ratio6_1, false);
motor leftMotor2 = motor(PORT4, ratio6_1, false);
motor leftMotor3 = motor(PORT19, ratio6_1, true);
motor rightMotor1 = motor(PORT1, ratio6_1, true);
motor rightMotor2 = motor(PORT9, ratio6_1, true);
motor rightMotor3 = motor(PORT2, ratio6_1, false);
motor thwacker = motor(PORT10, ratio6_1, false);
digital_out valve = digital_out(Brain.ThreeWirePort.A);

controller Controller1 = controller(primary);
// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}