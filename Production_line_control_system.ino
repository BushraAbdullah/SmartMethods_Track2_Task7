#include <Servo.h>
Servo motor;
int tr=10,ec=9; //pin for sensor
int x=0; //duration of the pulse
int d=0; //distance

void setup() {
 
motor.attach(4);
pinMode(tr,OUTPUT);
pinMode(ec,INPUT);
Serial.begin(9600);
}

void loop() {
  
digitalWrite(tr,0);
delayMicroseconds(2);

digitalWrite(tr,1);
delayMicroseconds(10);
digitalWrite(tr,0);

x=pulseIn(ec,1);
d=x*0.034/2; // determine the distance in cm
Serial.print("Distance");
Serial.println(d);
// ranges of small,midium and large boxes:
if (d<300 && d>200) {
  motor.write(135);
  }
  else if (d<199 && d>100){
    motor.write(90);
    }
    else if (d<99 && d>0){
      motor.write(45);
      }
}
