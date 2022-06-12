#include <SimpleDHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// for DHT11, //    VCC: 5V or 3V  //    GND: GND    //    DATA: 2
int pinDHT11 = 6;                                                                                                                                      
SimpleDHT11 dht11(pinDHT11);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  
  // read without samples.
  byte temperature = 0;
  byte humidity = 0;    //byte는 8비트
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err); delay(1000);
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" *C, "); 
  Serial.print((int)humidity); Serial.println(" H");   //25부터 27이 우리에게 필요

  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("temperature=");
  lcd.setCursor(12,0);
  lcd.print(temperature);
  lcd.setCursor(14,0);
  lcd.print((char)0xDF);
  lcd.setCursor(15,0);
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("humidity= ");
  lcd.setCursor(10,1);
  lcd.print(humidity);
  lcd.setCursor(12,1);
  lcd.print("H");
  
  // DHT11 sampling rate is 1HZ.
  delay(1000);   //1.5초 딜레이
}
