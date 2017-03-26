#include <math.h>
const int ledPin=9;                 //Connect the LED Grove module to Pin12, Digital 12
const int thresholdvalue=10;         //The threshold for which the LED should turn on. 
float Rsensor; //Resistance of sensor in K

#include "rgb_lcd.h"

rgb_lcd lcd;

//int buttonPin = 2; //the Grove port No. you attached a button to

int RLED = 3;
int GLED = 4;
int BLED = 5;

/*
int buttonPushCounter = 1;
int buttonState = 1;
int lastButtonState = 0;
*/

void setup(){
  
  Serial.begin(9600);                //Start the Serial connection
  //pinMode(ledPin,OUTPUT);            //Set the LED on Digital 12 as an OUTPUT
  
    lcd.begin(16, 2);
    //lcd.print("Critical");
}

void loop(){

int sensorValue = analogRead(0); 
  Rsensor=(float)(1023-sensorValue)*10/sensorValue;
  if(Rsensor>thresholdvalue)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
  digitalWrite(ledPin,LOW);
  }
  Serial.println("the analog read data is ");
  Serial.println(sensorValue);
  Serial.println("the sensor resistance is ");
  Serial.println(Rsensor,DEC);//show the light intensity on the serial monitor;
  delay(1000);
  
//pinMode(buttonPin, INPUT); 

/*
buttonState = digitalRead(buttonPin); //read the status of the button

if (buttonPushCounter > 2) {
    buttonPushCounter = 0;
  }
if (buttonState > 2) {
    buttonState = 0;
  }
*/
if (Rsensor < 333) {
    lcd.clear();
    //digitalWrite(BLED,0);
    //digitalWrite(GLED,0);
    //pinMode(RLED, OUTPUT);
  //digitalWrite(RLED,1);
  lcd.setRGB(255, 0, 0);
  lcd.setCursor(0, 0);
  lcd.print("Level: ");
  lcd.print(Rsensor,DEC);}
else if (Rsensor < 666) {
    lcd.clear();
    //digitalWrite(RLED,0);
    //digitalWrite(BLED,0);
      //pinMode(GLED, OUTPUT);
  //digitalWrite(GLED,1);
  lcd.setRGB(0, 255, 0);
  lcd.setCursor(0, 0);
  lcd.print("Level: ");
  lcd.print(Rsensor,DEC);}
else {
    lcd.clear();
      //digitalWrite(GLED,0);
      //digitalWrite(RLED,0);
      //pinMode(BLED, OUTPUT);
  //digitalWrite(BLED,1);
  lcd.setRGB(0, 0, 255);
  lcd.setCursor(0, 0);
  lcd.print("Level: ");
  lcd.print(Rsensor,DEC);}
  }
//buttonPushCounter++;
//lastButtonState = buttonState;
//delay(5000);
