#ifndef _COMMON_H_
#define _COMMON_H_

#include "Constants.h"

int threshold(int aNumber, int threshold = 20);

int confineToRange(int value, int min = -KMaxMotorSpeed, int max = KMaxMotorSpeed);

bool inRange(int value, int min = -KMaxMotorSpeed, int max = KMaxMotorSpeed);

int sign(int aNumber);

#endif // _COMMON_H_
