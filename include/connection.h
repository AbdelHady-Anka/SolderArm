#include<Arduino.h>
class Connection
{
private:
    /* data */
    bool _connected;
public:
    bool Ready();
    void Connect();
};