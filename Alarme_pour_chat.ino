
#include "SR04.h"
#include "pitches.h"

#define TRIG_PIN 12
#define ECHO_PIN 11

//Partie mesure distance
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;


void setup() {
   pinMode(8, OUTPUT);
   pinMode(LED_BUILTIN, OUTPUT);
   Serial.begin(9600);
   delay(1000);
}

void loop() {
   a=sr04.Distance();
   Serial.print(a);
   Serial.println("cm");
   delay(20);
   
   if (a <= 50)  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(10);
    digitalWrite(LED_BUILTIN, LOW);
    delay(10); 
   }
   
  if (a <= 50) {
    tone (8, 600);
    delay(50);
    tone (8, 900);
    }
   else noTone(8);
}
