    //Le capteur
#include "DHT.h"          // inclus la librairie DHT.h dans le code
#define DHTPIN 3          // broche ou le capteur est branché
#define DHTTYPE DHT11     // Model du capteur : DHT 11 
DHT dht(DHTPIN, DHTTYPE); // Déclaration du capteur


  //L'écran
  
#include <LiquidCrystal.h>              // Inclus la bibliothèque LiquideCrystal
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //Déclaration des pins de l'écran


  //La LED RGB

#define RED 5
#define BLUE 6
  
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);       // Initialise le nb de caractères et de lignes
  dht.begin();
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
}

int redValue;
int blueValue;
float x;

void loop() {
  
  delay(2000);                     // Délais entre chaque mesure
  float h = dht.readHumidity();    //Lecture Humidité
  float t = dht.readTemperature(); //Lecture Temperature
  



  //Affichage LCD
  
  //Ligne 1  
lcd.setCursor(0, 0);  //Met le curseur en colonne 1 et ligne 1
lcd.print("Hum: ");   //Affiche sur le LCD la chaine de caractère "Hum: "
lcd.setCursor(10, 0); //Met le curseur en colone 10 (ligne 1)
lcd.print(h);         //Affiche la variable h
lcd.setCursor(15, 0); //Met le curseur en colone 15 (ligne 1)
lcd.print("%");       //Affiche le caractère "%"

  //Ligne 2
lcd.setCursor(0, 1);  //Met le curseur en colonne 1 et ligne 2
lcd.print("Temp: ");  //Affiche sur le LCD la chaine de caractère "Temp: "
lcd.setCursor(10, 1); //Met le curseur en colone 10 (ligne 2)
lcd.print(t);         //Affiche la variable t
lcd.setCursor(15, 1); //Met le curseur en colone 15 (ligne 2)
lcd.print("C");       //Affiche le caractère "C"
 

  //Affichage Serie

 Serial.print("Temp = ");   //Affiche la chaine de caractère "Temp = " sur le port série
 Serial.print(t);           //Affiche la variable t sur le port série
 Serial.print(" °C Hum = ");//Affiche la chaine de caractère " °C Hum = " sur le port série
 Serial.print(h);           //Affiche la variable h sur le port série
 Serial.println(" %");      //Affiche la chaine de caractère " %" sur le port série

delay(2000);               //Délais de X secondes


  //Lumière LED

#define delayTime 100
redValue = 0; 
blueValue = 0;
x == t;


if (t <=10) {
    blueValue += 100;
    redValue -= 100;
digitalWrite(BLUE, blueValue);
  
}

if (t >10 ) {
  redValue += 100;
  blueValue -= 100;
  digitalWrite(RED, redValue);

}

  
} 
  
