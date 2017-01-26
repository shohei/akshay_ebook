#include "lookuptable.h"

const int brailleIntTable[] = {0,27,4,23,57,49,59,2,47, 31,33,19,1,3,17,18,7,8,10,12,13,9,14,15,11,6,37,5,41,63,22,53,16,32,40,48,52,36,56,60,44,24,28,34,42,50,54,38,58,62,46,26,30,35,43,29,51,55,39,25,45,61,20,21};

int dotPins[6] = {2,3,4,5,6,7};
int pinState[6] = {0,0,0,0,0,0};

void setup(){
	Serial.begin(9600);
	delay(1000);
	Serial.println("arduino ready");

	for(int i=0;i<6;i++){
		pinMode(dotPins[i],OUTPUT); 
	}
}

void loop(){
	if(Serial.available()){
		// String strings = Serial.readStringUntil("\n");
		char c = Serial.read();
		int ascii_code = c + 4; // char A = 97. ASCII A = 101
		Serial.print("Your input: ");
		Serial.println(ascii_code);
		int sliced_num = ascii_code - 64;
		Serial.print("sliced num: ");
		Serial.println(sliced_num);

        Serial.println(brailleIntTable[sliced_num]);
		for (byte i=0; i<6; i++) {
         byte state = bitRead(brailleIntTable[sliced_num], i);
         Serial.print(state);
         pinState[i] = state;
        }
        Serial.println();
        printBraille();
	}
	// int val = 32; //in case of "a"
	// for(int i = 0;i < 6;i++)
	// {
		// digitalWrite(dotPins[0], !!(val & (1 << 0)));
		// digitalWrite(dotPins[1], !!(val & (1 << 1)));
		// digitalWrite(dotPins[2], !!(val & (1 << 2)));
		// digitalWrite(dotPins[3], !!(val & (1 << 3)));
		// digitalWrite(dotPins[4], !!(val & (1 << 4)));
		// digitalWrite(dotPins[5], !!(val & (1 << 5)));
	// }
}

void printBraille(){
	// x o // 1 2
	// o o // 3 4
	// o o // 5 6
	Serial.println("*** CURRENT BRAILLE ***");
	if(pinState[0]==1){
  	  Serial.print("x ");
  	  digitalWrite(dotPins[0],HIGH);
    } else{
  	  Serial.print("o ");
  	  digitalWrite(dotPins[0],LOW);
    }
	if(pinState[1]==1){
  	  Serial.println("x");
  	  digitalWrite(dotPins[1],HIGH);
    } else{
  	  Serial.println("o");
  	  digitalWrite(dotPins[1],LOW);
    }

	if(pinState[2]==1){
  	  Serial.print("x ");
  	  digitalWrite(dotPins[2],HIGH);
    } else{
  	  Serial.print("o ");
  	  digitalWrite(dotPins[2],LOW);
    }
	if(pinState[3]==1){
  	  Serial.println("x");
  	  digitalWrite(dotPins[3],HIGH);
    } else{
  	  Serial.println("o");
  	  digitalWrite(dotPins[3],LOW);
    }

	if(pinState[4]==1){
  	  Serial.print("x ");
  	  digitalWrite(dotPins[4],HIGH);
    } else{
  	  Serial.print("o ");
  	  digitalWrite(dotPins[4],LOW);
    }
	if(pinState[5]==1){
  	  Serial.println("x");
  	  digitalWrite(dotPins[5],HIGH);
    } else{
  	  Serial.println("o");
  	  digitalWrite(dotPins[5],LOW);
    }
	Serial.println("*** ***");
}