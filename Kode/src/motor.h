<<<<<<< HEAD
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

const uint8_t encA = 19;
const uint8_t encB = 18;
const uint8_t dirPin = 7;

const uint8_t motorPWM = 44;
const int maxSpeed = 100;
const int minSpeed = 17;

const float Kp = 1.00;
const float Ki = 0.001;
const float Kd = 1.00;

extern int encVal();
extern void kalibrering();
extern void resetEncoder();
extern int pid(int error);
extern void move(int taks);


#endif /* SRC_MOTOR_H_ */
=======
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
const uint8_t dirPin = 7;

const uint8_t motorPWM = 44;
const int maxSpeed = 100;
const int minSpeed = 20;

const float Kp = 1.00;
const float Ki = 0.001;
const float Kd = 1.00;

extern void kalibrering();
extern void resetEncoder();
extern int pid(int error);
extern void move(int taks);


#endif /* SRC_MOTOR_H_ */
>>>>>>> refs/remotes/origin/master
