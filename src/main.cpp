#include <motor.h>
#include <connection.h>
// Define stepper motors connections and motor interface type. Motor interface type must be set to 1 when using a driver:
#define stepPinY 4
#define dirPinY 5

#define stepPinX 8
#define dirPinX 9

#define stepPinZ 6
#define dirPinZ 7

#define start 10
// Create a new instance of the Motor class:

Connection connection = Connection();

void setup()
{
    pinMode(start, INPUT_PULLUP);
    Serial.begin(9600);
}
void loop()
{
    if(!connection.Ready()){
        connection.Connect();
    }


    if (Serial.readString().equals("on"))
    {
        Serial.write("ready");
        boolean val = digitalRead(start);
        if (!val)
        {
            // motorX.MoveTo(5475);
            // delay(1000);
            // motorX.MoveTo(0);
            // delay(3000);

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
}