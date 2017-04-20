#include <Arduino.h>

// Rows
#define R1 8
#define R2 6 //shift
#define R3 A4
#define R4 0 //shift
#define R5 11
#define R6 A5
#define R7 1 //shift
#define R8 9
// Cols
#define C1 7 //shift
#define C2 2 //shift
#define C3 3 //shift
#define C4 7
#define C5 10
#define C6 6
#define C7 5 //shift
#define C8 4 //shift

#define B1 A3
#define B2 A2

unsigned char table[8][8] = {
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
  0,0,0,0,0,0,0,0,
};

int datapin = 2;
int clockpin = 3;
int latchpin = 4;
byte data = 0;
int speed = 30;

void setup() {
  //shift register
  pinMode(datapin, INPUT);
  pinMode(clockpin, OUTPUT);
  pinMode(latchpin, OUTPUT);
  //rows
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  pinMode(R5, OUTPUT);
  pinMode(R6, OUTPUT);
  pinMode(R7, OUTPUT);
  pinMode(R8, OUTPUT);
  //cols
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(C4, OUTPUT);
  pinMode(C5, OUTPUT);
  pinMode(C6, OUTPUT);
  pinMode(C7, OUTPUT);
  pinMode(C8, OUTPUT);
  //buttons
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
}

// write to shift register outputs
void shiftWrite(int desiredPin, boolean desiredState) {
  pinMode(datapin, OUTPUT);
  bitWrite(data,desiredPin,desiredState);
  shiftOut(datapin, clockpin, MSBFIRST, data);
  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
  pinMode(datapin, INPUT);
}

// clear display
void Clear() {
  digitalWrite(R1, LOW);
  shiftWrite(R2, false);
  digitalWrite(R3, LOW);
  shiftWrite(R4, false);
  digitalWrite(R5, LOW);
  digitalWrite(R6, LOW);
  shiftWrite(R7, false);
  digitalWrite(R8, LOW);

  shiftWrite(C1, true);
  shiftWrite(C2, true);
  shiftWrite(C3, true);
  digitalWrite(C4, HIGH);
  digitalWrite(C5, HIGH);
  digitalWrite(C6, HIGH);
  shiftWrite(C7, true);
  shiftWrite(C8, true);
}

// set all elements of table to 0
void ClearTable() {
  for (int i = 0 ; i < 8 ; i++) {
    for (int j = 0 ; j < 8 ; j++) {
      table[i][j] = 0;
    }
  }
}

void loop() {
  int b1 = digitalRead(B1);
  int b2 = digitalRead(B2);
  if (b1 == LOW && b2 == LOW) {
    for (int i = 0 ; i < 8 ; i++) {
      for (int j = 0 ; j < 8 ; j++) {
        for (int k = 0 ; k < speed ; k++) {
          int points[1][2] = {i, j};
          drawPoints(table, points, 1);
        }
        Display(table);
        //ClearTable();
      }
    }
    ClearTable();
  }
  if (b1 == HIGH && b2 == LOW) {
    for (int i = 7 ; i >= 0 ; i--) {
      for (int j = 0 ; j < 8 ; j++) {
        for (int k = 0 ; k < speed ; k++) {
          int points[1][2] = {i, j};
          drawPoints(table, points, 1);
        }
        Display(table);
        //ClearTable();
      }
    }
    ClearTable();
  }
  if (b1 == HIGH && b2 == HIGH) {
    // for (int i = 7 ; i >= 0 ; i--) {
    //   for (int j = 7 ; j >= 0 ; j--) {
    //     for (int k = 0 ; k < speed ; k++) {
    //       int points[1][2] = {i, j};
    //       drawPoints(table, points, 1);
    //     }
    //     Display(table);
    //     //ClearTable();
    //   }
    // }
    ClearTable();
  }
  if (b1 == LOW && b2 == HIGH) {
    for (int i = 0 ; i < 8 ; i++) {
      for (int j = 7 ; j >= 0 ; j--) {
        for (int k = 0 ; k < speed ; k++) {
          int points[1][2] = {i, j};
          drawPoints(table, points, 1);
        }
        Display(table);
        //ClearTable();
      }
    }
    ClearTable();
  }
}

// add points to draw
void drawPoints(unsigned char dat[8][8], int points[][2], int n) {
  for (int i = 0 ; i < n ; i++) {
    int x = points[i][0];
    int y = points[i][1];
    dat[x][y] = 1;
  }
}

// display function
void Display(unsigned char dat[8][8]) {
  int delayTime = 1;

  shiftWrite(C1, false); //select 1th col
  digitalWrite(R1, dat[0][0]);
  shiftWrite(R2, dat[1][0] == 1);
  digitalWrite(R3, dat[2][0]);
  shiftWrite(R4, dat[3][0] == 1);
  digitalWrite(R5, dat[4][0]);
  digitalWrite(R6, dat[5][0]);
  shiftWrite(R7, dat[6][0] == 1);
  digitalWrite(R8, dat[7][0]);
  delay(delayTime); //Wait LED is lit.
  Clear();  //Clear shadow

  shiftWrite(C2, false); //select 2th col
  digitalWrite(R1, dat[0][1]);
  shiftWrite(R2, dat[1][1] == 1);
  digitalWrite(R3, dat[2][1]);
  shiftWrite(R4, dat[3][1] == 1);
  digitalWrite(R5, dat[4][1]);
  digitalWrite(R6, dat[5][1]);
  shiftWrite(R7, dat[6][1] == 1);
  digitalWrite(R8, dat[7][1]);
  delay(delayTime);
  Clear();

  shiftWrite(C3, false); //select 3th col
  digitalWrite(R1, dat[0][2]);
  shiftWrite(R2, dat[1][2] == 1);
  digitalWrite(R3, dat[2][2]);
  shiftWrite(R4, dat[3][2] == 1);
  digitalWrite(R5, dat[4][2]);
  digitalWrite(R6, dat[5][2]);
  shiftWrite(R7, dat[6][2] == 1);
  digitalWrite(R8, dat[7][2]);
  delay(delayTime);
  Clear();

  digitalWrite(C4,LOW); //select 4th col
  digitalWrite(R1, dat[0][3]);
  shiftWrite(R2, dat[1][3] == 1);
  digitalWrite(R3, dat[2][3]);
  shiftWrite(R4, dat[3][3] == 1);
  digitalWrite(R5, dat[4][3]);
  digitalWrite(R6, dat[5][3]);
  shiftWrite(R7, dat[6][3] == 1);
  digitalWrite(R8, dat[7][3]);
  delay(delayTime);
  Clear();

  digitalWrite(C5,LOW); //select 5th col
  digitalWrite(R1, dat[0][4]);
  shiftWrite(R2, dat[1][4] == 1);
  digitalWrite(R3, dat[2][4]);
  shiftWrite(R4, dat[3][4] == 1);
  digitalWrite(R5, dat[4][4]);
  digitalWrite(R6, dat[5][4]);
  shiftWrite(R7, dat[6][4] == 1);
  digitalWrite(R8, dat[7][4]);
  delay(delayTime);
  Clear();

  digitalWrite(C6,LOW); //select 6th col
  digitalWrite(R1, dat[0][5]);
  shiftWrite(R2, dat[1][5] == 1);
  digitalWrite(R3, dat[2][5]);
  shiftWrite(R4, dat[3][5] == 1);
  digitalWrite(R5, dat[4][5]);
  digitalWrite(R6, dat[5][5]);
  shiftWrite(R7, dat[6][5] == 1);
  digitalWrite(R8, dat[7][5]);
  delay(delayTime);
  Clear();

  shiftWrite(C7, false); //select 7th col
  digitalWrite(R1, dat[0][6]);
  shiftWrite(R2, dat[1][6] == 1);
  digitalWrite(R3, dat[2][6]);
  shiftWrite(R4, dat[3][6] == 1);
  digitalWrite(R5, dat[4][6]);
  digitalWrite(R6, dat[5][6]);
  shiftWrite(R7, dat[6][6] == 1);
  digitalWrite(R8, dat[7][6]);
  delay(delayTime);
  Clear();

  shiftWrite(C8, false); //select 8th col
  digitalWrite(R1, dat[0][7]);
  shiftWrite(R2, dat[1][7] == 1);
  digitalWrite(R3, dat[2][7]);
  shiftWrite(R4, dat[3][7] == 1);
  digitalWrite(R5, dat[4][7]);
  digitalWrite(R6, dat[5][7]);
  shiftWrite(R7, dat[6][7] == 1);
  digitalWrite(R8, dat[7][7]);
  delay(delayTime);
  Clear();
}
