#include <cvzone.h>

SerialData serialData(5, 1);
int valRec[5];

void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  serialData.begin();
}

void loop() {
  serialData.Get(valRec);

  digitalWrite(13, valRec[0]);
  digitalWrite(12, valRec[1]);
  digitalWrite(11, valRec[2]);
  digitalWrite(10, valRec[3]);
  digitalWrite(9, valRec[4]);
}