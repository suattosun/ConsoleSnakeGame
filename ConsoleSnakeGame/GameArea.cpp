#include"GameArea.h"

GameArea::GameArea() {
	for (std::size_t index_x{}; index_x < msize; index_x++) {
		for (std::size_t index_y{}; index_y < msize; index_y++) {
			if ((index_y == 0) || (index_y == GameArea::msize - 1) || (index_x == 0) || (index_x == GameArea::msize - 1))
				m_array[index_x][index_y] = '#';
			else
				m_array[index_x][index_y] = ' ';
			std::cout << "\n";
		}
	}
}
void GameArea::PrintGameArea() {
	std::cout << scoreCount << '\n';
	for (std::size_t index_x{}; index_x < msize; index_x++) {
		for (std::size_t index_y{}; index_y < msize; index_y++) {
			std::cout << m_array[index_x][index_y];
		}
		std::cout << "\n";
	}
}