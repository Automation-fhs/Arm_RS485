#include "Arm-RS485.h"
#include "Arduino.h"

Arm_RS485::Arm_RS485(uint8_t RX, uint8_t TX, uint8_t RW, long speed) : _myRS485(RX, TX)
{
    this->_myRS485.begin(speed);
}

void Arm_RS485::message_read()
{
    if (this->_myRS485.available())
    {
        String received = "";
        bool msgEnd = false;
        while (this->_myRS485.available())
        {
            char temp;
            temp = (char)this->_myRS485.read();
            if (msgEnd == true)
            {
                if (temp == 't')
                    break;
            }
            if (temp == '/')
                msgEnd = true;
            else
                received += temp;
        }
        char r_to_c[received.length() + 1];
        strcpy(r_to_c, received.c_str());
        this->message_handle(r_to_c);
    }
}

void Arm_RS485::message_handle(char msg[])
{
    int arr[5];
    // Serial.println(str);
    if (this->msg_to_array(arr, msg))
    {
    }
    else
    {
    }
}

bool Arm_RS485::msg_to_array(int arr[5], char msg[])
{
    memset(arr, 0, sizeof(arr));
    int count = 0;
    for (unsigned int i = 0; i < sizeof(msg); i++)
    {
        if (msg[i] == ':')
            count += 1;
        else
        {
            switch (count)
            {
            case 0:
            {
                arr[0] = arr[0] * 10 + (int)msg[i] - (int)'0';
            }
            break;
            case 1:
            {
                arr[1] = arr[1] * 10 + (int)msg[i] - (int)'0';
            }
            break;
            case 2:
            {
                arr[2] = arr[2] * 10 + (int)msg[i] - (int)'0';
            }
            break;
            case 3:
            {
                arr[3] = arr[3] * 10 + (int)msg[i] - (int)'0';
            }
            break;
            case 4:
            {
                arr[4] = arr[4] * 10 + (int)msg[i] - (int)'0';
            }
            break;
            }
        }
    }
    if (cs_check(arr) && count == 4)
    {
        digitalWrite(this->_rw_Pin, HIGH);
        this->_myRS485.write("Ok!");
        digitalWrite(this->_rw_Pin, LOW);
        return true;
    }
    else
    {
        return false;
    }
}

void Arm_RS485::array_to_msg(int arr[5], char msg[])
{
    msg = "Hello World!";
};

bool Arm_RS485::cs_check(int arr[5])
{
    return true;
}