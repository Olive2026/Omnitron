
#include "vex.h"

class Autonomous {

  private:
    drivetrain robot;

    void runAutonomus1();
    void runAutonomus2();
    void runAutonomus3();

  public:
    //constructor
    Autonomous(drivetrain & robot);
    void execute(int selection);

};