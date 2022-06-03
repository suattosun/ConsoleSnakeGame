#pragma once
#include<iostream>

class GameArea {
public:
	GameArea();
	void PrintGameArea();
	friend class Snake;
	friend class Meal;
private:
	static const int msize = 26;
	inline static char m_array[msize][msize];
	static const int leftGameAreaBorder = 1;
	static const int rightGameAreaBorder = 2;
	inline static int scoreCount{ };
};

