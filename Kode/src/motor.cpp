/*
 * motor.cpp
 *
 *  Created on: 14. maj 2019
 *      Author: NielsDyrberg
 */
#include "motor.h"

Encoder enc(encA, encB);

float integral = 0.00;
int lastError = 0;

/*
 * Calibrates the system to know where the motor is.
 */
void kalibrering() {
	//Dreg motoren rundt intil at den rammer knappen.
	Serial.println("Kalibrering start");
	enc.write(100000);
	digitalWrite(dirPin, HIGH);
	analogWrite(motorPWM, maxSpeed);

	while (enc.read() > 100) {
	delay(20);
	}
	analogWrite(motorPWM, 0);

	Serial.println("Kalibrering slut");
	//delay(500);
}

/*
 * Intterupt pin that resets encoder value.
 */
void resetEncoder(){
	enc.write(0);
	Serial.println("Encode reset");
}

/*
 * Calculates Correction value from target encoder value.
 * returns correction.
 */
int pid(
		int target /*Target encoder value*/
		){
	int currPos = enc.read();

	float error = 0.00;
	float derivative = 0;
	int correction = 0;

	float e = 0.00;
	float i = 0.00;
	float d;

	error = target - currPos;

	integral = integral + error;
	derivative = error - lastError;

	e = error * Kp;
	i = integral * Ki;
  	d = derivative * Kd;
  	correction = e + i;

  	lastError = error;

	return correction;
}

int chooseDirection(
		int target /*Target encoder value*/
		){

	int currPos = enc.read();
	Serial.print("Encode value: ");
	Serial.print(currPos);
	Serial.print(" : ");
	Serial.println(enc.read());

	if (currPos > target) {
		digitalWrite(dirPin, LOW);
		return 0;
	} else if (currPos < target) {
		digitalWrite(dirPin, HIGH);
		return 1;
	}

	return 3;
}

/*
 * Moves the motor to the dessired encoder value.
 * as long, as correction is higher than minSpeed.
 */
void move(
		int target /*Target encoder value*/
) {
	int rawCorrection = 0;
	int correction = 0;

	int dirr = 0;
	int currPos = enc.read();

	dirr = chooseDirection(target);
	rawCorrection = pid(target);

	Serial.print("Direction: ");
	Serial.println(dirr);
	Serial.print("RawCorrection: ");
	Serial.println(rawCorrection);
	Serial.print("Encode value: ");
	Serial.println(enc.read());
	Serial.print("Abs Corr: ");
	Serial.println(abs(rawCorrection));

	while(abs(rawCorrection) > 15){
		dirr = chooseDirection(target);
		rawCorrection = pid(target);

		//Correction skal ligge mellem 0 og 100
		correction = rawCorrection * (maxSpeed/(tacksPeRound/2));
		if(correction < minSpeed){
			correction = minSpeed;
		}

		dirr = chooseDirection(target);
		rawCorrection = pid(target);

		analogWrite(motorPWM, abs(correction));
	}

	analogWrite(motorPWM, 0);
	delay(50);
	rawCorrection = pid(target);
	Serial.println("Præcis kørsel");


	while(abs(rawCorrection) > 4){
		dirr = chooseDirection(target);

		analogWrite(motorPWM, minSpeed);
		delay(30);

		analogWrite(motorPWM, 0);

		delay(70);

		rawCorrection = pid(target);
	}

	Serial.println("Sluk motor");
	Serial.print("Encode value: ");
	Serial.println(enc.read());
	analogWrite(motorPWM, 0);
	integral = 0;

}
