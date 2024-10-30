#include <Arduino.h>


int incomingByte = 0; // variable pour lecture de l'octet entrant

void setup() {
  Serial.begin(9600); // ouvre le port série et fixe le débit à 9600 bauds
}

void loop() {
  // envoie une donnée sur le port série seulement quand reçoit une donnée
  if (Serial.available() > 0) { // si données disponibles sur le port série
    // lit l'octet entrant
    incomingByte = Serial.read();

    // renvoie l'octet reçu
    Serial.print("Octet recu: ");
    Serial.println((char)incomingByte, DEC);
  }
}