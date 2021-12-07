#pragma once
class User
{ //need to add activity level to calculation
private:
	int maxCarbs;
	int maxProt;
	int maxFat;
	int age;

	float weight;
	float height;
public:
	float calculateBMR(int AGE, float WEIGHT, float HEIGHT);
};

