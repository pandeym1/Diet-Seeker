#include "User.h"

float User::calculateBMR(int AGE, float WEIGHT, float HEIGHT) {
	float BMR = 655.0f + (4.35f * (float)WEIGHT) + (4.7f * (float)HEIGHT) - (4.7f * (float)AGE);
	return BMR;
}