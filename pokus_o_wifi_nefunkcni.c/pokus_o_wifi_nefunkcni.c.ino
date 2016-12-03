
#include <SoftwareSerial.h>
#include <WiFi.h>

SoftwareSerial BT(10, 11); 
WiFiClient client;
IPAddress server(74,125,115,105);

char ssid[] = "cichnovabrno.public";
char pass[] = "cichnovabrno";

int status = WL_IDLE_STATUS;

void setup()  
{
  pinMode(13, OUTPUT);
  BT.begin(9600);
 
  if (WiFi.status() == WL_NO_SHIELD) {
    digitalWrite(12, HIGH);
    while (true);
  }

  while ( status != WL_CONNECTED) {
    status = WiFi.begin(ssid, 0, pass);
    delay(10000);
  }
  
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
