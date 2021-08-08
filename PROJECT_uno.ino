

//#include <Keyboard.h>
/*
  10000


*/
int one = 4;
int two = 3;
int three = 2;
int four = 5;
int five = 6;
int six = 7;
int space = 8;//
int caps = 11;
int add =  0;
void setup() {
  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(one, INPUT_PULLUP);
  pinMode(two, INPUT_PULLUP);
  pinMode(three, INPUT_PULLUP);
  pinMode(four, INPUT_PULLUP);
  pinMode(five, INPUT_PULLUP);
  pinMode(six, INPUT_PULLUP);
  pinMode(space, INPUT_PULLUP);
  pinMode(caps, INPUT_PULLUP);
  Serial.begin(9600);
 // Keyboard.begin();
}

void loop() {
  int input = B1000000;

// array for translating the input signal to the ascii value for the small letters
  int translator[128] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 65, 0, 66, 0, 75, 0, 76, 0, 67, 73, 70, 0, 77, 83, 80, 0, 69, 0, 72, 0, 79, 0, 82, 0, 68, 74, 71, 0, 78, 84, 81, 0, 0, 0, 0, 0, 85, 0, 86, 0, 0, 0, 0, 0, 88, 0, 0, 0, 0, 0, 0, 0, 90, 0, 0, 0, 0, 87, 0, 0, 89, 0, 0};
// array for translating the input signal to the ascii value of Capital letters
  int TRANSLATOR[128] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 97, 0, 98, 0, 107, 0, 108, 0, 99, 105, 102, 0, 109, 115, 112, 0, 101, 0, 104, 0, 111, 0, 114, 0, 100, 106, 103, 0, 110, 116, 113, 0, 0, 0, 0, 0, 117, 0, 118, 0, 0, 0, 0, 0, 120, 0, 0, 0, 0, 0, 0, 0, 122, 0, 0, 0, 0, 119, 0, 0, 121, 0, 0};


  if (digitalRead(one) == LOW) {

    input += B1;
  }
  if (digitalRead(two) == LOW) {
    input  += B10;

  }
  if (digitalRead(three) == LOW) {
    input += B100;
  }
  if (digitalRead(four) == LOW) {
    input += B1000;
  }
  if (digitalRead(five) == LOW) {
    input += B10000;
  }
  if (digitalRead(six) == LOW) {
    input += B100000;
  } //AAAAAAAAAAAaAAaAAaaaaaAAAaaaaaa

  if (digitalRead(space) == LOW) {

    input = B1111;
  }
  if (input == B1111) //
  {
    Serial.write(" ");
 //   Serial.print("\n"); 
   delay(100);
  } 
   if ( digitalRead(caps)== HIGH)
  {
    if (input != B1000000){
      Serial.write(translator[input]);
 //   Serial.print("\n");
    delay(100);
    }
  } //AAAAAA
  
   else 
  {
    if (input != B1000000){
      Serial.write(TRANSLATOR[input]);
   //     Serial.print("\n");
        delay(100);
    }
  } 
  //Serial.println(translator[input]);
  //
  delay(200);
  //Keyboard.releaseAll();
}
