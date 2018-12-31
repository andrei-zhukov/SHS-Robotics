#include "robot-config.h"

/* Define additional digital outputs.
 * Follow this format:
 * 
 * vex::digital_out <var name> = vex::digital_out( PORT );
 * 
 * Where PORT is a Brain.ThreeWirePort.[letter] = https://www.robotmesh.com/docs/vexv5-cpp/html/classvex_1_1triport.html
 * Ie Brain.ThreeWirePort.A
 */


/* Define global variables because why not */
bool spinnerOn = false;

/* Messages */
const char* reverseMessageOn = "Motors are REVERSED";
const char* reverseMessageOff = "Motors are NORMAL";
const char* rumbleCode = ".-";

/**
 * Reversing of motors. If reversed is true then
 * directions.fwd and directions.rev will be the opposite of
 * what they're intended to do (Ie directions.fwd = vex::directionType::rev)
 *
 * Upon changing the state of reversed, the reversedTimeout will be incremented
 * to REVERSE_TIMEOUT and decrease to 0 each iteration of the loop.
 */
bool reversed = false; // Are all motors reversed?
const int MAX_REVERSE_TIMEOUT = 7; // Max iterations before state can be changed
int reversedTimeout = 0; // Min timeout between motor reversals

/**
 * Stores all direction types. Use this instead of 
 * vex::directionType if you want the motor to be 
 * reversed by the reversed variable 
 *
 * Ie. Do directions.fwd instead of vex::directionType::fwd
 */
struct directionsStruct {
    vex::directionType fwd;
    vex::directionType rev;

 Motor.spin(directionType::fwd,50,velocityUnits} directions;

void arcadedrive {
    
    const leftpower = Controller1.Axis1.position(percentUnits::pct)+Controller1.Axis2.position(percentUnits::pct);
    const rightpower = Controller1.Axis1.position(percentUnits::pct)-Controller1.Axis2.position(percentUnits::pct);
        Controller1.Screen.print(leftpower);
        Controller1.Screen.print(rightpower);
            Motor04dr.spin(dir, leftpower, vex::velocityUnits::pct);
            Motor16dr.spin(dir, leftpower, vex::velocityUnits::pct);
            Motor02dr.spin(dir, leftpower, vex::velocityUnits::pct);
            Motor11dl.spin(dir, rightpower, vex::velocityUnits::pct);
            Motor03dl.spin(dir, rightpower, vex::velocityUnits::pct);
            Motor01dl.spin(dir, rightpower, vex::velocityUnits::pct);
}

/**
 * Deal with the spinner thing at the front 
 * of the robot. Pls refactor.
 */
void Spinner() {
    if (Controller1.ButtonY.pressing()) {
        spinnerOn = !spinnerOn;
    }
    if (spinnerOn) {
        Motor07.spin(vex::directionType::fwd, 100, vex::velocityUnits::pct);
    } else {
        Motor07.stop();
    }
}

int main() {
    while(true) {
        /**
         * Checking of motor reversal code. If the B button
         * is pressed all motors will be toggled to reverse
         * direction
         */
        reversedTimeout = reversedTimeout < 0 ? 0 : reversedTimeout - 1;
        if(Controller1.ButtonB.pressing() && reversedTimeout <= 0) {
            reversed = !reversed;
            reversedTimeout = MAX_REVERSE_TIMEOUT;
            
            /* Display the current reversal state */
            Controller1.Screen.clearScreen();
            Controller1.Screen.print(reversed ? reverseMessageOn : reverseMessageOff);
            Controller1.rumble(rumbleCode);
        }
        
        directions.fwd = !reversed ? vex::directionType::fwd : vex::directionType::rev;
        directions.rev = !reversed ? vex::directionType::rev : vex::directionType::fwd;

        // Spinny thing code
        doSpinner();
        // Drive code
        doarcadedrive();
}



void moveStraight (int power=100, bool fwd=true) {
    vex::directionType dir = fwd ? directions.fwd : directions.rev;
    
    Motor01.spin(dir, power, vex::velocityUnits::pct);
    Motor02.spin(dir, power, vex::velocityUnits::pct);
    Motor05.spin(dir, power, vex::velocityUnits::pct);
    Motor03.spin(dir, power, vex::velocityUnits::pct);
    Motor04.spin(dir, power, vex::velocityUnits::pct);
    Motor16.spin(dir, power, vex::velocityUnits::pct);
}

