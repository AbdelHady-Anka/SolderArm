#include <Arduino.h>
#include <AccelStepper.h>
#define motorInterfaceType 1

class Motor
{
public:
    Motor(uint8_t step_pin, uint8_t dir_pin, long high_band, long low_band, long init_location, float speed);
    void move_to(int location);
    void init();

private:
    AccelStepper stepper;
    float speed;
    uint8_t step_pin;
    uint8_t dir_pin;
    int high_band;
    int low_band;
    int currnet_location;
    String axsis_name;
};

Motor::Motor(uint8_t step_pin, uint8_t dir_pin, long high_band, long low_band, long init_location, float speed)
{
    this->step_pin = step_pin;
    this->high_band = high_band;
    this->low_band = low_band;
    this->axsis_name = axsis_name;
    this->speed = speed;
    this->stepper = AccelStepper(motorInterfaceType, step_pin, dir_pin);
    this->stepper.setCurrentPosition(init_location);
    // Set the maximum speed in steps per second:
    this->stepper.setMaxSpeed(1000);
}

void Motor::move_to(int location)
{
    // Serial.println("in move to");
    if (location <= high_band && location >= low_band)
    {
        // Serial.println("in the if");
        // Serial.println("current location: ");
        // Serial.println(stepper.currentPosition());
        float shift = location - stepper.currentPosition();
        int direction = shift >= 0 ? +1 : -1;

        // Serial.println("direction: ");
        // Serial.println(direction);
        while (stepper.currentPosition() != location)
        {
            stepper.setSpeed(direction * speed);
            stepper.runSpeed();
        }
        // Serial.println("current location: ");
        // Serial.println(stepper.currentPosition());
        // stepper.setCurrentPosition(location);

        delay(1000);
    }
}