/*
 * motor.cpp
 *
 *  Created on: 14. maj 2019
 *      Author: NielsDyrberg
 */
#include "motor.h"

Encoder myEnc(encA, encB);

int currPos = myEnc.read();

/*
 * Calibrates the system to know where the motor is.
 */
void kalibrering() {
	//Dreg motoren rundt intil at den rammer knappen.
	Serial.println("Kalibrering start");
	//myEnc.write(100000);
	digitalWrite(dir, HIGH);
	analogWrite(motorPWM, 20);
	/*
	 while (enc.read() > 30) {
	 delay(20);
	 }
	 */

	//delay(500);
}

/*
 * Intterupt pin that resets encoder value.
 */
void resetEncoder() {

	analogWrite(motorPWM, 0);
	Serial.println("Kalibrering slut");

	/*
	 int currentPos = enc.read();

	 //HERHEHREHRERH

	 while (currentPos < 0) {
	 currentPos = enc.read();
	 analogWrite(motorPWM, 20);

	 Serial.println("Drejer!");
	 Serial.println(currentPos);
	 }
	 while (currentPos > 0) {
	 currentPos = enc.read();

	 analogWrite(motorPWM, 20);
	 Serial.println(currentPos);
	 Serial.println("Drejer tilbage");

	 }
	 */

	delay(200);
	myEnc.write(0);
	delay(200);
	int currentPos = myEnc.read();

	Serial.println("Encoder position:");
	Serial.println(currentPos);
}

/*
 * Calculates Correction value from target encoder value.
 * returns correction.
 */
int pid(int target /*Target encoder value*/
) {
	int currPos = myEnc.read();

	int error = 0;
	//int integral = 0;
	//int derivative = 0;
	int correction = 0;
	//int lastError = 0;
	int e;
	//int i;
	//int d;

	error = target - currPos;

	/*	if (target < currPos){
	 digitalWrite(dir, LOW);
	 }
	 if (target > currPos){
	 digitalWrite(dir, HIGH);
	 }
	 */
	//integral = integral + error;
	//derivative = error - lastError;
	e = error * Kp;
	//i = integral * Ki;
	//d = derivative * Kd;
	correction = e;

	//Correction skal ligge mellem 0 og 255
	//Serial.print("Raw Correction: ");
	Serial.println(correction);

	correction = correction * (30 / (tacksPeRound / 2));

	return correction;
}

int chooseDirection(int target /*Target encoder value*/
) {
	//int currPos = enc.read();

	Serial.print("Current pos: ");
	Serial.println(currPos);

	if (currPos > target) {
		digitalWrite(dir, LOW);
	} else if (currPos < target) {
		digitalWrite(dir, HIGH);
	}

	return 0;
}

/*
 * Moves the motor to the dessired encoder value.
 * as long, as correction is higher than minSpeed.
 */
void move(int target /*Target encoder value*/
) {
	int correction;

	int dirr = 0;
	int currentPos = myEnc.read();

	//correction = pid(target);

	if (currentPos != target) {
		dirr = chooseDirection(target);

		//Serial.println("Correction loop");
		//correction = pid(target);
		//Serial.print("Not Raw Correction: ");
		//Serial.println("Current correction:");
		//Serial.println(correction);
		Serial.println("Current position:");
		Serial.println(currentPos);
		delay(1000);
		currentPos = myEnc.read();
		analogWrite(motorPWM, 0);

		while (currentPos > target) {
			currentPos = myEnc.read();
			analogWrite(motorPWM, 20);
			Serial.println("Drejer!");
			delay(10);
			Serial.println("Current target:");
			Serial.println(target);
			Serial.println("Current position:");
			Serial.println(currentPos);
			currentPos = myEnc.read();
			Serial.print("ENCODER READ:");
			Serial.print(currentPos);
			delay(100);

		}
		analogWrite(motorPWM, 0);

		while (currentPos < target) {
			currentPos = myEnc.read();
			digitalWrite(dir, HIGH);
			delay(100);
			Serial.println("Drejer tilbage");
			analogWrite(motorPWM, 20);
			Serial.println(currentPos);
			Serial.println("Current target:");
			Serial.println(target);
			Serial.println("Current position:");
			Serial.println(currentPos);
			currentPos = myEnc.read();
			Serial.print("ENCODER READ:");
			Serial.print(currentPos);
			delay(10);
		}
		delay(5);
		analogWrite(motorPWM, 0);

		//delay(500);
	}

}
