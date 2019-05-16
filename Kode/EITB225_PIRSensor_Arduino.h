/*
 * EITB225_PIRSensor_Arduino.h
 *
 *  Created on: 14. maj 2019
 *      Author: NielsDyrberg
 */

#ifndef EITB225_PIRSENSOR_ARDUINO_H_
#define EITB225_PIRSENSOR_ARDUINO_H_

#include <Arduino.h>
#include "src/motor.h"

const uint8_t sen1Pin = 2;
const uint8_t sen2Pin = 3;
const uint8_t sen3Pin = 21;

const uint8_t resetPin = 20;


const float tacksPeRound = 1496.00;
const float encodeRatio = tacksPeRound/360;


#endif /* EITB225_PIRSENSOR_ARDUINO_H_ */
