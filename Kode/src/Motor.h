
/*
 * motor.h
 *
 *  Created on: 14. maj 2019
 *      Author: NielsDyrberg
 */

#ifndef SRC_MOTOR_H_
#define SRC_MOTOR_H_

#include <Arduino.h>
#include "../EITB225_PIRSensor_Arduino.h"
#include "../lib/encoder/Encoder.h"



class Motor{

private:
	const int maxSpeed = 100;
	const int minSpeed = 20;

	const float Kp = 1.00;
	const float Ki = 0.001;
	const float Kd = 1.00;

	int tack;

	int pid(int error);

public:
	void kalibrering();
	static void resetEncoder();
	void move(int taks);

	int getEncVal(){ return tack; }
};




#endif /* SRC_MOTOR_H_ */
