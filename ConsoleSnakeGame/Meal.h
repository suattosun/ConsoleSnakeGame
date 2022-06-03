#pragma once
#include"GameArea.h"
class Meal {
public:
	Meal();
	void CreateMeal();
	void CreateLoc();
	int RandomNumberGen();
	friend class Snake;
private:
	char mealShape = '$';
	int locX;
	int locY;

};