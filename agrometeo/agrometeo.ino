
//===Settings============
#define DS18B20 9
//---RS485---------------
#define RS485_RX 3 
#define RS485_TX 4
#define MODE_RS485 7
//---humidity------------
#define SOIL1 A0
#define SOIL2 A1
#define SOIL3 A2
//---modem---------------
#define SLEEP 3
#define BOOT 6

//===Limraries===========
#include <SoftwareSerial.h>
SoftwareSerial rs485(RS485_RX, RS485_TX); //(RX,TX)

#include <microDS18B20.h>
uint8_t s1_addr[] = {0x28, 0xFF, 0xCD, 0x59, 0x51, 0x17, 0x4, 0xFE};
uint8_t s2_addr[] = {0x28, 0xFF, 0x36, 0x94, 0x65, 0x15, 0x2, 0x80};
uint8_t s3_addr[] = {0x28, 0xFF, 0x36, 0x94, 0x65, 0x15, 0x2, 0x80};
MicroDS18B20<DS18B20, s1_addr> ds1;
MicroDS18B20<DS18B20, s2_addr> ds2;
MicroDS18B20<DS18B20, s3_addr> ds3;

#include <GyverPower.h>

void setup() {
  delay(2000)
  //Init
  Serial.begin(9600);
  rs485.begin(9600);
  Serial.println("AT+CLIP=1") //Turn AOH on
  delay(100)
}

void loop() {
  ds1.requestTemp();
  ds2.requestTemp();
  ds3.requestTemp(); 
}
