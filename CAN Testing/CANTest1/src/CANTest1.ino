#include <FlexCAN.h>
//#include <kinetis_flexcan.h>
#define led 13
// create CAN object
//FlexCAN CANTransmitter(50000);
static CAN_message_t msg;
static CAN_message_t inMsg;

int rx2 = 0;
int rx3 = 0;

void setup() {

  Can0.begin(500000);

  int idnum = 1;

  msg.id = 0x222;
  msg.len = 1;
  msg.ext = 0;
  msg.buf[0] = 0;
  msg.buf[1] = 0;
  msg.buf[2] = 0;
  msg.buf[3] = 0;
  msg.buf[4] = 0;
  msg.buf[5] = 0;
  msg.buf[6] = 0;
  msg.buf[7] = 0;

  delay(100);
  Serial.print("CAN ");
  Serial.print(idnum);
  Serial.print(" Init\n");
  
}

void loop() {

  //Serial.println("Running");
  delay(1000);

  msg.buf[0] = 3;
  Can0.write(msg);

  Can0.read(inMsg);

  if (inMsg.buf[0] == 3)
  {
    rx2 = 1;
  }

//  if (inMsg.buf[0] == 3)
//  {
//    rx3 = 1;
//  }

  if(rx2 == 1)
  {
    digitalWrite(led, HIGH);
  }
  delay(1000);

  
  Serial.print("CAN Message: ");
  Serial.print(inMsg.buf[0]);
  Serial.print("\n");

  Serial.print("CAN Message: ");
  Serial.print(rx2);
  Serial.print("\n");


//  if (rx2 == 1 && rx3 == 1)
//  {
//    digitalWrite(led, HIGH); 
//  }

}





