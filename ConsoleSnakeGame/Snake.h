#pragma once
#include"GameArea.h"
#include"Meal.h"
#include<vector>
class Snake {
public:

	Snake();
	void KeyboardInput();
	void SnakeMove();
	void BorderEffect();
	void SnakeLocCal(char);
	void SnakeLocDelete();
	void IsSnakeEatMeal();
	bool snakeCantTurnBack(int, int);
	void SnakeSpeed();
	bool isDead();
private:
	int dirX{};
	int dirY{};
	bool isGameStart = false;
	int speed{ 3 };
	int speedInit{};
	int snakeMealCount{ 1 };
	int snakePosDir{ 1 };
	int snakeNegDir{ -1 };
	int snakeNotMove{ };
	int snakeHeadX;
	int snakeHeadY;
	inline static std::vector<char> SnakeLocX;
	inline static std::vector<char> SnakeLocY;
	char snakeChar = '*';
	char blankChar = ' ';

	Meal mmeal;
};