/**
* @file min_max.cpp
* @author Cameron A. Craig
* @copyright 2020 Cameron A. Craig
* @brief Min and max functions
*/

#include "min_max.h"

int ucm::min(int x, int y) {
	if (x > y) {
		return y;
	}
	return x;
}

int ucm::max(int x, int y) {
	if (x > y) {
		return x;
	}
	return y;
}

float ucm::min(float x, float y) {
	if (x > y) {
		return y;
	}
	return x;
}

float ucm::max(float x, float y) {
	if (x > y) {
		return x;
	}
	return y;
}
