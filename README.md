# Introduction
part 1: is the operation of the LED with a simple electrical circuit in addition to the special programming code that shows the inputs and outputs of the signals with the specified lighting duration (Delay).


part 2: is operation of the LED Matrix and I used the shape (heart) to make it the only one that works , The LED Matrixes consist of an array of LEDs arranged in a grid. This display has a total of 64 LEDs in 8 rows and 8 columns.
# Components 
Part 1:
1-Yellow LED (1) 
2- Pushbutton (1)
3-Arduino Uno R3 (1)
4-10 kΩ Resistor (2)


Part 2:
1-Blue LED (24) 
2-Red LED (40)
3-Arduino Uno R3 (1)
4-1 kΩ Resistor (8)
# Used by
Tinkercad
[Part 1](https://www.tinkercad.com/things/bbXa8CN0cHX-epic-vihelmo-gogo/editel?sharecode=uCfsqxi3PktO4ExZ-mISIMvmH9Arxq3SakBNoTY8X6o).
[Part 2](https://www.tinkercad.com/things/6GDPoiwM7Gm-ingenious-lahdi/editel?sharecode=OAuCt8KuGlfElA_yeD1KdNkfK1UUpg0sh-GMlOYlL2Q).
# Circuit
Part 1:
![Epic Vihelmo-Gogo](https://github.com/joudalhef/SM23-EPD01/assets/139080884/31d89c9d-b524-415e-b914-dbf113fe3f93)


Part 2:
![Ingenious Lahdi](https://github.com/joudalhef/SM23-EPD01/assets/139080884/60e6bbf5-a20b-4601-a0e5-28442e1dfdda)
# Code

Part 1:

int pushButton = 0;

void setup() 

{
  
  pinMode(13, OUTPUT);
  
  pinMode(2, INPUT);

}

void loop() 

{
 pushButton = digitalRead(2);
  
  if (pushButton == HIGH) {
    
    digitalWrite(13, HIGH);
  }
 
  else{
    
    digitalWrite(13, LOW);
  }
  
  delay(10);

}







Part 2:

#define ROW1 13

#define ROW2 12

#define ROW3 11

#define ROW4 10

#define ROW5 9

#define ROW6 8

#define ROW7 7

#define ROW8 6


#define COL1 5

#define COL2 4

#define COL3 3

#define COL4 2

#define COL5 A4

#define COL6 A3

#define COL7 A2

#define COL8 A1

const int row[] = {ROW1, ROW2, ROW3, ROW4, ROW5, ROW6, ROW7, ROW8};


const int col[] = {COL1,COL2, COL3, COL4, COL5, COL6, COL7, COL8};



int A[8][8] = 
       
	{{1,0,0,1,1,0,0,1},
		      
	 {0,0,0,0,0,0,0,0},
		      
	 {0,0,0,0,0,0,0,0},
		      
	 {0,0,0,0,0,0,0,0},
		      
	 {1,0,0,0,0,0,0,1},
		      
	 {1,1,0,0,0,0,1,1},
		      
	 {1,1,1,0,0,1,1,1},
		     
	 {1,1,1,1,1,1,1,1}};

void setup() {
  
  Serial.begin(9600);
  
  for (int i = 2; i <= 13; i++) {
    
    pinMode(i, OUTPUT);
    
    digitalWrite(i, LOW);

  }
  
  pinMode(A1, OUTPUT);
  
  digitalWrite(A1, LOW);
  
  pinMode(A2, OUTPUT);
  
  digitalWrite(A2, LOW);
 
  pinMode(A3, OUTPUT);
 
  digitalWrite(A3, LOW);
  
  pinMode(A4, OUTPUT);
  
  digitalWrite(A4, LOW);
}

void loop() {

  delay(10);
  
  yaz(A);

}


void  yaz(int matrix[8][8]){
  
  for (int c=0; c<8; c++){

   
    digitalWrite(col[c], HIGH);
    
    for (int r = 0; r < 8; r++){
      
      digitalWrite(row[r], 255*matrix[r][c]);
    
     delay(1);
    }
    for (int r = 0; r < 8; r++){
      
      digitalWrite(row[r], HIGH);
     
     delay(1);
    }
  
    digitalWrite(col[c], LOW);
  }
}
