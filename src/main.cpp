
#include <motor.h>
// Define stepper motors connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define stepPinY 4
#define dirPinY 5

#define stepPinX 8
#define dirPinX 9

#define stepPinZ 6
#define dirPinZ 7

#define start 10
// Create a new instance of the Motor class:
Motor motorY = Motor(stepPinY, dirPinY, 3625, 0, 0, 600);
Motor motorX = Motor(stepPinX, dirPinX, 5475, 0, 0, 600);
Motor motorZ = Motor(stepPinZ, dirPinZ, 975, 0, 0, -400);
void setup()
{
    pinMode(start, INPUT_PULLUP);
    Serial.begin(9600);
}
void loop()
{
    boolean val = digitalRead(start);
    if (!val)
    {
        motorX.move_to(5475);
        delay(1000);
        motorX.move_to(0);
        delay(3000);

        // motorY.move_to(3625);
        // delay(1000);
        // motorY.move_to(0);

        // delay(3000);

        // motorZ.move_to(975);
        // delay(1000);
        // motorZ.move_to(0);

        val = true;
    }
}