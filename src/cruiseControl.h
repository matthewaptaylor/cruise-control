// The type 'string' is defined as 'char*' in Esterel, hence passing a string by referenc  is 'char**'
// Aviod naming a function 'recv'
#include <stdbool.h>

#define SPEED_MIN 30.0  // Minimum cruise control speed, in km/h
#define SPEED_MAX 150.0 // Maximum cruise control speed, in km/h
#define SPEED_INC 2.5   // Increment to change speed by when QuickAccel or QuickDecel is pressed, km/h
#define PEDALS_MIN 3.0  // Minimum throttle and brake pedal position to trigger a change, in percent

// Cruise control states
#define OFF 1
#define ON 2
#define STDBY 3
#define DISABLE 4
