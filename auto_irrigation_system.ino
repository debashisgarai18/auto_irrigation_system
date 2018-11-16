#include <SoftwareSerial.h>

SoftwareSerial BTserial(10, 11); // RX | TX

int sensorPin = A0;

int sensorValue = 0;
int WATERPUMP = 13; //motor pump connected to pin 13
int val ; //This variable stores the value received from Soil moisture sensor.
int fugt = A0;
const int threshold = "100%";
void setup() {
  
  pinMode(13,OUTPUT); //Set pin 13 as OUTPUT piN
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  while (! Serial);// wait for serial port to connect. Needed for native USB
  Serial.println("Speed 0 to 255");
  Serial.begin(9600);
  pinMode(fugt, INPUT);
  BTserial.begin(9600); 
}

void loop()
  { 
  if (Serial.available()) //loop to operate motor
  {
    int speed = Serial.parseInt(); // to read the number entered as text in the Serial Monitor 
    
    if (speed >= 0 && speed <=255)
    {
      analogWrite(WATERPUMP, speed);// tuns on the motor at specified speed 
    }
  }
  val = analogRead(jordFugt(fugt));  //Read data from soil moisture sensor 
  if(val>=threshold) 
  {
  digitalWrite(13,LOW); //if soil moisture sensor provides LOW value send LOW value to motor pump and motor pump goes off
  }
  else
  {
  digitalWrite(13,HIGH); //if soil moisture sensor provides HIGH value send HIGH value to motor pump and motor pump get on
  }
  delay(400); //Wait for few second and then continue the loop.
  Serial.print("Moisture: ");
  Serial.print(jordFugt(fugt));
  Serial.print("% ");
  delay(1000);
}
int jordFugt(int fugt)
{
  int value1 = analogRead(fugt);
  int sensorConstrain1 = constrain(value1, 485, 1023);
  int soil1 = map(sensorConstrain1, 485, 1023, 100, 0);
  return(soil1);
}
