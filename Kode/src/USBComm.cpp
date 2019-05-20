/*
 * USBComm.cpp
 *
 *  Created on: 14. maj 2019
 *      Author: knham
 */
#include "USBComm.h";

String senString(int senCase){
	String tmpString = "";

	switch(senCase){
	case 0 :
		tmpString = "";
		return 0;
	case 1 :	//sen 3
		tmpString = "-Sensor1 OFF -Sensor2 OFF -Sensor3 ON";
		return 5;
	case 2 :	//sen 2
		tmpString = "-Sensor1 OFF -Sensor2 ON -Sensor3 OFF";
		return 3;
	case 3 :	//sen 2+3
		tmpString = "-Sensor1 OFF -Sensor2 ON -Sensor3 ON";
		return 4;
	case 4 :	//sen 1
		tmpString = "-Sensor1 ON -Sensor2 OFF -Sensor3 OFF";
		return 1;
	case 5 :	//sen 1+3	//fejl
		tmpString = "";
		return 0;
	default:
		break;
	}

	return tmpString;
}

String samlString(int senCase){
	String dataString = "";
	String tmpString = "";

	dataString = "-Grader ";
	dataString += (String)encVal();
	dataString += senString(senCase);



	return "0";
}

void usbKommunikationUd(){
	//samlString();
}

void usbKommunikationInd(){

}

