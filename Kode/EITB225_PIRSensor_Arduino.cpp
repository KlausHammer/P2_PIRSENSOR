#include <Arduino.h>
#include "EITB225_PIRSensor_Arduino.h"
//#include "src/moveFuncs.cpp"
//#include "src/kali.cpp"

const uint8_t sen1Pin = 2;
const uint8_t sen2Pin = 3;
const uint8_t sen3Pin = 21;

int waiter = 0;

float encodeRatio = 360/374;

int pirPos[] = {
		-100*encodeRatio,
		-50*encodeRatio,
		0,
		50*encodeRatio,
		100*encodeRatio
};


void sen1(){


	waiter = 1;
}

void sen2(){

}

void sen3(){

}

void setup() {
	Serial.begin(9600);
	attachInterrupt(digitalPinToInterrupt(sen1Pin), sen1, RISING);
	attachInterrupt(digitalPinToInterrupt(sen2Pin), sen2, RISING);
	attachInterrupt(digitalPinToInterrupt(sen3Pin), sen3, RISING);

	//kalibrering();

}

void loop() {
	int test2;

	while(waiter == 0);

	//move(test2);

}


