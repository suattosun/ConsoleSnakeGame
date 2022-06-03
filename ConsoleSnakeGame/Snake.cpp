#include"Snake.h"
#include<iostream>
#include<Windows.h>
Snake::Snake() :snakeHeadX{ GameArea::msize / 2 }, snakeHeadY{ GameArea::msize / 2 }{
	SnakeLocX.push_back(snakeHeadX);
	SnakeLocY.push_back(snakeHeadY);
	SnakeLocX.push_back(snakeHeadX + 1);
	SnakeLocY.push_back(snakeHeadY);
	SnakeLocCal(snakeChar);
	dirX = -1;
}

void Snake::SnakeLocCal(char snakeShape) {
	for (size_t index{ }; index < SnakeLocX.size(); index++)
		GameArea::m_array[SnakeLocY.at(index)][SnakeLocX.at(index)] = snakeShape;
}
void Snake::SnakeSpeed() {
	speedInit++;
	if (speedInit > speed) {
		snakeHeadX += dirX;
		snakeHeadY += dirY;
		BorderEffect();
		SnakeLocDelete();
		speedInit = 0;
	}
}
bool Snake::isDead() {
	if (GameArea::m_array[snakeHeadY + dirY][snakeHeadX + dirX] == snakeChar) {
		return true;
	}
	return false;
}
void Snake::KeyboardInput() {


	if ((GetKeyState('W') & 0x8000) && snakeCantTurnBack(snakeNotMove, snakeNegDir)) {
		dirX = snakeNotMove;
		dirY = snakeNegDir;

	}
	else if ((GetKeyState('S') & 0x8000) && snakeCantTurnBack(snakeNotMove, snakePosDir)) {
		dirX = snakeNotMove;
		dirY = snakePosDir;
	}
	else if ((GetKeyState('A') & 0x8000) && snakeCantTurnBack(snakeNegDir, snakeNotMove)) {
		dirX = snakeNegDir;
		dirY = snakeNotMove;

	}
	else if ((GetKeyState('D') & 0x8000) && snakeCantTurnBack(snakePosDir, snakeNotMove)) {
		dirX = snakePosDir;
		dirY = snakeNotMove;
	}
}
bool Snake::snakeCantTurnBack(int _dirX, int _dirY) {
	if ((snakeHeadY + _dirY != SnakeLocY.at(SnakeLocY.size() - 2)) && (snakeHeadX + _dirX != SnakeLocX.at(SnakeLocX.size() - 2))) {
		return true;
	}
	return false;
}
void Snake::IsSnakeEatMeal() {
	if ((snakeHeadX == mmeal.locX) && (snakeHeadY == mmeal.locY)) {
		GameArea::scoreCount = snakeMealCount++;
		SnakeLocX.push_back(snakeHeadX - (dirX));
		SnakeLocY.push_back(snakeHeadY - (dirY));
		mmeal.CreateMeal();
	}
}
void Snake::SnakeLocDelete() {

	SnakeLocX.erase(SnakeLocX.begin());
	SnakeLocY.erase(SnakeLocY.begin());
	SnakeLocX.push_back(snakeHeadX);
	SnakeLocY.push_back(snakeHeadY);


}
void Snake::BorderEffect() {
	if (snakeHeadX < GameArea::leftGameAreaBorder)
		snakeHeadX = GameArea::msize - GameArea::rightGameAreaBorder;
	else if (snakeHeadX > GameArea::msize - GameArea::rightGameAreaBorder)
		snakeHeadX = GameArea::leftGameAreaBorder;
	else if (snakeHeadY < GameArea::leftGameAreaBorder)
		snakeHeadY = GameArea::msize - GameArea::rightGameAreaBorder;
	else if (snakeHeadY > GameArea::msize - GameArea::rightGameAreaBorder)
		snakeHeadY = GameArea::leftGameAreaBorder;
}
void Snake::SnakeMove() {
	mmeal.CreateLoc();
	SnakeLocCal(blankChar);
	SnakeSpeed();
	KeyboardInput();
	IsSnakeEatMeal();
	SnakeLocCal(snakeChar);

}