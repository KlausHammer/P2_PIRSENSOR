/*
 * motor.cpp
 *
 *  Created on: 14. maj 2019
 *      Author: NielsDyrberg
 */
#include "motor.h"



Encoder enc(encA, encB);


int pid(int target){
	int currPos = enc.read();

	int error = 0;
	int integral = 0;
	int derivative = 0;
	int correction = 0;
	int lastError = 0;
	int e;
	int i;
	int d;

	error = target - currPos;
	integral = integral + error;
	derivative = error - lastError;

	e = error * Kp;
	i = integral * Ki;
  	d = derivative * Kd;
  	correction = e + i + d;

  	//Correction skal ligge mellem 0 og 100
  	correction = correction * (100/(tacksPeRound/2));

	return correction;
}

void move(int target){
	int correction;

	correction = pid(target);

	if(correction > minSpeed){
		analogWrite(motorPWM, correction);
	}else{
		analogWrite(motorPWM, 0);
	}
}
