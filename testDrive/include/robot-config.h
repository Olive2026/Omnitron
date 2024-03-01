using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor rightF;
extern motor rightBB;
extern motor rightTB;
extern motor leftF;
extern motor leftBB;
extern motor leftTB;
extern controller Controller1;
extern motor frontIntake;
extern digital_out valve;
extern limit limitSwitch;
extern motor thwacker;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );