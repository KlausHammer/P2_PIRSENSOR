/*
 * USBComm.h
 *
 *  Created on: 20. maj 2019
 *      Author: NielsDyrberg
 */

#ifndef SRC_USBCOMM_H_
#define SRC_USBCOMM_H_

#include <Arduino.h>
#include "../EITB225_PIRSensor_Arduino.h"

class USBComm{

private:
	String dataString;
	String tmpDataString;
	String modData;
	int targetGrd;

	void senString(int senCase);
	void samlString(int senCase, float ratio, int tack);

public:
	USBComm();
	virtual ~USBComm();

	void usbKommunikationUdAuto(int senCase, float ratio, int tack);
	void usbKommunikationUdMan(float ratio, int tack);
	int usbKommunikationInd();
	int getTargetGrd(){ return targetGrd; }
};




#endif /* SRC_USBCOMM_H_ */
