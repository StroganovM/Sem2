#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<iomanip>
#include<conio.h>
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_EXIT 27
#define KEY_ENTER 13
#define SIZE 4
class game {
	int c_bombs = SIZE - 1;//количество бомб
	int map[SIZE][SIZE];
	int open_map[SIZE][SIZE];
	int open_counter = 0;
	bool winner = false;
	int curs_row = 0;
	int curs_col = 0;
	int i_key = 90;
	int choise = 9;
	bool min_open = false;
public:
	void instructions() {
		std::cout << "\t\tWelcome to the Minesweeper\n\n";
		std::cout << "use strelky to choise the kletka and press Enter\n";
		std::cout << "press Esc to exit\n";
	}
	void display_map(int& curs_row, int& curs_col) {
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				if (curs_row == i && curs_col == j) {
					std::cout << "[" << "*" << "]";
				}
				else {
					if (open_map[i][j] == 0) {
						std::cout << "[" << " " << "]";
					}
					else {
						if (map[i][j] == -1) {
							std::cout << "[" << "!" << "]";
						}
						else {
							std::cout << "[" << map[i][j] << "]";
						}
					}
				}
			}
			std::cout << std::endl;
		}
	}
	void set_map() {
		//позиции бомб

		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				map[i][j] = 0;
			}
		}
		for (int i = 0; i < SIZE; i++) {
			for (int j = 0; j < SIZE; j++) {
				open_map[i][j] = 0;
			}
		}
		int x;
		int y;
		for (int i = 0; i < c_bombs; i++) {
			x = rand() % SIZE;
			y = rand() % SIZE;
			if (map[x][y] == -1) {
				i--;
			}
			else {
				map[x][y] = -1;
				try {
					if ((x - 1) >= 0 && (y - 1) >= 0 && map[x - 1][y - 1] != -1) {
						map[x - 1][y - 1]++;
					}if (x - 1 >= 0 && map[x - 1][y] != -1) {
						map[x - 1][y]++;
					}if ((x - 1) >= 0 && (y + 1) <= (SIZE - 1) && map[x - 1][y + 1] != -1) {
						map[x - 1][y + 1]++;
					}if ((y + 1) <= (SIZE - 1) && map[x][y + 1] != -1) {
						map[x][y + 1]++;
					}if ((x + 1) <= (SIZE - 1) && (y + 1) <= (SIZE - 1) && map[x + 1][y + 1] != -1) {
						map[x + 1][y + 1]++;
					}if ((x + 1) <= (SIZE - 1) && map[x + 1][y] != -1) {
						map[x + 1][y]++;
					}if ((x + 1) <= (SIZE - 1) && (y - 1) >= 0 && map[x + 1][y - 1] != -1) {
						map[x + 1][y - 1]++;
					}if ((y - 1) >= 0 && map[x][y - 1] != -1) {
						map[x][y - 1]++;
					}
				}
				catch (const std::out_of_range& e) {
					std::cerr << "Ошибка: " << e.what() << std::endl;
				}
				catch (...) {
					std::cerr << "Неизвестная ошибка"<< std::endl;
				}
				//
			}
		}
	}
	void player(int& curs_row, int& curs_col, int& i_key, bool& min_open) {
		display_map(curs_row, curs_col);
		i_key = _getch();
		switch (i_key) {
		case KEY_ARROW_UP:
			if (curs_row == 0) {
				curs_row = SIZE - 1;
			}
			else {
				curs_row--;
			}
			break;
		case KEY_ARROW_DOWN:
			if (curs_row == SIZE - 1) {
				curs_row = 0;
			}
			else {
				curs_row++;
			}
			break;
		case KEY_ARROW_RIGHT:
			if (curs_col == SIZE - 1) {
				curs_col = 0;
			}
			else {
				curs_col++;
			}
			break;
		case KEY_ARROW_LEFT:
			if (curs_col == 0) {
				curs_col = SIZE - 1;
			}
			else {
				curs_col--;
			}
			break;
		case KEY_ENTER:
			if (map[curs_row][curs_col] == -1) {
				system("cls");
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						open_map[i][j] = 1;
					}
				}
				display_map(curs_row, curs_col);
				Sleep(2000);
				min_open = true;
			}
			else {
				if (open_map[curs_row][curs_col] == 1) {
					std::cout << "It was opened.\n";
					Sleep(1000);
				}
				else {
					open_map[curs_row][curs_col] = 1;
					open_counter++;
					if (open_counter == SIZE * SIZE - c_bombs) {
						winner = true;
					}
				}
			}
			curs_col = 0;
			curs_row = 0;
		}

		system("cls");
	}
	void reset() {
		set_map();
		open_counter = 0;
		winner = false;
		min_open = false;
		while (i_key != KEY_EXIT && min_open != true && winner != true) {
			player(curs_row, curs_col, i_key, min_open);
		}
	}
	bool get_min_open() {
		return min_open;
	}
	bool get_winner() {
		return winner;
	}
	game() {
		instructions();
		set_map();
		while (i_key != KEY_EXIT && min_open != true && winner != true) {
			player(curs_row, curs_col, i_key, min_open);
		}
	}
};
int main() {
	srand(time(0));
	game new_game;
	char choose = 'y';
	while (choose == 'y') {
		if (new_game.get_winner()) {
			std::cout << "You won!!!\n";
			Sleep(2000);
		}
		else if (new_game.get_min_open() == true) {
			std::cout << "oopps)\n";
			Sleep(1000);
			std::cout << "KABOOOOM!\nYou lose, s*it happens!\n";
			Sleep(1000);
		}
		system("cls");
		std::cout << "Do you want to play again?(y/n): ";
		std::cin >> choose;
		if (choose == 'y') {
			new_game.reset();
		}
	}
	std::cout << "See you later)\n";
	return 0;
}