#include<string>
#include<vector>
#include"GameArea.h"
#include"Snake.h"
#include<Windows.h>
#include"Meal.h"
void hide_cursor() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // top left corner of the screen
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(h, &ConCurInf);
}
void clear_screen() {
	COORD coord = { 0 };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}
int main() {

	GameArea gm;
	Snake sx;
	gm.PrintGameArea();
	hide_cursor();
	while (true)
	{
		sx.SnakeMove();
		gm.PrintGameArea();
		if (sx.isDead()) {
			break;
		}
		clear_screen();
	}
	std::cout << "GAME OVER" << "\n";
}