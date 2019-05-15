/*
 * motor.cpp
 *
 *  Created on: 14. maj 2019
 *      Author: NielsDyrberg
 */
#include "motor.h"

Encoder enc(encA, encB);

/*
 * Calibrates the system to know where the motor is.
 */
void kalibrering(){
	//Dreg motoren rundt intil at den rammer knappen.
	enc.write(1000);
	analogWrite(motorPWM, 100);
	while(enc.read() < 30);
	analogWrite(motorPWM, 0);
}

/*
 * Intterupt pin that resets encoder value.
 */
void resetEncoder(){
	enc.write(0);
}

/*
 * Calculates Correction value from target encoder value.
 * returns correction.
 */
int pid(
		int target /*Target encoder value*/
		){
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

int chooseDirection(
		int target /*Target encoder value*/
		){
	if(){

	}

	return 0;
}

/*
 * Moves the motor to the dessired encoder value.
 * as long, as correction is higher than minSpeed.
 */
void move(
		int target /*Target encoder value*/
		){
	int correction;
	int dirr;

	dirr = chooseDirection(target);

	while(correction != 0){
		correction = pid(target);
		if(correction > minSpeed){
			analogWrite(motorPWM, correction);
		}else{
			analogWrite(motorPWM, 0);
		}
	}
}
