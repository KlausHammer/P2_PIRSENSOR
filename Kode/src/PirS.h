/*
 * PirS.h
 *
 *  Created on: 20. maj 2019
 *      Author: NielsDyrberg
 */

#ifndef PIRS_H_
#define PIRS_H_

#include <Arduino.h>
#

class PirS {
private:
	int *waiter;
	unsigned long ofsetTime = 500;
	float encodeRatio = 1.00;
	float tmpGrd = 0.00;
	int pirPos[] = {
			50.00*encodeRatio,
			75.00*encodeRatio,
			100.00*encodeRatio,
			125.00*encodeRatio,
			150.00*encodeRatio
	};
	int caseNr;

public:
	PirS(int *waiter);
	virtual ~PirS();

	void pirGrd(int taks){ };

	void sen1();
	void sen2();
	void sen3();

	void whatCase(int checkSum);

	float getTmpGrd(){return tmpGrd;};
	int getCase(){ return caseNr; }
};

#endif /* PIRS_H_ */



class PirS2{
private:

	uint8_t sen1Pin; 	// = 2;
	uint8_t sen2Pin; 	// = 3;
	uint8_t sen3Pin; 	// = 21;
	uint8_t ledPin; 	// = 6;
	uint8_t resetPin;	// = 20;

	const float tacksPeRound = 1496.00;
	const float encodeRatio = tacksPeRound/360;

public:
	PirS();

	float pirGrd(float taks);

};
