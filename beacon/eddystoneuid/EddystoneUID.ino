// Copyright (c) Sandeep Mistry. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

// Import libraries (EddystoneBeacon depends on SPI)
#include <SPI.h>
#include <EddystoneBeacon.h>

// define pins (varies per shield/board)
//
//   Adafruit Bluefruit LE   10, 2, 9
//   Blend                    9, 8, UNUSED
//   Blend Micro              6, 7, 4
//   RBL BLE Shield           9, 8, UNUSED

#define EDDYSTONE_BEACON_REQ   6
#define EDDYSTONE_BEACON_RDY   7
#define EDDYSTONE_BEACON_RST   4

EddystoneBeacon eddystoneBeacon = EddystoneBeacon(EDDYSTONE_BEACON_REQ, EDDYSTONE_BEACON_RDY, EDDYSTONE_BEACON_RST);
BLEUuid         uid             = BLEUuid("01020304050607080910-AABBCCDDEEFF"); // <namespace id>-<instance id>

void setup() {
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
  eddystoneBeacon.begin(-4, uid); // power, UID
}

void loop() {
  eddystoneBeacon.loop();
  delay(15);
  sd_power_system_off();
}
