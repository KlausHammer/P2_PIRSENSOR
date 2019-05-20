#include "EITB225_PIRSensor_Arduino.h"


PirS pir(tacksPeRound);
Motor mot;

void setup() {
	Serial.begin(9600);
	Serial.println("System startup");

	pinMode(resetPin, INPUT_PULLUP);
	pinMode(dirPin, OUTPUT);
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);

	attachInterrupt(digitalPinToInterrupt(sen1Pin), pir.sen1, RISING);
	attachInterrupt(digitalPinToInterrupt(sen2Pin), pir.sen2, RISING);
	attachInterrupt(digitalPinToInterrupt(sen3Pin), pir.sen3, RISING);

	attachInterrupt(digitalPinToInterrupt(resetPin), mot.resetEncoder, FALLING);



	mot.kalibrering();

}

void loop() {

	int senCase;
	int wantPos;
	int tmpCheckSum;

	Serial.println("Loop - before wait");
	while(pir.getWaiter() == 0){
		//Serial.println("Loop - in wait");
		delay(20);
	}
	delay(100);
	Serial.println("Loop - after wait");

	pir.checkTimeDif();
	tmpCheckSum = pir.getCheckSum();

	Serial.print("checkSum: ");
	Serial.println(tmpCheckSum);

	pir.whatCase(tmpCheckSum);

	senCase = pir.getCase();

	Serial.print("senCase: ");
	Serial.println(senCase);

	if(senCase==0){
		Serial.println("ERROR senCase = 0");
		digitalWrite(ledPin, HIGH);
		while(1);
	}

	wantPos = pir.getPos(senCase-1);

	Serial.print("Target: ");
	Serial.println(pir.getPos(senCase-1));


	mot.move(wantPos);

	//usbKommunikationUd(senCase);

	pir.setWaiter(0);

}

