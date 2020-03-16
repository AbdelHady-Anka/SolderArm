#include <Arduino.h>
#include <AccelStepper.h>

class Motor
{
public:
    Motor(uint8_t step_pin, uint8_t dir_pin, long high_band, long low_band, long init_location);
    void move_to(int location);
    void init();

private:
    AccelStepper stepper;
    uint8_t step_pin;
    uint8_t dir_pin;
    int high_band;
    int low_band;
    int currnet_location;
    String axsis_name;
};

Motor::Motor(uint8_t step_pin, uint8_t dir_pin, long high_band, long low_band, long init_location)
{
    this->step_pin = step_pin;
    this->high_band = high_band;
    this->low_band = low_band;
    this->axsis_name = axsis_name;
    this->stepper = AccelStepper(1, step_pin, dir_pin);
    this->stepper.setCurrentPosition(init_location);
    // Set the maximum speed in steps per second:
    this->stepper.setMaxSpeed(1000);
}

void Motor::move_to(int location)
{
    if (location < high_band && location > low_band)
    {
        float shift = location - stepper.currentPosition();
        int direction = shift >= 0 ? +1 : -1;
        while (stepper.currentPosition() != abs(shift))
        {
            stepper.setSpeed(direction * 600);
            stepper.runSpeed();
        }
        delay(1000);
    }
}