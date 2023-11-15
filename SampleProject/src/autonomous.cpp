#include "autonomous.h"

Autonomous::Autonomous(drivetrain & train):robot(train) {}

void Autonomous::execute(int selection) {
  switch(selection) {
    case 0:
      // execute autonomous 1
      runAutonomus1();
      break;
    case 1:
      // execute autonomous 1
      runAutonomus2();
      break;
    case 2:
      // execute autonomous 1
      runAutonomus3();
      break;
  }
}

// autonomous code for our robot on aliance side
void Autonomous::runAutonomus1() {
 robot.driveFor(forward, 11, distanceUnits::in);
 robot.turnFor(right, 90, degrees);
 // I am another peter
 robot.driveFor(forward, 2, distanceUnits::in);
 robot.turnFor(left, 45, degrees);
 //test change again
}


void Autonomous::runAutonomus2() {

}

void Autonomous::runAutonomus3() {

}