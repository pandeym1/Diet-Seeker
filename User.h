#pragma once
class User
{ //need to add activity level to calculation
private:
	float maxCarbs;
	float maxProt;
	float maxFat;
	int age;
	int activityLevel;

	float weight;
	float height;
	float BMR;
public:
	float calculateBMR(int AGE, int actLev, float WEIGHT, float HEIGHT);
	float giveMaxCarb();
	float giveMaxProt();
	float giveMaxFat();
	User(int AGE, int actLev, float WEIGHT, float HEIGHT) {
		this->age = AGE;
		this->activityLevel = actLev;
		this->weight = WEIGHT;
		this->height = HEIGHT;
		this->BMR = calculateBMR(this->age, this->activityLevel, this->weight, this->height);

		this->maxCarbs = (this->BMR) * 0.4f;
		this->maxProt = (this->BMR) * 0.4f;
		this->maxFat = (this->BMR) * 0.2f;
	}
};

