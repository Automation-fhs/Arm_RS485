#include <Arduino.h>
#include <Arm-RS485.h>
#include <RS485-Code.h>

#define TX 3
#define RX 2
#define RW 4
#define addr 1

Arm_RS485 rs485(RX, TX, RW, addr, 115200);

int receive[5];

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  rs485.begin();
  pinMode(RW, OUTPUT);
  digitalWrite(RW, LOW);
}

void loop()
{
  switch (rs485.message_read(receive))
  {
  case 0xFF:
  {
    Serial.println("Message received!");
    message_handle(receive);
  }
  break;
  case 0x10:
    Serial.println("Checksum Error");
    break;
  case 0x50:
    Serial.println("Message Format Error");
    break;
  case 0x51:
    Serial.println("Message Checksum Error");
    break;
  case 0xF0:
    Serial.println("Not from center");
    break;
  case 0xF1:
    Serial.println("Not to this arm");
    break;
  }
}

void message_handle(int msg[5])
{
  switch (msg[2])
  {
  case 1:
    switch (msg[3])
    {
    case 0:
    {
    }
    break;
    case 1:
    {
    }
    break;
    case 2:
    {
    }
    break;
    case 3:
    {
    }
    break;
    }
    rs485.message_write(receive[2], receive[3]);
    break;
  case 2:
    switch (msg[3])
    {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    }
    break;
  case 10:
  {
  };
  break;
  case 20:
  {
  };
  break;
  case 11:
  {
  };
  break;
  case 21:
  {
  };
  break;
  }
}
