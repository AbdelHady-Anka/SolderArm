
#include<motor.h>
Motor::Motor(uint8_t step_pin, uint8_t dir_pin, long high_band, long low_band, long init_location, float speed)
{
    _step_pin = step_pin;
    _high_band = high_band;
    _low_band = low_band;
    _speed = speed;
    _stepper = AccelStepper(motorInterfaceType, step_pin, dir_pin);
    _stepper.setCurrentPosition(init_location);
    // Set the maximum speed in steps per second:
    _stepper.setMaxSpeed(1000);
}

Motor::Motor(){
    _low_band = _high_band = _speed = 0;
    _stepper = AccelStepper();
    _stepper.setMaxSpeed(0);
}

Motor::~Motor(){
    _stepper.~AccelStepper();
}

void Motor::MoveTo(int location)
{
    // Serial.println("in move to");
    if (location <= _high_band && location >= _low_band)
    {
        // Serial.println("in the if");
        // Serial.println("current location: ");
        // Serial.println(stepper.currentPosition());
        float shift = location - _stepper.currentPosition();
        int direction = shift >= 0 ? +1 : -1;

        // Serial.println("direction: ");
        // Serial.println(direction);
        while (_stepper.currentPosition() != location)
        {
            _stepper.setSpeed(direction * _speed);
            _stepper.runSpeed();
        }
        // Serial.println("current location: ");
        // Serial.println(stepper.currentPosition());
        // stepper.setCurrentPosition(location);

        delay(1000);
    }
}