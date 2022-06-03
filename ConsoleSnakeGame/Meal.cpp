#include"Meal.h"
#include <Random>

Meal::Meal() :locX{ RandomNumberGen() }, locY{ RandomNumberGen() }{
	CreateLoc();

}
int Meal::RandomNumberGen() {
	std::random_device generator;
	std::mt19937 gen(generator());
	std::uniform_int_distribution<int> distribution(1, GameArea::msize - 2);
	return distribution(generator);
}
void Meal::CreateMeal() {
	locX = RandomNumberGen();
	locY = RandomNumberGen();
	CreateLoc();
}
void Meal::CreateLoc() {
	GameArea::m_array[locY][locX] = mealShape;
}