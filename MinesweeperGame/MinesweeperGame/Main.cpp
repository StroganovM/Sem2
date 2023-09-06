#include<iostream>
#include "windows.h"
#include <conio.h>
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ENTER 13
#define KEY_SHIFT 16

using namespace std;
void gotoxy(int x, int y) {
	COORD point = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}
class Game {
private:
	int bombs = 10;
	static const int sizemap = 9;
	int map[sizemap + 2][sizemap + 2] = {};
	int cosmeticmap[sizemap + 2][sizemap + 2] = {};
	int curs_row = 0;
	int curs_col = 0;
	int Number_of_bombs = 0; 
	int Notbombs = 0;
public:
	
	void map_limiter() {
		for (int i = 0; i < sizemap + 2; i++) {
			map[i][0] = 100;
			map[0][i] = 100;
			map[i][10] = 100;
			map[10][i] = 100;
			cosmeticmap[i][0] = 100;
			cosmeticmap[0][i] = 100;
			cosmeticmap[i][10] = 100;
			cosmeticmap[10][i] = 100;
		}
	}
	void notbombs(int& a) {
		a++;
	}
	void GameStatus(int defeat, int victory) {
		if (defeat == 1) {
			system("cls");
			cout << "Louse" << "\n";
		}
		else {
			if (victory == 1) {
				system("cls");
				cout << "Win" << "\n";

			}
		}
		system("pause");
	}
	void generatebombs() {
		for (int i = 0; i < bombs; i++)
		{
			map[1 + rand() % (8)][1 + rand() % (8)] = 9;
		}
	}
	void fantom_map() {
		for (int a = 1; a < sizemap + 1; a++) {
			for (int b = 1; b < sizemap + 1; b++) {
				cosmeticmap[a][b] = 10;
			}
		}
	}
	void print_map() {
		Notbombs = 0;
		cout << "\n";
		for (int i = 1; i < sizemap + 1; i++) {
			for (int j = 1; j < sizemap + 1; j++) {
				if (cosmeticmap[i][j] == 10) {
					cout << " #";
				}
				if ((cosmeticmap[i][j] != 10) && (cosmeticmap[i][j] != 9)) {
					cout << " " << cosmeticmap[i][j];
					notbombs(Notbombs);
				}
				if (cosmeticmap[i][j] == 9) {
					cout << " " << 9;
				}
			}
			cout << '\n';


		}
		cout << "\n";
	}
	void markup_map() {
		int markupcount = 0;
		for (int i = 1; i < sizemap+1 ; i++) {
			for (int j = 1; j < sizemap+1 ; j++) {
				if (map[j][i] == 9) {
					continue;
				}
				if (map[j][i + 1] == 9) {
					markupcount++;
				}
				if (map[j][i - 1] == 9) {
					markupcount++;
				}
				if (map[j + 1][i + 1] == 9) {
					markupcount++;
				}
				if (map[j + 1][i - 1] == 9) {
					markupcount++;
				}
				if (map[j - 1][i + 1] == 9) {
					markupcount++;
				}
				if (map[j - 1][i - 1] == 9) {
					markupcount++;
				}
				if (map[j + 1][i] == 9) {
					markupcount++;
				}
				if (map[j - 1][i] == 9) {
					markupcount++;
				}
				map[j][i] = markupcount;
				markupcount = 0;

			}
		}
	}
	void LoadingScreen() {
		cout << "Сапёр ошибается только один раз в жизни!" << endl;
		cout << "Loading ";
		cout << '-' << flush;
		for (int i = 0; i < 20; i++) {
			Sleep(10);
			cout << "\b\\" << flush;
			Sleep(10);
			cout << "\b|" << flush;
			Sleep(10);
			cout << "\b/" << flush;
			Sleep(10);
			cout << "\b-" << flush;
		}
		system("cls");
	}
	void Control() {
		int ikey = 0, x = 1, y = 1;
		int exit_flag = 0;
		print_map();
		gotoxy(x, y);
		while (exit_flag != 1) {
			gotoxy(x, y);
			ikey = _getch();
			switch (ikey) {
			case KEY_ARROW_RIGHT:
				if (x < 17) {
					x = x + 2;
				}
				else {
					if (x == 17) {
						x = 1;
					}
				}
				break;
			case KEY_ARROW_LEFT:
				if (x > 1) {
					x = x - 2;
				}
				else {
					if (x == 1) {
						x = 17;
					}
				}
				break;
			case KEY_ARROW_UP:
				if (y > 1) {
					y--;
				}
				else {
					if (y == 1) {
						y = 9;
					}
				}
				break;
			case KEY_ARROW_DOWN:
				if (y < 9) {
					y++;
				}
				else {
					if (y == 9) {
						y = 1;
					}
				}
				break;
			}
			gotoxy(x, y);
			if (ikey == KEY_ENTER) {
				switch (x) {
				case 1:
					cosmeticmap[y][1] = map[y][1];
					break;
				case 3:
					cosmeticmap[y][2] = map[y][2];
					break;
				case 5:
					cosmeticmap[y][3] = map[y][3];
					break;
				case 7:
					cosmeticmap[y][4] = map[y][4];
					break;
				case 9:
					cosmeticmap[y][5] = map[y][5];
					break;
				case 11:
					cosmeticmap[y][6] = map[y][6];
					break;
				case 13:
					cosmeticmap[y][7] = map[y][7];
					break;
				case 15:
					cosmeticmap[y][8] = map[y][8];
					break;
				case 17:
					cosmeticmap[y][9] = map[y][9];
					break;

				}
			}
			system("cls");
			print_map();
			for (int i = 1; i < sizemap + 1; i++) {
				for (int j = 1; j < sizemap + 1; j++) {
					if (cosmeticmap[i][j] == 9) {
						exit_flag++;
						GameStatus(exit_flag, 0);
						system("cls");
					}
					if ((81 - Notbombs) == Number_of_bombs) {
							exit_flag++;
							GameStatus(0, exit_flag);
							exit(1);
						}
					}
				}
			}
		}
	
};
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Game game;
	game.LoadingScreen();
	game.map_limiter();
	game.generatebombs();
	game.fantom_map();
	game.markup_map();
	game.Control();
	system("pause");
	return 0;
}