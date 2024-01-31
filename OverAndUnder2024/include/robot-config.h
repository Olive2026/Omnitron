using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor leftF;
extern motor leftTB;
extern motor leftBB;
extern motor rightF;
extern motor rightTB;
extern motor rightBB;
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