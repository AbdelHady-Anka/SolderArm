#include <arm.h>

Arm::Arm(uint8_t stepPinX, uint8_t dirPinX, uint8_t stepPinY, uint8_t dirPinY, uint8_t stepPinZ, uint8_t dirPinZ, uint8_t stepPinTin, uint8_t dirPinTin)
{
    _motorX = Motor(stepPinX, dirPinX, 5475, 0, 0, (float)600);
    _motorY = Motor(stepPinY, dirPinY, 3625, 0, 0, (float)600);
    _motorZ = Motor(stepPinZ, dirPinZ, 975, 0, 0, (float)-400);
    _motorTin = Motor(stepPinTin, dirPinTin, 124, 0, 0, 400);
}

Arm::~Arm()
{
    _motorX.~Motor();
    _motorY.~Motor();
    _motorZ.~Motor();
}

void Arm::MoveTo(int x, int y)
{
    _motorX.MoveTo(x);
    _motorY.MoveTo(y);
}

void Arm::Solid(int z, int tinQuantity)
{
    _motorZ.MoveTo(z);
}
