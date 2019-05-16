#include "EITB225_PIRSensor_Arduino.h"

int waiter = 0;
unsigned long ofsetTime = 500;


int pirPos[] = {
		50.00*encodeRatio,
		75.00*encodeRatio,
		100.00*encodeRatio,
		125.00*encodeRatio,
		150.00*encodeRatio
};

unsigned long timeSet[] = {
		0,
		0,
		0
};

void sen1(){
	timeSet[0] = millis();
	waiter = 1;
	Serial.println("1");

}
void sen2(){
	timeSet[1] = millis();
	Serial.println("2");
	waiter = 1;

}
void sen3(){
	timeSet[2] = millis();
	Serial.println("3");
	waiter = 1;
}

/*
 * Takes an int as input, then from the int
 * determens which combination of sensors that is in use.
 * Returns an int from 1-x or 0
 * where x is the number of combinations.
 * If it returns 0, there is an error.
 */
int whatCase(int checkSum){
	switch(checkSum){
	case 000 :	//NULL		//fejl
		return 0;
	case 1 :	//sen 3
		return 5;
	case 10 :	//sen 2
		return 3;
	case 11 :	//sen 2+3
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

/*
 * Checks the time defference between current time,
 * to note which sensors has been activated whitin
 * the ofsetTime.
 * Returns a bit array, as an int.
 */
int checkTimeDif(){
	String checkSum = "";
	for(int i = 0; i < (sizeof(timeSet) / sizeof(timeSet[0])); i++){
		if(timeSet[i] > millis()-ofsetTime){
			 checkSum += 1;
		}else{
			checkSum += 0;
		}
	}
	Serial.println(checkSum);
	Serial.println(checkSum.toInt());
	return checkSum.toInt();
}


void setup() {
	Serial.begin(9600);
	Serial.println("System startup");
	attachInterrupt(digitalPinToInterrupt(sen1Pin), sen1, RISING);
	attachInterrupt(digitalPinToInterrupt(sen2Pin), sen2, RISING);
	attachInterrupt(digitalPinToInterrupt(sen3Pin), sen3, RISING);

	attachInterrupt(digitalPinToInterrupt(resetPin), resetEncoder, FALLING);

	pinMode(dirPin, OUTPUT);
	kalibrering();
}

void loop() {
	int	bitArray;
	int senCase;
	int wantPos;
	Serial.println("Loop - before wait");
	while(waiter == 0){
		//Serial.println("Loop - in wait");
		delay(20);
	}
	Serial.println("Loop - after wait");

	bitArray = checkTimeDif();
	senCase = whatCase(bitArray);
	if(senCase==0){
		Serial.println("ERROR senCase = 0");
		while(1);
	}

	wantPos = pirPos[senCase-1];

	Serial.print("Target: ");
	Serial.println(wantPos);


	move(wantPos);

	waiter=0;
}

