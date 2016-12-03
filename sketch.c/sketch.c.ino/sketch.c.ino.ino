#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); 

void setup()  
{

  pinMode(13, OUTPUT);
  BT.begin(9600);
}
char a;
char compare[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
bool access = false;

void loop() 
{
  if (BT.available())
  {
    a=(BT.read());

    for (int i =0; i < 10; i++) {
        if (a == compare[i])
        {
            access = true; 
        }
    }

    if (access) {
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
  }

  access = false;
}
