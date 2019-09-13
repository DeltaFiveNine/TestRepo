#include <FlexCAN.h>
//#include <kinetis_flexcan.h>
#define led 13
// create CAN object
//FlexCAN CANTransmitter(50000);
static CAN_message_t msg;
static CAN_message_t inMsg;

int rx1 = 0;
int rx2 = 0;


void setup() {

  Can0.begin(500000);

  int idnum = 3;

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
  
  msg.buf[0] = '3';
  Can0.write(msg);

  Can0.read(inMsg);
  int message = inMsg.buf[0];

  if (inMsg.buf[0] == '1')
  {
    rx1 = 1;
  }

  if (inMsg.buf[0] == '3')
  {
    rx2 = 1;
  }

  if (rx1 == 1 && rx2 == 1)
  {
    digitalWrite(led, HIGH); 
  }

}





