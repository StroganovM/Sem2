#include<iostream>
#include "windows.h"
using namespace std;
class Game {
private:
	int bombs = 16;
	static const int sizemap = 9;
	int map[sizemap + 1][sizemap + 1] = {};
public:
	void map_limiter() {
		for (int i = 0; i < sizemap + 1; i++) {
			map[i][0] = 100;
			map[0][i] = 100;
			map[i][9] = 100;
			map[9][i] = 100;
		}
	}
	void generatebombs() {
		for (int i = 0; i < bombs; i++)
		{
			map[1 + rand() % (8)][1 + rand() % (8)] = 9;
		}
	}
	void print_map() {
		for (int i = 1; i < sizemap; i++) {
			for (int j = 1; j < sizemap; j++) {
				cout << "[" << map[i][j] << ']';
			}
			cout << '\n';


		}
	}
	void markup_map() {
		int markupcount = 0;
		for (int i = 1; i < sizemap - 1; i++) {
			for (int j = 1; j < sizemap - 1; j++) {
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
		cout << "Ñàï¸ð îøèáàåòñÿ òîëüêî îäèí ðàç â æèçíè!" << endl;
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
};
int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	Game game;
	game.LoadingScreen();
	game.map_limiter();
	game.generatebombs();
	game.markup_map();
	game.print_map();
	system("pause");
	return 0;
}