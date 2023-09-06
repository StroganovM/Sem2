#include<iostream>
#include <windows.h>
#include <conio.h>

#define SIZE_FIELD 9 // Размер поля 

//Дефайники для кнопочек
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ENTER 13
#define KEY_SHIFT 16
using namespace std;

//Постановление курсора по заданым координатам
void gotoxy(int x, int y) {
    COORD point = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

class Field {
public:
    int max_bombs = 11;
    int field[SIZE_FIELD + 2][SIZE_FIELD + 2] = {};
    int fake_field[SIZE_FIELD + 2][SIZE_FIELD + 2] = {}; //Фейковое поле (изначально заполненное #)
    int Number_of_bombs = 0; //Переменная, хранит количество сгенерируемых бомб
    int No_bombs = 0; //Переменная хранит количество открытых ячеек, в которых нет бомб
    char bomb = 15; //Чарик для символа бомбы
    //Объявление границ игрового поля
    void borders() {
        for (int i = 0; i < SIZE_FIELD + 2; i++) {
            field[i][0] = 100;
            field[0][i] = 100;
            field[i][10] = 100;
            field[10][i] = 100;
            fake_field[i][0] = 100;
            fake_field[0][i] = 100;
            fake_field[i][10] = 100;
            fake_field[10][i] = 100;
        }
    }

    //Заполнение фейкового поля 
    void filling_fake_field() {
        for (int a = 1; a < SIZE_FIELD + 1; a++) {
            for (int b = 1; b < SIZE_FIELD + 1; b++) {
                fake_field[a][b] = 10;
            }
        }
    }
    //Генерация бомб в рандомных местах поля
    void generate_bombs() {
        for (int i = 0; i < max_bombs; i++)
        {
            field[1 + rand() % (9)][1 + rand() % (9)] = 9;
        }

    }
    //Функция для подсчёта ячеек не содержащих бомб
    void no_bombs(int& a) {
        a++;
    }
    //Считает количество сгенерируемых бомб на поле 
    int number_bombs() {
        for (int a = 1; a < SIZE_FIELD + 1; a++) {
            for (int b = 1; b < SIZE_FIELD + 1; b++) {
                if (field[a][b] == 9) {
                    Number_of_bombs = Number_of_bombs + 1;
                }
            }
        }
        return Number_of_bombs;
    }
    //Проставление ориентиров бомб(единички, двойки и тд)
    void markup() {
        int number_markup = 0;
        for (int i = 1; i < SIZE_FIELD + 1; i++) {
            for (int j = 1; j < SIZE_FIELD + 1; j++) {
                if (field[i][j] == 9) {
                    continue;
                }
                if (field[i][j + 1] == 9) {
                    number_markup++;
                }
                if (field[i][j - 1] == 9) {
                    number_markup++;
                }
                if (field[i + 1][j + 1] == 9) {
                    number_markup++;
                }
                if (field[i + 1][j - 1] == 9) {
                    number_markup++;
                }
                if (field[i - 1][j + 1] == 9) {
                    number_markup++;
                }
                if (field[i - 1][j - 1] == 9) {
                    number_markup++;
                }
                if (field[i + 1][j] == 9) {
                    number_markup++;
                }
                if (field[i - 1][j] == 9) {
                    number_markup++;
                }
                field[i][j] = number_markup;
                number_markup = 0;

            }
        }
    }

    //Вывод игрового поля на экран
    void print_field() {
        No_bombs = 0;
        cout << "\n";
        for (int i = 1; i < SIZE_FIELD + 1; i++) {
            for (int j = 1; j < SIZE_FIELD + 1; j++) {
                if (fake_field[i][j] == 10) {
                    cout << " #";
                }
                if ((fake_field[i][j] != 10) && (fake_field[i][j] != 9)) {
                    cout << " " << fake_field[i][j];
                    no_bombs(No_bombs);
                }
                if (fake_field[i][j] == 9) {
                    cout << " " << bomb;
                }
            }
            cout << '\n';


        }
        cout << "\n";
    }
    //ГДЗ по сапёру
    void print_field_GDZ() {
        cout << "\n";
        for (int i = 1; i < SIZE_FIELD + 1; i++) {
            for (int j = 1; j < SIZE_FIELD + 1; j++) {
                cout << " " << field[i][j];

            }
            cout << '\n';


        }
        system("pause");
    }
};


class Game {
private:
    void Welcome_and_download() {
        int a = 0;

        //Приветствие)
        cout << "ЛОЛ, ЭТО САПЁР)\n";
        system("pause");
        system("cls");

        //Цикл для экрана загрузки
        while (a < 2) {
            cout << "Загрузка.";
            Sleep(500);
            system("cls");
            cout << "Загрузка..";
            Sleep(500);
            system("cls");
            cout << "Загрузка...";
            Sleep(500);
            system("cls");
            a++;
        }
    }
    void Welcome_and_rules() {
        cout << "Уважаемый человек, который открыл это творение!\nОгромное спасибо, что вы притронулись к этому куску шедевра.\nМеня зовут Частов Вячеслав Робертович и я с гордостью представляю вам написанную мною игру Сапёр :).\n";
        system("pause");
        system("cls");
        cout << "Правила очень просты. Перед вами имеется скрытое поле размером 9 на 9.\nПо нему можно передвигаться используя стрелочки (вверх, вниз, вправо, влево), \nа таже можно выбирать нужную вам ячейку поля нажав клавишу ENTER.\nПосле нажатия данной клавиши ячейка откроется.\n";
        system("pause");
        system("cls");
        cout << "Желаю вам приятной игры!\n";
        system("pause");
        system("cls");
    }
    //Функция завершения игры(в зависимости от исхода выводит разные надписи)
    void GameOver(int defeat, int victory) {
        if (defeat == 1) {
            cout << "Win" << "\n";
        }
        else {
            if (victory == 1) {
                cout << "Louse" << "\n";

            }
        }
        system("pause");
    }
public:
    //Главный метод. Он запускает всю игру
    void game_launch() {
        Welcome_and_download();
        Welcome_and_rules();
        Field field;                 // Создаём объект класса Field
        field.borders();             //Заполняем границы поля(основного и фейкового)
        field.filling_fake_field();  //Заполняем фейковое поле
        field.generate_bombs();      //Рандомим бомбы
        field.markup();              //Проставляем ориентиры бомб
        field.number_bombs();        //Считаем количество зарандомившихся бомб

        int ikey = 0, x = 1, y = 1;
        int exit_flag = 0;
        int GDZ_flag;
        field.print_field();
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
                    field.fake_field[y][1] = field.field[y][1];
                    break;
                case 3:
                    field.fake_field[y][2] = field.field[y][2];
                    break;
                case 5:
                    field.fake_field[y][3] = field.field[y][3];
                    break;
                case 7:
                    field.fake_field[y][4] = field.field[y][4];
                    break;
                case 9:
                    field.fake_field[y][5] = field.field[y][5];
                    break;
                case 11:
                    field.fake_field[y][6] = field.field[y][6];
                    break;
                case 13:
                    field.fake_field[y][7] = field.field[y][7];
                    break;
                case 15:
                    field.fake_field[y][8] = field.field[y][8];
                    break;
                case 17:
                    field.fake_field[y][9] = field.field[y][9];
                    break;

                }
            }
            system("cls");
            field.print_field();
            for (int i = 1; i < SIZE_FIELD + 1; i++) {
                for (int j = 1; j < SIZE_FIELD + 1; j++) {
                    if (field.fake_field[i][j] == 9) {
                        exit_flag++;
                        GameOver(exit_flag, 0);
                        system("cls");
                        cout << "Если вы хотите посмотреть ГДЗ, то нажмите ENTER: ";
                        ikey = _getch();
                        if (ikey == KEY_ENTER) {
                            system("cls");
                            field.print_field_GDZ();
                        }
                        else {
                            system("cls");
                            cout << "Вам не интересно ГДЗ???!!!Ну и ладно.\n";
                            system("pause");
                        }
                    }
                    else {
                        if ((81 - field.No_bombs) == field.Number_of_bombs) {
                            exit_flag++;
                            GameOver(0, exit_flag);
                            exit(1);
                        }
                    }
                }
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(0));
    Game game;
    game.game_launch();
    return 0;
}