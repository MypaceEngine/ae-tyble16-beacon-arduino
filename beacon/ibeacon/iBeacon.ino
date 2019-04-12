// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// Import libraries (EddystoneBeacon depends on SPI)
#include <BLEPeripheral.h>
#include <iBeacon.h>

#if !defined(NRF51) && !defined(NRF52) && !defined(__RFduino__)
#error "This example only works with nRF51 boards"
#endif

iBeacon beacon;
 
void setup() {
  char* uuid                   = "a196c876-de8c-4c47-ab5a-d7afd5ae7129";
  unsigned short major         = 0;
  unsigned short minor         = 0;
  unsigned short measuredPower = -55;
  
  pinMode(19, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  beacon.begin(uuid, major, minor, measuredPower);
}

void loop() {
  beacon.loop();
  delay(15);
  sd_power_system_off();
}
