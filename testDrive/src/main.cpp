#pragma region VEXcode Generated Robot Configuration
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\14846                                            */
/*    Created:      Tue Sep 12 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// rightF               motor         12              
// rightBB              motor         2               
// rightTB              motor         4               
// leftF                motor         13              
// leftBB               motor         7               
// leftTB               motor         10              
// Controller1          controller                    
// frontIntake          motor         21              
// valve                digital_out   A               
// limitSwitch          limit         H               
// thwacker             motor         5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;
//vex::motor_group;
#include "vex_motorgroup.h"
//#ifndef   VEX_DRIVETRAIN_CLASS_H
#define   VEX_DRIVETRAIN_CLASS_H


void preAuton(){
  valve.set(false);
  rightF.setStopping(hold);
  rightBB.setStopping(hold);
  rightTB.setStopping(hold);

  leftF.setStopping(hold);
  leftTB.setStopping(hold);
  leftBB.setStopping(hold);
}
void settingRight(int x){
  rightF.setVelocity(x, percent);
  rightBB.setVelocity(x, percent);
  rightTB.setVelocity(x, percent);
}
void settingLeft(int x){
  leftF.setVelocity(x, percent);
  leftBB.setVelocity(x, percent);
  leftTB.setVelocity(x, percent);
}
void setAll(int x, int y){
  settingRight(x);
  settingLeft(y);
}
void driveF(double ta, int vr, int vl){
  setAll(vr, vl);
  rightF.spinFor(forward, ta, turns, false);
  rightBB.spinFor(forward, ta, turns, false);
  rightTB.spinFor(forward, ta, turns, false);

  leftF.spinFor(forward, ta, turns, false);
  leftBB.spinFor(forward, ta, turns, false);
  leftTB.spinFor(forward, ta, turns, true);
  wait(0.01, seconds);
}
void driveB(double ta, int vr, int vl){
  setAll(vr, vl);
  rightF.spinFor(reverse, ta, turns, false);
  rightBB.spinFor(reverse, ta, turns, false);
  rightTB.spinFor(reverse, ta, turns, false);

  leftF.spinFor(reverse, ta, turns, false);
  leftBB.spinFor(reverse, ta, turns, false);
  leftTB.spinFor(reverse, ta, turns, true);
  wait(0.01, seconds);
}
void driveL(double ta, int vr, int vl){
  setAll(vr, vl);
  rightF.spinFor(forward, ta, turns, false);
  rightBB.spinFor(forward, ta, turns, false);
  rightTB.spinFor(forward, ta, turns, false);

  leftF.spinFor(reverse, ta, turns, false);
  leftBB.spinFor(reverse, ta, turns, false);
  leftTB.spinFor(reverse, ta, turns, true);
  wait(0.01, seconds);
}
void driveR(double ta, int vr, int vl){
  setAll(vr, vl);
  rightF.spinFor(reverse, ta, turns, false);
  rightBB.spinFor(reverse, ta, turns, false);
  rightTB.spinFor(reverse, ta, turns, false);

  leftF.spinFor(forward, ta, turns, false);
  leftBB.spinFor(forward, ta, turns, false);
  leftTB.spinFor(forward, ta, turns, true);
  wait(0.01, seconds);
}
void autonLeft(){
  driveF(10, 50, 50);
  /*
  valve.set(false);
  driveB(2, 50, 50);
  driveF(0.5, 50, 50);
  driveL(1, 50, 50);
  driveF(0.5, 50, 50);
  driveL(1, 50, 50);
  driveF(0.5, 50, 50);
  driveR(1, 50, 50);
  driveB(2, 50, 50);
  driveF(1, 50, 50);
  driveL(0.5, 50, 50);
  driveB(3, 50, 50);
  driveL(0.5, 50, 50);
  valve.set(true);
  driveB(0.3, 50, 50);
  driveR(0.5, 50, 50);
  valve.set(false);
  driveB(2, 50, 50);
  */
}
void solonoid(){
  if(valve.value() == 1){
    valve.set(false);
  } else if(valve.value() == 0) {
    valve.set(true);
  }
}
void unAuton(){
  rightF.setStopping(coast);
  rightBB.setStopping(coast);
  rightTB.setStopping(coast);

  leftF.setStopping(coast);
  leftTB.setStopping(coast);
  leftBB.setStopping(coast);
}
void driverControl(){
  //setting the velocity constant for the intake
  //preAuton();
  valve.set(false);
  int v = 100;
  bool toggle = true;
  frontIntake.setVelocity(v, percent);
  thwacker.setVelocity(20, percent);
  thwacker.setStopping(hold);
  thwacker.setMaxTorque(100, percent);

  
  //the while statement so that the code is continously driving the notebook
  while(true){
    //setting the velocity of the drivetrain to the position of the axis
    int fwd = Controller1.Axis3.position(percent);
    int trn = Controller1.Axis1.position(percent)*.5;
    
    rightF.setVelocity(fwd+trn, percent);
    rightBB.setVelocity(fwd+trn, percent);
    rightTB.setVelocity(fwd+trn, percent);
    //spinning the wheels to the posistion of the axis
    
    rightF.spin(forward);
    rightBB.spin(forward);
    rightTB.spin(forward);
    
    //same as what the right is doing, just on the left

    leftF.setVelocity((fwd-trn), percent);
    leftBB.setVelocity(fwd-trn, percent);
    leftTB.setVelocity(fwd-trn, percent);
    
    leftF.spin(forward);
    leftBB.spin(forward);
    leftTB.spin(forward);
    
    //spins the intake backward or forward for the triball
    if(Controller1.ButtonR1.pressing()){
      frontIntake.spin(forward);
    }else if(Controller1.ButtonR2.pressing()){
      frontIntake.spin(reverse);
    }else{
      frontIntake.stop();
    }
    //Pnumatics?
    Controller1.ButtonL2.pressed(solonoid);
   
    
    if(toggle){
        unAuton();
    }else{
      preAuton();
    }
    if(Controller1.ButtonA.pressing()){
      toggle = !(toggle); 
    }
    if(Controller1.ButtonL1.pressing()){
      thwacker.spin(forward);
    } else{
      thwacker.stop();
    }
    
  }
}
int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  //preAuton();
  /*
  competition Comp;
  Comp.autonomous(autonLeft);
  Comp.drivercontrol(driverControl);
  */
  driverControl();
  //autonLeft();
  /*
  robot.setDriveVelocity(50, percentUnits::pct);
  //robot.driveFor(directionType::fwd,36,distanceUnits::in);
  robot.turnFor(45,rotationUnits::deg);
  */
  //driverControl();
  //autonLeft();
  //autonRight();
  //driverControl();
  //robot.driveFor(34, inches, true);
}
