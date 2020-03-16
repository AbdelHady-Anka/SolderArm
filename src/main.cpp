
#include <motor.h>
// Define stepper motor connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define dirPin 7
#define stepPin 6
#define motorInterfaceType 1
#define start 10
// Create a new instance of the Motor class:
Motor motor = Motor(stepPin, dirPin, 5500, 0, 0);
void setup()
{
    pinMode(start, INPUT_PULLUP);
}
void loop()
{
    boolean val = digitalRead(start);
    if (!val)
    {
        motor.move_to(1000);
        delay(3000);
        motor.move_to(500);
        val = true;
    }
}