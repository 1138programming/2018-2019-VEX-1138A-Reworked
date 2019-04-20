#include "main.h"
#include "common.h"

int threshold(int aNumber, int threshold) {
	return (abs(aNumber) >= threshold) ? aNumber : 0;
}

int reverseThreshold(int aNumber, int threshold) {
	return (abs(aNumber) >= threshold) ? aNumber : threshold;
}

// DO NOT USE! Create pin objects in subsystems
bool getLimitSwitch(unsigned char pin) {
	bool returnValue = false;
	pros::ADIDigitalIn* limitSwitch = new pros::ADIDigitalIn(pin);
	returnValue = limitSwitch->get_value();
	delete limitSwitch; // Fix memory leak
	return returnValue;
}

int confineToRange(int value, int max) {
	if (value >= abs(max))
		return abs(max);
	else if (value <= -abs(max))
		return -abs(max);
	else
		return value;
}

int confineToRange(int value, int min, int max) {
	if (min > max) return confineToRange(value, max, min);
	if (value < min)
		return min;
	else if (value > max)
		return max;
	return value;
}

bool inRange(int value, int min, int max) {
	return min <= value && value <= max;
}

int sign(int aNumber) {
	if (aNumber == 0) return 0;
	return aNumber/abs(aNumber);
}
