/*
 * motor.cpp
 *
 *  Created on: 14. maj 2019
 *      Author: NielsDyrberg
 */
#include "Motor.h"

Encoder enc(encA, encB);

Motor::Motor() {
	// TODO Auto-generated constructor stub

	tack = 0;
}

Motor::~Motor() {
	// TODO Auto-generated destructor stub
}


/*
 * Calibrates the system to know where the motor is.
 */
void Motor::kalibrering() {
	//Dreg motoren rundt intil at den rammer knappen.
//	Serial.println("Kalibrering start");
	enc.write(100000);
	digitalWrite(dirPin, HIGH);
	analogWrite(motorPWM, minSpeed);

	while (enc.read() > 200) {
	delay(20);
	}
	analogWrite(motorPWM, 0);

	delay(150);

	tack = enc.read();
	detachInterrupt(digitalPinToInterrupt(resetPin));
	/*
	Serial.print("Curr pos: ");
	Serial.println(enc.read());
	Serial.println("Kalibrering slut.");
	*/
	//delay(500);
}

/*
 * Intterupt pin that resets encoder value.
 */
void Motor::resetEncoder(){


	enc.write(0);
//	Serial.println("EN RE");


	/*
	if(millis() > testTime+50){
		testTime = millis();
		Serial.print(enc.read());
		enc.write(0);
		Serial.println(","+(String)i+";");
		i++;
	}
	digitalWrite(dirPin, HIGH);
	analogWrite(motorPWM, 50);
	*/
}

/*
 * Calculates Correction value from target encoder value.
 * returns correction.
 */
int Motor::pid(
		int target /*Target encoder value.*/
		){
	int currPos = enc.read();

	float error = 0.00;
	int correction = 0;

	float e = 0.00;

	error = target - currPos;


	e = error * Kp;

  	correction = e;

  	lastError = error;

	return correction;
}

int chooseDirection(
		int target /*Target encoder value*/
		){

	int currPos = enc.read();

/*
	Serial.print("Encode value: ");
	Serial.print(currPos);
	Serial.print(" : ");
	Serial.println(enc.read());
*/
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
void Motor::move(
		int target /*Target encoder value*/
) {
	int rawCorrection = 0;
	int correction = 0;

	int dirr = 0;
	int currPos = enc.read();

	dirr = chooseDirection(target);
	rawCorrection = pid(target);

	/*
	Serial.print("Direction: ");
	Serial.println(dirr);
	Serial.print("RawCorrection: ");
	Serial.println(rawCorrection);
	Serial.print("Encode value: ");
	Serial.println(enc.read());
	Serial.print("Abs Corr: ");
	Serial.println(abs(rawCorrection));
*/
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
	/*
	Serial.println("Præcis kørsel");
*/

	while(abs(rawCorrection) > 4){
		dirr = chooseDirection(target);

		analogWrite(motorPWM, minSpeed);
		delay(25);

		analogWrite(motorPWM, 0);

		delay(100);

		rawCorrection = pid(target);
	}
/*
	Serial.println("Sluk motor ");
	Serial.print("Encode value: ");
	Serial.println(enc.read());
*/
	analogWrite(motorPWM, 0);
	tack = enc.read();
	integral = 0;

}

