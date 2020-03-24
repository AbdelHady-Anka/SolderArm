#include <Arduino.h>
#include <AccelStepper.h>
#define motorInterfaceType 1

class Motor
{
public:
    Motor(uint8_t step_pin, uint8_t dir_pin, long high_band, long low_band, long init_location, float speed);
    Motor();
    ~Motor();
    void MoveTo(int location);

private:
    AccelStepper _stepper;
    float _speed;
    uint8_t _step_pin;
    uint8_t _dir_pin;
    int _high_band;
    int _low_band;
};
