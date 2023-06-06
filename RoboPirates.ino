#include <Servo.h>
int ms=0;
char Incoming_value = 0; 
byte servoPinSb = 5;
byte servoPinP = 6;
byte servo1pin = 9;
byte servo2pin = 10;
byte relay1 = 11;
byte relay2 = 12;
Servo servoSb;
Servo servoP;
Servo servo1;
Servo servo2;
void setup() {

Serial1.begin(9600);
servoSb.attach(servoPinSb);
servoP.attach(servoPinP);
servo1.attach(servo1pin);
servo2.attach(servo2pin);
servoSb.writeMicroseconds(950); // necessary to arm the ESC.
servoP.writeMicroseconds(950); // necessary to arm the ESC.
servo1.write(0);
servo2.write(0);
pinMode(relay1, OUTPUT);
pinMode(relay2, OUTPUT);
digitalWrite(relay1, HIGH);
digitalWrite(relay2, HIGH);
}

void loop() {
signalo();


//Sirial1.printn(Incoming_value);
}



void signalo()
{if(Serial1.available() > 0)  
  {
    Incoming_value = Serial1.read();      //Read the incoming data and store it into variable Incoming_value
    switch (Incoming_value){
    case 'X' :stb();
    break;
    case 'P' :P();
    break;
    case 'S': STOPP();
    break;
    case 's': STOPSB();
    break;
    case 'D': 
    servo1.write(180);
    break;
    case 'd':
    servo1.write(0);
    break;
    case 'L': 
    servo2.write(180);
    break;
    case 'l':
    servo2.write(0);
    break;
    case 'A':
    digitalWrite(relay1, LOW);
    break;
    case 'a':
    digitalWrite(relay1, HIGH);
    break;
    case 'B':
    digitalWrite(relay2, LOW);
    break;
    case 'b':
    digitalWrite(relay2, HIGH);
    break;
    case '0': ms=950;
    break;
    case '1': ms=1100;
    break;
    case '2': ms=1200;
    break;
    case '3': ms=1300;
    break;
    case '4': ms=1400;
    break;
    case '5': ms=1500;
    break;
    case '6': ms=1600;
    break;
    case '7': ms=1700;
    break;
    case '8': ms=1800;
    break;
    case '9': ms=1900;          
    break;

          }    }   }



void stb(){

servoP.writeMicroseconds(ms);
}
void P(){
servoSb.writeMicroseconds(ms);

}
void STOPSB(){
servoSb.writeMicroseconds(950);

}
void STOPP(){

servoP.writeMicroseconds(950);
}