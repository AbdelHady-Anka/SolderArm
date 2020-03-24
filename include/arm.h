#include <motor.h>

class Arm
{
private:
    /* data */
    Motor _motorX;
    Motor _motorY;
    Motor _motorZ;
    Motor _motorTin;
public:
    Arm(uint8_t stepPinX, uint8_t dirPinX, uint8_t stepPinY, uint8_t dirPinY,uint8_t stepPinZ, uint8_t dirPinZ, uint8_t stepPinTin, uint8_t dirPinTin);
    ~Arm();
    void MoveTo(int x, int y);
    void Solid(int z, int tinQuantity);
};


