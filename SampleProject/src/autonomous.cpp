#include "autonomous.h"

Autonomous::Autonomous(drivetrain train):robot(train) {}

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

void Autonomous::runAutonomus1() {

}


void Autonomous::runAutonomus2() {

}

void Autonomous::runAutonomus3() {

}