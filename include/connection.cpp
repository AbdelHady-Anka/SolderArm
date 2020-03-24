#include <connection.h>

bool Connection::Ready()
{
    return _connected;
}
void Connection::Connect()
{
    while (!Serial.readString().equals("on"))
    {
        Serial.write("ready");
        _connected = true;
    }
}