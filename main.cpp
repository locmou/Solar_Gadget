#include <Arduino.h>


#include "SevSeg.h" // La librairie 7 segments
SevSeg sept_segments; // On appel la librairie

void setup(){
  byte nombre_chiffre_7_segments = 4; // Nombre de digit de votre 7 segments
  // Les broches de votre 7 segments
  byte Broche_pins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};

  bool resistance_sur_Segments = true; // On applique une résistance sur chaque segment 
  bool pause_entre_mise_a_jour = true; // On fait une mini pause entre chaque segment
  byte configuration_materiel = COMMON_CATHODE; // On fait un 7 segments a cathode commune
  sept_segments.begin(configuration_materiel, nombre_chiffre_7_segments, Broche_pins, segmentPins, resistance_sur_Segments); // On initialize l'afficheur 7 segments
  sept_segments.setBrightness(90); // On initialize la luminosité de l'afficheur
}

void loop(){
    sept_segments.setNumber(45); // On assigne le nombre 16 à l'afficheur 7 segments
    sept_segments.refreshDisplay(); // On rafraichit l'affichage pour que le nouveau nombre soit pris en compte
}
/*

void setup() {
  // put your setup code here, to run once:

}

void loop() {
digitalWrite(13,HIGH);
delay(250);
digitalWrite(13,LOW);
delay(250);

}


void setup()
{
    Serial.begin(9600);
}

void loop()
{
    // variable contenant le caractère à lire
    char carlu = 0;
    // variable contenant le nombre de caractère disponibles dans le buffer
    int cardispo = 0;

    cardispo = Serial.available();

    while(cardispo > 0) // tant qu'il y a des caractères à lire
    {
        carlu = Serial.read(); // on lit le caractère
        Serial.print(carlu); // puis on le renvoi à l’expéditeur tel quel
        cardispo = Serial.available(); // on relit le nombre de caractères dispo
    }
    // fin du programme
}
*/