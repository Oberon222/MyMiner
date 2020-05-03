#include "Header.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
using namespace std;
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

//todo: generate mines AFTER first move

int sizeI = 0;
int sizeJ = 0;
int countMine = 0;
int countUnopenedCell = 0;

char** Field = new char* [sizeI];

void Timer() {
	int hours = 0, minutes = 0, seconds = 0;
	while (true) {
		cout << hours << ":" << minutes << ":" << seconds;
		seconds++;
		if (seconds == 60) {
			seconds = 0;
			minutes++;
		}
		if (minutes == 60) {
			minutes = 0;
			hours++;
		}
		this_thread::sleep_for(0.999s);
		system("cls");
	}
}

void InitSizeI(int a) {
	sizeI = a;
}
void InitSizeJ(int b) {
	sizeJ = b;
}
void InitCountMine(int c) {
	countMine = c;
}

void FieldInit() {

	Field = new char* [sizeI];

	for (int i = 0; i < sizeI; i++)
	{
		Field[i] = new char[sizeJ];
		for (int j = 0; j < sizeJ; j++)
		{
			Field[i][j] = ' ';
		}
	}
	countUnopenedCell = sizeI * sizeJ;
}

void DrowField() {

	cout << "  ";

	for (int i = 0; i < sizeJ; i++) {
		cout << setw(3) << i + 1;
	}
	cout << endl;
	cout << "   ";
	for (int i = 0; i < sizeJ; i++) {
		cout << setw(3) << "---";
	}
	cout << endl;
	

	for (int i = 0; i < sizeI; i++) {
		cout << (char)(i + 65) << "|";

		for (int j = 0; j < sizeJ; j++) {
			if (Field[i][j] == '0') {
				cout << setw(3) << '0';
			}

			else if (Field[i][j] != ' ' && Field[i][j] != '0' && Field[i][j] != 'x') {
				cout << setw(3) << Field[i][j];
			}

			else if (Field[i][j] == 'x') {
				SetConsoleTextAttribute(hConsole, 6);

				cout << setw(3) << '*';
				SetConsoleTextAttribute(hConsole, 7);
			}
			else {
				SetConsoleTextAttribute(hConsole, 6);

				cout << setw(3) << '*';
				SetConsoleTextAttribute(hConsole, 7);
			}
		}
		cout << endl;
	}
	cout << endl;
	cout << "To win you need to find " << countMine << " mines" << endl;
}

void Set_Mine() {
	srand(time(0));

	int mineX = 0;
	int mineY = 0;
	for (int i = 0; i < countMine; )
	{
		mineX = rand() % sizeI;
		mineY = rand() % sizeJ;
		cout << "X" << mineX << "-Y" << mineY<<endl;   // ï³äêàçêà, êîîğäèíàòè ì³í
		if (Field[mineX][mineY] == ' ') {

			Field[mineX][mineY] = 'x';
			i++;
		}
	}

}

void showMines(int colorCode) {
	cout << "  ";
	for (int i = 0; i < sizeJ; i++) {
		cout << setw(3) << i + 1;
	}
	cout << endl;
	cout << "  ";

	for (int i = 0; i < sizeJ; i++) {
		cout << setw(3) << "---";
	}
	cout << endl;
	for (int i = 0; i < sizeI; i++) {
		cout << (char)(i + 65) << "|";

		for (int j = 0; j < sizeJ; j++) {
			if (Field[i][j] == ' ') {
				SetConsoleTextAttribute(hConsole, 6);

				cout << setw(3) << '*';
				SetConsoleTextAttribute(hConsole, 7);

			}
			else {
				SetConsoleTextAttribute(hConsole, colorCode);

				cout << setw(3) << Field[i][j];
				SetConsoleTextAttribute(hConsole, 7);

			}
		}
		cout << endl;
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, colorCode);
}

bool youWon() {
	showMines(10);

	cout << "Y O U    W O N ! ! !" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl;
	cout << "Game Over" << endl;

	return false;
};

bool youAreLoser() {
	showMines(12);

	cout << "L O S E R ! ! !" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl;
	cout << "Game Over" << endl;

	return false;
};


bool Shot(int x, int y) {
	int count = 0;
	countUnopenedCell = countUnopenedCell - 1;
	cout << countUnopenedCell << endl;
	cout << countMine << endl;

	

	 if (Field[x][y] != 'x') {
		for (int i = x - 1; i <= x + 1 && i < sizeI; i++) {
			for (int j = y - 1; j <= y + 1; j++) {
				if (i >= 0 && j >= 0) {
					if (Field[i][j] == 'x') count++;

				}
			}
		}
		Field[x][y] = 48 + count;
	}
	/*else if (Field[x][y] == '0') {
		for (int i = x - 1; i <= x + 1 && i < sizeI; i++) {
			for (int j = y - 1; j <= y + 1 && j<sizeJ; j++) {
				if (i >= 0 && j >= 0) {
					Field[i][j+1] == '0';
				}
			}
		}
	}*/


	/*else (countMine)*/
	if (countUnopenedCell == countMine) {
		return youWon();
	}

	if (Field[x][y] == 'x') { // ïğîãğàø
		return youAreLoser();
	}

		return continueGame();
}

bool continueGame() {
	return true;
};


void Game() {

	//Timer();
	FieldInit();
	Set_Mine();

	char x;
	int y;
	do
	{
		DrowField();
		cout << endl;
		cout << "Enter the shot coordinates" << endl;
		cin >> x >> y;

		//ÏÅĞÅÂÎÄÈÌÎ Ë²ÒÅĞÓ Õ  Ó ÖÈÔĞÓ (ÊÎÄ Ë²ÒÅĞÈ À - 65)
		x = x - 65;
		y = y - 1;
		system("cls");

	} while (Shot(x, y));

	/*cout << "  ";
	for (int i = 0; i < sizeJ; i++) {
		cout << setw(3) << i + 1;
	}
	cout << endl;
	cout << "  ";

	for (int i = 0; i < sizeJ; i++) {
		cout << setw(3) << "---";
	}
	cout << endl;*/

	/*for (int i = 0; i < sizeI; i++) {
		cout << (char)(i + 65) << "|";

		for (int j = 0; j < sizeJ; j++) {
			if (Field[i][j] == ' ') {
				SetConsoleTextAttribute(hConsole, 6);

				cout << setw(3) << '*';
				SetConsoleTextAttribute(hConsole, 7);

			}
			else {
				SetConsoleTextAttribute(hConsole, 12);

				cout << setw(3) << Field[i][j];
				SetConsoleTextAttribute(hConsole, 7);

			}
		}
		cout << endl;
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 12);

	cout << "L O S E R ! ! !" << endl;
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl;
	cout << "Game Over" << endl;*/



}