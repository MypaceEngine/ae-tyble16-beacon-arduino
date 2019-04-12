#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/sleep.h>

const uint8_t WDT_PRSCL_125 = (_BV(WDP1) | _BV(WDP0));
const uint8_t WDT_PRSCL_250 = _BV(WDP2);
const uint8_t WDT_PRSCL_500 = (_BV(WDP2) | _BV(WDP0));
const uint8_t WDT_PRSCL_1000 = (_BV(WDP2) |_BV(WDP1));
const uint8_t WDT_PRSCL_2000 = (_BV(WDP2) |_BV(WDP1) | _BV(WDP0));
const uint8_t WDT_PRSCL_4000 = _BV(WDP3);
const uint8_t WDT_PRSCL_8000 = (_BV(WDP3) |_BV(WDP0));

void start_wdt(int8_t prscl) {
  cli();
  WDTCSR  = _BV(WDIE) | prscl;
  wdt_reset();
  sei();
}

void setup() {
  CCP = 0xD8;
  CLKMSR = 0;
  CCP = 0xD8;
  CLKPSR = 8;
  cli();
  PORTB = 0;
  ACSR |= 0x80;    // disable Analog Comparator.
  ADCSRA &= 0x7f;  // disable ADC
  PRR = 15;
  sei();
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
}

ISR(WDT_vect) {}

void loop() {
  digitalWrite(2,LOW);
  delay(50);
  digitalWrite(2,HIGH);
  
  start_wdt(WDT_PRSCL_8000);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
  sleep_cpu();
  sleep_disable();  
}
