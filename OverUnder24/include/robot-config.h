using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftMotor1;
extern motor leftMotor2;
extern motor leftMotor3;
extern motor rightMotor1;
extern motor rightMotor2;
extern motor rightMotor3;
extern motor thwacker;
extern digital_out valve;
extern controller Controller1;
//extern valve 
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit(void);