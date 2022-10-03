#include <Arduino.h>

#define LED_Red D3
#define LED_Yellow D5
#define LED_Blue D6

int sensorValue = 0;

float voltage = 0;

void setup()
{

  Serial.begin(9600);

  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Yellow, OUTPUT);
  pinMode(LED_Blue, OUTPUT);
}

void loop()
{
  delay(1000);

  sensorValue = analogRead(A0);

  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.println(voltage);

  while (voltage < 5.1)
  {
    digitalWrite(LED_Blue, LOW);
    digitalWrite(LED_Yellow, LOW);
    digitalWrite(LED_Red, LOW);
    if (voltage < 1.25)
    {
      digitalWrite(LED_Blue, HIGH);
      break;
    }
    if (voltage < 2.5)
    {
      digitalWrite(LED_Yellow, HIGH);
      break;
    }
    digitalWrite(LED_Red, HIGH);
    break;
  }
}