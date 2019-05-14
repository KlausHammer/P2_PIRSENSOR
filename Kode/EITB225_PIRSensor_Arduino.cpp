
#include "EITB225_PIRSensor_Arduino.h"

int waiter = 0;
unsigned long ofsetTime = 500;


float encodeRatio = 360/tacksPeRound;

int pirPos[] = {
		-100*encodeRatio,
		-50*encodeRatio,
		0,
		50*encodeRatio,
		100*encodeRatio
};

unsigned long timeSet[] = {
		0,
		0,
		0
};



void kalibrering(){
	//Dreg motoren rundt intil at den rammer knappen.
}



void sen1(){
	timeSet[0] = millis();
	waiter = 1;
}
void sen2(){
	timeSet[1] = millis();
	waiter = 1;
}
void sen3(){
	timeSet[2] = millis();
	waiter = 1;
}

int whatCase(int checkSum){
	switch(checkSum){
	case 000 :	//NULL		//fejl
		return 0;
	case 001 :	//sen 3
		return 5;
	case 010 :	//sen 2
		return 3;
	case 011 :	//sen 2+3
		return 4;
	case 100 :	//sen 1
		return 1;
	case 101 :	//sen 1+3	//fejl
		return 0;
	case 110 :	//sen 1+2
		return 2;
	case 111 :	//sen 1+2+3	//fejl
		return 0;
	default:
		break;
	}
	return 0;
}

int checkTimeDif(){
	String checkSum = "";

	for(int i = 0; i < sizeof(timeSet); i++){
		if(timeSet[i] > millis()-ofsetTime){
			 checkSum += 1;
		}else{
			checkSum += 0;
		}
	}
	return checkSum.toInt();
}


void setup() {
	Serial.begin(9600);
	attachInterrupt(digitalPinToInterrupt(sen1Pin), sen1, RISING);
	attachInterrupt(digitalPinToInterrupt(sen2Pin), sen2, RISING);
	attachInterrupt(digitalPinToInterrupt(sen3Pin), sen3, RISING);

	kalibrering();

}

void loop() {
	int	bitArray;
	int senCase;
	int wantPos;

	while(waiter == 0);

	bitArray = checkTimeDif();
	senCase = whatCase(bitArray);
	if(senCase==0){
		Serial.println("ERROR senCase = 0");
		while(1);
	}
	wantPos = pirPos[senCase-1];

	move(wantPos);

}


