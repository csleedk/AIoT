#include <SoftwareSerial.h>

int led = 13;

SoftwareSerial BTSerial(2,3);

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  if(BTSerial.available()) 
  {
    char data = BTSerial.read();
    Serial.write(data);
    switch(data)
    {
      case '1': digitalWrite(led, HIGH);
        break;
      case '0': digitalWrite(led, LOW);
        break;
    }
  }
  if(Serial.available())
    BTSerial.write(Serial.read());
  delay(1);
  
}
