/*
 * USBComm.cpp
 *
 *  Created on: 14. maj 2019
 *      Author: knham
 */
#include "USBComm.h";

USBComm::USBComm() {
	// TODO Auto-generated constructor stub
	dataString = "";
	tmpDataString = "";
	modData = "";
	targetGrd = 0;
}

USBComm::~USBComm() {
	// TODO Auto-generated destructor stub
}

void USBComm::senString(int senCase){
	switch(senCase){
	case 0 : 	//sen 1+3 	//FEJL
		tmpDataString = "";
		break;
	case 1 :	//sen 3
		tmpDataString = " -Sensor1 ON -Sensor2 OFF -Sensor3 OFF";
		break;
	case 2 :	//sen 2
		tmpDataString = " -Sensor1 ON -Sensor2 ON -Sensor3 OFF";
		break;
	case 3 :	//sen 2+3
		tmpDataString = " -Sensor1 OFF -Sensor2 ON -Sensor3 OFF";
		break;
	case 4 :	//sen 1
		tmpDataString = " -Sensor1 OFF -Sensor2 ON -Sensor3 ON";
		break;
	case 5 :	//sen 3
		tmpDataString = " -Sensor1 OFF -Sensor2 OFF -Sensor3 ON";
		break;
	default:
		break;
	}

}

void USBComm::samlString(int senCase, float ratio, int tack){
	dataString = "-Grader ";
	int deg = tack/ratio;
	dataString += (String)deg;
	dataString += tmpDataString;
}

void USBComm::usbKommunikationUdAuto(int senCase, float ratio, int tack){
	senString(senCase);
	samlString(senCase, ratio, tack);

	Serial.println(dataString);
}

void USBComm::usbKommunikationUdMan(float ratio, int tack){
	dataString = "-Grader ";
	int deg = tack/ratio;
	dataString += (String)deg;

	Serial.println(dataString);
}

int USBComm::usbKommunikationInd(){
	// send data only when you receive data:
	if (Serial.available() > 0) {

		// read the incoming byte:
		modData = Serial.readString();

		// say what you got:
		//Serial.print("I received: ");
		//Serial.println(modData);

		if(modData.indexOf("-grader") != -1	){
			int strPos;
			String tmpGrd = "";
			strPos = modData.indexOf("-grader") + 8;

			while(modData[strPos] != ' '){
				tmpGrd += modData[strPos];
				strPos++;
			}
			targetGrd = tmpGrd.toInt();
		}
		return 2;
	}

	return 0;
}

