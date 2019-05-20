#include "EITB225_PIRSensor_Arduino.h"


PirS pir(tacksPeRound);
Motor mot;
USBComm usb;
void manualRun(){
	detachInterrupt(digitalPinToInterrupt(sen1Pin));
	detachInterrupt(digitalPinToInterrupt(sen2Pin));
	detachInterrupt(digitalPinToInterrupt(sen3Pin));

	int targetTack = (usb.getTargetGrd()*encodeRatio)+mot.getEncVal();
	//Serial.println(targetTack);
	mot.move(targetTack);

	usb.usbKommunikationUdMan(pir.getRatio(), mot.getEncVal());

	attachInterrupt(digitalPinToInterrupt(sen1Pin), pir.sen1, RISING);
	attachInterrupt(digitalPinToInterrupt(sen2Pin), pir.sen2, RISING);
	attachInterrupt(digitalPinToInterrupt(sen3Pin), pir.sen3, RISING);

	pir.setWaiter(0);

}

void autoRun(){
	int senCase;
	int wantPos;
	int tmpCheckSum;

	delay(100);
//	Serial.println("Loop - after wait");

	pir.checkTimeDif();
	tmpCheckSum = pir.getCheckSum();

/*
	Serial.print("checkSum: ");
	Serial.println(tmpCheckSum);
*/
	pir.whatCase(tmpCheckSum);

	senCase = pir.getCase();

/*
	Serial.print("senCase: ");
	Serial.println(senCase);
*/
	if(senCase==0){
//		Serial.println("ERROR senCase = 0");
		digitalWrite(ledPin, HIGH);
		while(1);
	}

	wantPos = pir.getPos(senCase-1);
/*
	Serial.print("Target: ");
	Serial.println(pir.getPos(senCase-1));
*/

	mot.move(wantPos);

	usb.usbKommunikationUdAuto(senCase, pir.getRatio(), mot.getEncVal());

	pir.setWaiter(0);
}

void setup() {
	Serial.begin(9600);

//	Serial.println("System startup");

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



//	Serial.println("Loop - before wait");
	while(pir.getWaiter() == 0){
		pir.setWaiter(usb.usbKommunikationInd());
		delay(20);
	}

	if(pir.getWaiter() == 1){
		autoRun();
	}else if(pir.getWaiter() == 2){
		manualRun();
	}

}

