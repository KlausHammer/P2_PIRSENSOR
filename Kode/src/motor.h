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

const uint8_t encA = 18;
const uint8_t encB = 19;

const uint8_t motorPWM = 44;

const int minSpeed = 30;

const int Kp = 1;
const int Ki = 1;
const int Kd = 1;

extern void resetEncoder();

extern int pid(int error);

extern void move(int taks);

#endif /* SRC_MOTOR_H_ */
