#include "Header.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;



int sizeI = 5;
int sizeJ = 5;
int countMine = 10;

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
}

void DrowField() {

	cout << "  ";
	for (int i = 0; i < sizeJ; i++) {
		cout << i + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < sizeJ; i++) {
		cout << "---";
	}
	cout << endl;

	for (int i = 0; i < sizeI; i++) {
		cout << (char)(i + 65) << "|";
		for (int j = 0; j < sizeJ; j++) {
			cout << '*' << " ";
		}
		cout << endl;
	}

}


void Set_Mine() {
	srand(time(0));

	int mineX = 0;
	int mineY = 0;
	for (int i = 0; i < countMine; )
	{
		mineX = rand() % sizeI;
		mineY = rand() % sizeJ;
		if (Field[mineX][mineY] == ' ') {

			Field[mineX][mineY] = '$';
			i++;
		}
	}
}

bool Shot(int x, int y) {
	if (Field[x][y] == '$') {
		return false;
	}

	int count = 0;
	for (int i = x - 1; i <= x + 1 && i < sizeI; i++) {
		for (int j = y - 1; i <= y + 1 && j < sizeJ; j++) {
			if (i == '$' && j == '$') count++;
			
		}
	}

	Field[x][y] = count+48;
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

		cout << "Enter the shot coordinates" << endl;
		cin >> x >> y;

		//оепебндхлн к╡репс у  с жхтпс (йнд к╡репх ю - 65)

		x = x - 65;
		y = y - 1;
		system("cls");

	} while (Shot(x, y));

	cout << "  ";
	for (int i = 0; i < sizeJ; i++) {
		cout << i + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < sizeJ; i++) {
		cout << "---";
	}
	cout << endl;

	for (int i = 0; i < sizeI; i++) {
		cout << (char)(i + 65) << "|";

		for (int j = 0; j < sizeJ; j++) {
			if (Field[i][j] == ' ') {
				cout << "*";
			}
			
			cout << Field[i][j];
		}
		cout << endl;
	}

	cout << "Game Over" << endl;

}