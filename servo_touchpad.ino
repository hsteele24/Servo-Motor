#include <Servo.h>
#include <SPI.h>
Servo myservo; 

void setup()
{
  Serial.begin(9600);  // serial begin for serial monitor
  myservo.attach(4);   // attach servo to analog pin 4 
}

 int x,y = 0;
 int readX() // returns the value of the touchscreen's x-axis
{
  int xr=0;
  pinMode(A0, INPUT);  // pin setup for servo motor
  pinMode(A1, OUTPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  digitalWrite(A1, LOW);  // set A1 to GND
  digitalWrite(A3, HIGH); // set A3 as 5V
  delay(5);
  xr=analogRead(0);       // stores the value of the x-axis
  return xr;
}

  int readY() // returns the value of the touchscreen's y-axis
{
  int yr=0;
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT); 
  pinMode(A2, OUTPUT);
  pinMode(A3, INPUT); 
  digitalWrite(14, LOW);  // set A0 to GND
  digitalWrite(16, HIGH); // set A2 as 5V
  delay(5);
  yr=analogRead(1);       // stores the value of the y-axis
  return yr; 
}

void loop() {
  Serial.print(" x = ");
  x=readX();
  Serial.print(x);    // read x , print it
  y=readY();
  Serial.print(" y = ");
  Serial.println(y);  // read y , print it
  delay(5);
  if(x<1000){         // only allow servo to move if x is smaller than 1000, this is because touchpad always reads 1023x1023 
  myservo.write(x/5);
  }
  else {myservo.write(90);}  // makes servo unable to move if x is greater than 1000
}

