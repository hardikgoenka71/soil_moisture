//Welcome to Electronics University
//Subscribe us if you want to learn something new.


#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);


int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;
int relayPin = 6;

void setup(){
  lcd.begin(16, 2);
  pinMode(sensor_pin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);

}

void loop(){
  lcd.clear();
  lcd.setCursor(2,0);
  
  output_value= analogRead(sensor_pin);
 
  output_value = map(output_value,1005,80,0,100);
  lcd.print("Moisture: ");
  lcd.setCursor(12,0);
  lcd.print(output_value);
 Serial.print(output_value);
 Serial.println("%");
 lcd.setCursor(14,0);
  lcd.print("%");
  
  lcd.setCursor(2,1);
  if(output_value<30){
  digitalWrite(relayPin, LOW);
  lcd.print("Motor ON");
 }
 else
 {
  digitalWrite(relayPin, HIGH);
  lcd.print("Motor OFF");       
 }
  
  delay(1000);
lcd.clear();
  
}
