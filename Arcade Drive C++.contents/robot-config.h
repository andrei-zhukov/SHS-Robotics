using namespace vex;
vex::brain Brain;
vex::motor Motor11dl (vex::PORT1, vex::gearSetting::ratio18_1,true);
vex::motor Motor01dl (vex::PORT2, vex::gearSetting::ratio18_1,true);
vex::motor Motor03dl (vex::PORT3, vex::gearSetting::ratio18_1,false);
vex::motor Motor04dr (vex::PORT11, vex::gearSetting::ratio18_1,true);
vex::motor Motor16dr (vex::PORT12, vex::gearSetting::ratio18_1,false);
vex::motor Motor02dr (vex::PORT13, vex::gearSetting::ratio18_1,false);
vex::motor Motor05sp (vex::PORT14, vex::gearSetting::ratio18_1,false);
vex::controller Controller1;