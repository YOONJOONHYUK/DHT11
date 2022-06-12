#include <SimpleDHT.h>

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

 
  // DHT11 sampling rate is 1HZ.
  delay(1500);   //1.5초 딜레이
}
