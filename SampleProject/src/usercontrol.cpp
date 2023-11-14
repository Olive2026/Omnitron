#include "vex.h"
#include "usercontrol.h"

void runControl() {
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

void onIntakeReverseClicked() {

}

void onIntakeForwardClicked() {

}

void onIntakeStopClicked() {

}

void onCatapultClicked() {
  
}