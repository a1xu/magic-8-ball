// Basic demo for tap/doubletap readings from Adafruit LIS3DH

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 8, 3, 4, 5, 6);
int counter = 1;
int cases[] = {0, 1, 2, 3, 4, 5};
int rand_num;
//float avg;

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

// Used for software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// software SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

#if defined(ARDUINO_ARCH_SAMD)
// for Zero, output on USB Serial console, remove line below if using programming port to program the Zero!
   #define Serial SerialUSB
#endif

// Adjust this number for the sensitivity of the 'click' force
// this strongly depend on the range! for 16G, try 5-10
// for 8G, try 10-20. for 4G try 20-40. for 2G try 40-80
#define CLICKTHRESHHOLD 40

void setup(void) {
  randomSeed(analogRead(0));
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
//  
//#ifndef ESP8266
//  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
//#endif

  lcd.print("LIS3DH Tap Test!");
  
  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    lcd.clear();
    lcd.print("Couldnt start");
    while (1);
  }
  lcd.clear();
  lcd.print("LIS3DH found!");
  
  lis.setRange(LIS3DH_RANGE_2_G);   // 2, 4, 8 or 16 G!

  // 0 = turn off click detection & interrupt
  // 1 = single click only interrupt output
  // 2 = double click only interrupt output, detect single click
  // Adjust threshhold, higher numbers are less sensitive
//  lis.setClick(1, CLICKTHRESHHOLD);
  delay(100);

  lcd.clear();
//  lcd.print("Shake counter: ");
  lcd.print("X, Y, Z");
}

void loop() {
  lcd.setCursor(0, 1);
  
  sensors_event_t event; 
  lis.getEvent(&event);

////  avg = (abs(event.acceleration.z) + abs(event.acceleration.z) + abs(event.acceleration.z)) / 3;
//
//  lcd.print(abs(event.acceleration.x));
//  lcd.print(" ");
//  lcd.print(abs(event.acceleration.y));
//  lcd.print(" ");
//  lcd.print(abs(event.acceleration.z));

  if(abs(event.acceleration.z) > 11 || abs(event.acceleration.z) < 6){
//    lcd.print(counter);
//    counter = counter + 1;
    rand_num = random(0,6);
  }

  switch(rand_num){
    case 0:

    case 1:

    case 2:

  }

  delay(400);
  return;
}
