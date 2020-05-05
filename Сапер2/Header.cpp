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


int sizeI = 0;
int sizeJ = 0;
int countMine = 0;
int countUnopenedCells = 0;

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
	if (a > 26)
	{
		cout << "The vertical size of the field cannot exceed 26 lines." << endl;
	}
	
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
	countUnopenedCells = sizeI * sizeJ;
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
		/*cout << "X" << mineX << "-Y" << mineY<<endl;*/   // Ô≥‰Í‡ÁÍ‡, ÍÓÓ‰ËÌ‡ÚË Ï≥Ì
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

bool youWin() {
	showMines(10);

	cout << "Y O U    W I N ! ! !" << endl;
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
	countUnopenedCells = countUnopenedCells - 1;
	cout <<"No open cells remain " <<countUnopenedCells << endl;

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
	
	if (countUnopenedCells == countMine) {  //¬»√–¿ÿ
		return youWin();
	}

	if (Field[x][y] == 'x') { // œ–Œ√–¿ÿ
		return youAreLoser();
	}

		return true;
}



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

		//œ≈–≈¬Œƒ»ÃŒ À≤“≈–” ’  ” ÷»‘–” ( Œƒ À≤“≈–» ¿ - 65)
		x = x - 65;
		y = y - 1;
		system("cls");

	} while (Shot(x, y));

}