#include <Arduino.h>
#include "EITB225_PIRSensor_Arduino.h"

uint8_t sen1Pin = 2;
uint8_t sen2Pin = 3;
uint8_t sen3Pin = 21;

float encodeRatio = 360/374;

int pirPos[] = {
		-100*encodeRatio,
		-50*encodeRatio,
		0,
		50*encodeRatio,
		100*encodeRatio
};


void sen1(){

}

void sen2(){

}

void sen3(){

}





void setup() {

	attachInterrupt(digitalPinToInterrupt(sen1Pin), sen1, RISING);
	attachInterrupt(digitalPinToInterrupt(sen2Pin), sen2, RISING);
	attachInterrupt(digitalPinToInterrupt(sen3Pin), sen3, RISING);

}

void loop() {
	int waiter = 0;

	while(waiter == 0);

	move

}


