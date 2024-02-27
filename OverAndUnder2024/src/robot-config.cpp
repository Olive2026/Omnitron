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
brain Brain;

// VEXcode device constructors
<<<<<<< Updated upstream
motor leftF = motor(PORT11, ratio6_1, false);
motor leftTB = motor(PORT19, ratio6_1, true);
motor leftBB = motor(PORT4, ratio6_1, false); 
motor rightF = motor(PORT1, ratio6_1, true);
motor rightTB = motor(PORT9, ratio6_1, false);
motor rightBB = motor(PORT2, ratio6_1, true);
motor thwacker = motor(PORT10, ratio6_1, true);
=======
motor leftF = motor(PORT12, ratio6_1, false);
motor leftTB = motor(PORT10, ratio6_1, true);
motor leftBB = motor(PORT9, ratio6_1, false); 
motor rightF = motor(PORT13, ratio6_1, true);
motor rightTB = motor(PORT1, ratio6_1, false);
motor rightBB = motor(PORT2, ratio6_1, true);
motor thwacker = motor(PORT5, ratio6_1, true);
motor intake = motor(PORT4, ratio6_1, false);
>>>>>>> Stashed changes
digital_out valve = digital_out(Brain.ThreeWirePort.A);
//radio at 8
controller Controller1 = controller(primary);
// VEXcode generated functions


<<<<<<< Updated upstream

=======
>>>>>>> Stashed changes
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}