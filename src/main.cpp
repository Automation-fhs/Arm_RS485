#include <Arduino.h>
#include <Arm-RS485.h>

#define TX 3
#define RX 2
#define RW 4

Arm_RS485 arm(RX, TX, RW, 115200);

// put function declarations here:
void message_handle(String msg);
bool msg_to_array(int arr[5], String msg);
String array_to_msg(int arr[4]);
bool cs_check(int arr[5]);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(RW, OUTPUT);
  digitalWrite(RW, LOW);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:

void message_handle(String msg)
{
  int arr[5];
  // Serial.println(str);
  if (msg_to_array(arr, msg))
  {
  }
  else
  {
    Serial.println("Error");
  }
}

bool msg_to_array(int arr[5], String msg)
{
  memset(arr, 0, sizeof(arr));
  int count = 0;
  for (unsigned int i = 0; i < msg.length(); i++)
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
    digitalWrite(RW, HIGH);
    myRS485.write("Ok!");
    delay(5);
    digitalWrite(RW, LOW);
    return true;
  }
  else
  {
    return false;
  }
}

String array_to_msg(int arr[4])
{
  String result = "Hello World!";
  return result;
};

bool cs_check(int arr[5])
{
  return true;
}