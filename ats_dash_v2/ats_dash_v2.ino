#include <SPI.h>
#include <mcp2515.h>
#include "cancode.h"




MCP2515 mcp2515(10);


unsigned long prev_tempo_1s;
#define PACKET_SYNC 0xFF
#define PACKET_VER  2

int serial_byte;

void setup() {
  Serial.begin(115200);

    mcp2515.reset();
  mcp2515.setBitrate(CAN_125KBPS,MCP_8MHZ);
  mcp2515.setNormalMode();

carregaCAN();

}

void loop() {
//send can packs
mcp2515.sendMessage(&canMsg1);  
mcp2515.sendMessage(&canMsg2);
mcp2515.sendMessage(&canMsg3);
mcp2515.sendMessage(&canMsg4);
mcp2515.sendMessage(&canMsg5);
mcp2515.sendMessage(&canMsg6);

  if (Serial.available() < 42)
   return;
  
   serial_byte = Serial.read();     
   if (serial_byte != PACKET_SYNC)
   return;

   serial_byte = Serial.read();
   if (serial_byte != PACKET_VER)
   return;
  
int speed_kph =                Serial.read();
int speed_decimal =            Serial.read();
int lsb_rpm =                  Serial.read();
int msb_rpm =                  Serial.read();
int air_pressure =             Serial.read();
int fuel =                     Serial.read();
int oil_pressure =             Serial.read();
int water_temperature =        Serial.read();
int batterie_voltage =         Serial.read();
int average_cosumption =       Serial.read();
int adblue =                   Serial.read();
int engine_gear =              Serial.read();
int effective_throttle =       Serial.read();
int effective_brake=           Serial.read();
int effective_clutch=          Serial.read();
int input_throttle=            Serial.read();
int input_brake=               Serial.read();
int input_clutch=              Serial.read();
int fuel_liters =              Serial.read();
int unit_fuel =                Serial.read();
int decimal_fuel=              Serial.read();
int odometer_1 =               Serial.read();
int odometer_2 =               Serial.read();
int odometer_3 =               Serial.read();
int odometer_4 =               Serial.read();
int decimal_odometer =         Serial.read();
int game_time_1 =              Serial.read();
int game_time_2 =              Serial.read();
int game_time_3 =              Serial.read();
int game_time_4 =              Serial.read();
int next_rest_stop_1 =         Serial.read();
int next_rest_stop_2 =         Serial.read();
int next_rest_stop_3 =         Serial.read();
int next_rest_stop_4 =         Serial.read();
int cruise_control =           Serial.read();
int retarder_steps =           Serial.read();
int oil_temperature =          Serial.read();
int OCTET_0 =                  Serial.read();
int OCTET_1 =                  Serial.read();
int OCTET_2 =                  Serial.read();

int left_blinker =             ((OCTET_0 >> 5) & 0x01);
int right_blinker =            ((OCTET_0 >> 4) & 0x01);
int low_beam =                 ((OCTET_0 >> 3) & 0x01);
int high_beam =                ((OCTET_0 >> 2) & 0x01);
int park_brake =               ((OCTET_0 >> 1) & 0x01);
int temperature_warning =      ((OCTET_1 >> 0) & 0x01);
int trailer_connected =        ((OCTET_2 >> 6) & 0x01);
int retarder =                 ((OCTET_2 >> 4) & 0x01);
int electric_enabled =         ((OCTET_2 >> 1) & 0x01);
int engine_enabled =           ((OCTET_2 >> 0) & 0x01);

int lsb;
int msb;
int lsb1;
int msb1;
int split_low;
int retarder_state;

int rpm = msb_rpm;
rpm = rpm <<8;
rpm = rpm + lsb_rpm;

rpm =                             rpm*0.031286;    
speed_kph =                       speed_kph*0.390909;
speed_decimal =                   map(speed_decimal, 0, 5, 0, 255);
water_temperature =               map(water_temperature, 50, 101,  101, 131);
air_pressure =                    map(air_pressure, 0, 140, 0, 150);
fuel =                            map(fuel, 0, 100, 0, 128);
oil_pressure =                    map(oil_pressure, 0, 86, 0, 175);
int turbo =                       map(effective_throttle, 0, 100, 0, 75);
int instant_consuption_lh =       map(effective_throttle, 0, 100, 0, 96);
int instant_consuption_lk =       map(effective_throttle, 0, 100, 64254, 427);

long odometer = odometer_4;
odometer = odometer << 8;
odometer = odometer + odometer_3;
odometer = odometer << 8;
odometer = odometer + odometer_2;
odometer = odometer << 8;
odometer = odometer + odometer_1;
odometer = odometer*200;

//ajusta can
//rpm
canMsg3.data[0] = (rpm & 0xFF);
//speed
 canMsg3.data[2] = (speed_kph & 0xFF);
 canMsg3.data[3] = (speed_decimal & 0xFF);
//water temp
canMsg1.data[1] = (water_temperature  &0xFF);
//blinker + headlight
canMsg4.data[4] = (((left_blinker*2)+(right_blinker*4)+(high_beam*32)+(low_beam*64))&0xFF);
//park brake
 canMsg5.data[0] = (((park_brake*4)+(temperature_warning*128))&0xFF);
//ignition
canMsg1.data[0] = ((electric_enabled*142)&0xFF);
//fuel

canMsg6.data[3] = (fuel &0xFF);







}
