/*
 * Author: SMRAZA KEEN
 * Date:2016/6/29
 * IDE V1.6.9
 * Email:TechnicSmraza@outlook.com
 * Function:
 */
#define H1 11
#define H2 2
#define H3 7
#define H4 8
#define H5 3
#define H6 6
#define H7 4
#define H8 5

#define L1 A3
#define L2 A2
#define L3 A1
#define L4 10
#define L5 A0
#define L6 9
#define L7 A4
#define L8 A5

int speed = 30;
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



void setup() {
  pinMode(H1,OUTPUT);
  pinMode(H2,OUTPUT);
  pinMode(H3,OUTPUT);
  pinMode(H4,OUTPUT);
  pinMode(H5,OUTPUT);
  pinMode(H6,OUTPUT);
  pinMode(H7,OUTPUT);
  pinMode(H8,OUTPUT);

  pinMode(L1,OUTPUT);
  pinMode(L2,OUTPUT);
  pinMode(L3,OUTPUT);
  pinMode(L4,OUTPUT);
  pinMode(L5,OUTPUT);
  pinMode(L6,OUTPUT);
  pinMode(L7,OUTPUT);
  pinMode(L8,OUTPUT);
}

void loop() {
  for (int i = 0 ; i < 8 ; i++) {
    for (int j = 0 ; j < 8 ; j++) {
      for (int k = 0 ; k < speed ; k++) {
        int points[2][2] = {0, 0, i, j};

        drawPoints(table, points, 2);
        Display(table); //Animation 1: Heart-shaped display(big)
      }
      ClearTable();
    }
  }
  //ClearTable();
}

//add points to draw
void drawPoints(unsigned char dat[8][8], int points[][2], int n) {
  for (int i = 0 ; i < n ; i++) {
    int x = points[i][0];
    int y = points[i][1];
    dat[x][y] = 1;
  }
}

//display function
void Display(unsigned char dat[8][8]) {

  int delayTime = 1;

  digitalWrite(L1,LOW); //select 1th row
  digitalWrite(H1,dat[0][0]);
  digitalWrite(H2,dat[1][0]);
  digitalWrite(H3,dat[2][0]);
  digitalWrite(H4,dat[3][0]);
  digitalWrite(H5,dat[4][0]);
  digitalWrite(H6,dat[5][0]);
  digitalWrite(H7,dat[6][0]);
  digitalWrite(H8,dat[7][0]);
  delay(delayTime); //Wait LED is lit.
  Clear();  //Clear shadow

  digitalWrite(L2,LOW); //select 2th row
  digitalWrite(H1,dat[0][1]);
  digitalWrite(H2,dat[1][1]);
  digitalWrite(H3,dat[2][1]);
  digitalWrite(H4,dat[3][1]);
  digitalWrite(H5,dat[4][1]);
  digitalWrite(H6,dat[5][1]);
  digitalWrite(H7,dat[6][1]);
  digitalWrite(H8,dat[7][1]);
  delay(delayTime);
  Clear();

  digitalWrite(L3,LOW); //select 3th row
  digitalWrite(H1,dat[0][2]);
  digitalWrite(H2,dat[1][2]);
  digitalWrite(H3,dat[2][2]);
  digitalWrite(H4,dat[3][2]);
  digitalWrite(H5,dat[4][2]);
  digitalWrite(H6,dat[5][2]);
  digitalWrite(H7,dat[6][2]);
  digitalWrite(H8,dat[7][2]);
  delay(delayTime);
  Clear();

  digitalWrite(L4,LOW); //select 4th row
  digitalWrite(H1,dat[0][3]);
  digitalWrite(H2,dat[1][3]);
  digitalWrite(H3,dat[2][3]);
  digitalWrite(H4,dat[3][3]);
  digitalWrite(H5,dat[4][3]);
  digitalWrite(H6,dat[5][3]);
  digitalWrite(H7,dat[6][3]);
  digitalWrite(H8,dat[7][3]);
  delay(delayTime);
  Clear();

  digitalWrite(L5,LOW); //select 5th row
  digitalWrite(H1,dat[0][4]);
  digitalWrite(H2,dat[1][4]);
  digitalWrite(H3,dat[2][4]);
  digitalWrite(H4,dat[3][4]);
  digitalWrite(H5,dat[4][4]);
  digitalWrite(H6,dat[5][4]);
  digitalWrite(H7,dat[6][4]);
  digitalWrite(H8,dat[7][4]);
  delay(delayTime);
  Clear();

  digitalWrite(L6,LOW); //select 6th row
  digitalWrite(H1,dat[0][5]);
  digitalWrite(H2,dat[1][5]);
  digitalWrite(H3,dat[2][5]);
  digitalWrite(H4,dat[3][5]);
  digitalWrite(H5,dat[4][5]);
  digitalWrite(H6,dat[5][5]);
  digitalWrite(H7,dat[6][5]);
  digitalWrite(H8,dat[7][5]);
  delay(delayTime);
  Clear();

  digitalWrite(L7,LOW); //select 7th row
  digitalWrite(H1,dat[0][6]);
  digitalWrite(H2,dat[1][6]);
  digitalWrite(H3,dat[2][6]);
  digitalWrite(H4,dat[3][6]);
  digitalWrite(H5,dat[4][6]);
  digitalWrite(H6,dat[5][6]);
  digitalWrite(H7,dat[6][6]);
  digitalWrite(H8,dat[7][6]);
  delay(delayTime);
  Clear();

  digitalWrite(L8,LOW); //select 8th row
  digitalWrite(H1,dat[0][7]);
  digitalWrite(H2,dat[1][7]);
  digitalWrite(H3,dat[2][7]);
  digitalWrite(H4,dat[3][7]);
  digitalWrite(H5,dat[4][7]);
  digitalWrite(H6,dat[5][7]);
  digitalWrite(H7,dat[6][7]);
  digitalWrite(H8,dat[7][7]);
  delay(delayTime);
  Clear();
}

//clear display
void Clear() {
  digitalWrite(H1,LOW);
  digitalWrite(H2,LOW);
  digitalWrite(H3,LOW);
  digitalWrite(H4,LOW);
  digitalWrite(H5,LOW);
  digitalWrite(H6,LOW);
  digitalWrite(H7,LOW);
  digitalWrite(H8,LOW);

  digitalWrite(L1,HIGH);
  digitalWrite(L2,HIGH);
  digitalWrite(L3,HIGH);
  digitalWrite(L4,HIGH);
  digitalWrite(L5,HIGH);
  digitalWrite(L6,HIGH);
  digitalWrite(L7,HIGH);
  digitalWrite(L8,HIGH);
}

void ClearTable() {
  for (int i = 0 ; i < 8 ; i++) {
    for (int j = 0 ; j < 8 ; j++) {
      table[i][j] = 0;
    }
  }
}
