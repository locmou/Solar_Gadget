#include <Arduino.h>

#define NUM_OF_DIGITS 4

int latch = 4; //74HC595  pin 9 STCP
int cs = 5; //74HC595  pin 10 SHCP
int data = 3; //74HC595  pin 8 DS
int dPins[4] = {11, 10, 9, 8};

//  DP G F E D C B A
//0: 1 1 0 0 0 0 0 0 0xc0
//1: 1 1 1 1 1 0 0 1 0xf9
//2: 1 0 1 0 0 1 0 0 0xa4
//3: 1 0 1 1 0 0 0 0 0xb0
//4: 1 0 0 1 1 0 0 1 0x99
//5: 1 0 0 1 0 0 1 0 0x92
//6: 1 0 0 0 0 0 1 0 0x82
//7: 1 1 1 1 1 0 0 0 0xf8
//8: 1 0 0 0 0 0 0 0 0x80
//9: 1 0 0 1 0 0 0 0 0x90
unsigned char table[] =
{0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90};

void setup() {
  Serial.begin(115200);
  pinMode(latch, OUTPUT);
  pinMode(cs, OUTPUT);
  pinMode(data, OUTPUT);
  for (int j = 0; j < NUM_OF_DIGITS; j++) pinMode(dPins[j], OUTPUT);
}

void loop() {
  //Count from 0 to 9 on each digit
  for (int i = 0; i < NUM_OF_DIGITS; i++) {
    for (int j = 0; j < 10; j++) {
      Display(i, j);
      delay(500);
      Serial.println(j);
    }
    delay(500);
  }
}

void Display(int id, unsigned char num)
{
  digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, table[num]);
  digitalWrite(latch, HIGH);
  for (int j = 0; j < NUM_OF_DIGITS; j++) digitalWrite(dPins[j], LOW);
  digitalWrite(dPins[id], HIGH);
}

