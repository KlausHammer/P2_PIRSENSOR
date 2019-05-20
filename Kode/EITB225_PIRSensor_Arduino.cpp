#include "EITB225_PIRSensor_Arduino.h"

int waiter = 0;


void setup() {
	Serial.begin(9600);
	Serial.println("System startup");

	pinMode(resetPin, INPUT_PULLUP);
	pinMode(dirPin, OUTPUT);
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);

	attachInterrupt(digitalPinToInterrupt(sen1Pin), sen1, RISING);
	attachInterrupt(digitalPinToInterrupt(sen2Pin), sen2, RISING);
	attachInterrupt(digitalPinToInterrupt(sen3Pin), sen3, RISING);

	attachInterrupt(digitalPinToInterrupt(resetPin), resetEncoder, FALLING);


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
	delay(100);
	Serial.println("Loop - after wait");

	bitArray = checkTimeDif();
	senCase = whatCase(bitArray);
	if(senCase==0){
		Serial.println("ERROR senCase = 0");
		digitalWrite(ledPin, HIGH);
		while(1);
	}

	wantPos = pirPos[senCase-1];

	Serial.print("Target: ");
	Serial.println(wantPos);


	move(wantPos);

	usbKommunikationUd(senCase);

	waiter=0;

}

