#include <SoftwareSerial.h>

class Arm_RS485
{
public:
    Arm_RS485(uint8_t RX, uint8_t TX, uint8_t RW, long speed);
    void message_read();
    bool message_write();
    void message_handle(char msg[]);
    bool msg_to_array(int arr[5], String msg);
    String array_to_msg(int arr[4]);
    bool cs_check(int arr[5]);

private:
    uint8_t _rw_Pin;
    SoftwareSerial _myRS485;
};