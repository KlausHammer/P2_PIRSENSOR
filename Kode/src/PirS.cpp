/*
 * PirS.cpp
 *
 *  Created on: 20. maj 2019
 *      Author: NielsDyrberg
 */

#include "PirS.h"

int PirS::waiter = 0;
unsigned long PirS::timeSet[3] = {
		0,
		0,
		0
};

int PirS::pirPos[5] = {
		50.00,
		75.00,
		100.00,
		125.00,
		150.00
	};


PirS::PirS(float tacks) {
	// TODO Auto-generated constructor stub
	encodeRatio = tacks/360;
	caseNr = 0;

	for(int i = 0; i < (sizeof(pirPos) / sizeof(pirPos[0])); i++){
		pirPos[i] = pirPos[i]*encodeRatio;
	}



}

PirS::~PirS() {
	// TODO Auto-generated destructor stub
}

void PirS::setWaiter(int x){
	waiter = x;
}

void PirS::pirGrd(int taks){
	tmpGrd = taks/encodeRatio;
}

void PirS::sen1(){
	timeSet[0] = millis();
	waiter = 1;
	Serial.println("1");

}
void PirS::sen2(){
	timeSet[1] = millis();
	Serial.println("2");
	waiter = 1;

}
void PirS::sen3(){
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
void PirS::whatCase(int checkSum){
	switch(checkSum){
	case 0 :	//NULL		//fejl
		caseNr = 0;
		break;
	case 1 :	//sen 3
		caseNr = 5;
		break;
	case 10 :	//sen 2
		caseNr = 3;
		break;
	case 11 :	//sen 2+3
		caseNr = 4;
		break;
	case 100 :	//sen 1
		caseNr = 1;
		break;
	case 101 :	//sen 1+3	//fejl
		caseNr = 0;
		break;
	case 110 :	//sen 1+2
		caseNr = 2;
		break;
	case 111 :	//sen 1+2+3	//fejl
		caseNr = 0;
		break;
	default:
		break;
	}
}

/*
 * Checks the time defference between current time,
 * to note which sensors has been activated whitin
 * the ofsetTime.
 * Returns a bit array, as an int.
 */
void PirS::checkTimeDif(){
	checkSum = "";
	for(int i = 0; i < (sizeof(timeSet) / sizeof(timeSet[0])); i++){
		if(timeSet[i] > millis()-ofsetTime){
			 checkSum += 1;
		}else{
			checkSum += 0;
		}
	}
	Serial.print("checkTimeDif() :");
	Serial.print(checkSum);
	Serial.print(" : ");
	Serial.println(checkSum.toInt());
}
