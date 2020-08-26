#include <Wire.h>
#include <dht.h>
#include <LiquidCrystal_I2C.h>
#define dht_apin A0 
LiquidCrystal_I2C lcd(0x27, 16, 2);
dht DHT;

void setup(){
  Serial.begin(9600);
  lcd.begin();                      // initialize the lcd 
  lcd.begin();
  lcd.backlight();
}

void loop(){
  DHT.read11(dht_apin);

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print(" C");
  
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(DHT.humidity);
  lcd.print(" %");
  delay(10000);
}
