#include <cvzone.h>

SerialData serialData(5, 1);
int valRec[5];

void setup() {
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
  serialData.begin();
}

void loop() {
  serialData.Get(valRec);

  digitalWrite(13, valRec[0]);
  digitalWrite(11, valRec[1]);
  digitalWrite(9, valRec[2]);
  digitalWrite(7, valRec[3]);
  digitalWrite(5, valRec[4]);
}