/*
 * PirS.h
 *
 *  Created on: 20. maj 2019
 *      Author: NielsDyrberg
 */

#ifndef PIRS_H_
#define PIRS_H_

#include <Arduino.h>
#include "../EITB225_PIRSensor_Arduino.h"

class PirS {
private:
	static int waiter;
	static unsigned long timeSet[3];
	static int pirPos[5];

	unsigned long ofsetTime = 500;
	float encodeRatio;
	float tmpGrd = 0.00;

	int caseNr;
	String checkSum;
public:
	PirS(float encodeRatio);
	virtual ~PirS();

	void setWaiter(int x);

	void pirGrd(int taks);
	static void sen1();
	static void sen2();
	static void sen3();

	void whatCase(int checkSum);
	void checkTimeDif();

	float getTmpGrd(){return tmpGrd;}
	int getCase(){ return caseNr; }
	int getCheckSum(){ return checkSum.toInt(); }
	int getPos(int x){ return pirPos[x]; }
	int getWaiter(){ return waiter; }
};

#endif /* PIRS_H_ */
