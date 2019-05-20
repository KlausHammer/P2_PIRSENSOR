/*
 * USBComm.cpp
 *
 *  Created on: 14. maj 2019
 *      Author: knham
 */
#include "USBComm.h";


String samlString(){
	String dataString = "";
	String tmpString = "";

	dataString = "-Grader ";
	dataString += (String)encVal();
	dataString += "-Sensor1 ";
	dataString += "-Sensor1 ";
	dataString += "-Sensor2 ";
	dataString += "-Sensor1 ";
	dataString += "-Sensor3 ";
	dataString += "-Sensor1 ";


	return "0";
}

void usbKommunikationUd(){
	samlString();
}

void usbKommunikationInd(){

}

