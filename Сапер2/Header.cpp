#include "Header.h"
#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <iomanip>
#include <Windows.h>
using namespace std;


int sizeI=0;
int sizeJ=0;
int countMine=0;

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
}

void DrowField() {
		
	cout <<"  ";
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
		cout << static_cast<char>(i + 65) << "|";
		for (int j = 0; j < sizeJ; j++) {
			if (Field[i][j] == '0') {
				cout << setw(3) << '0';
			}

			else if (Field[i][j] != ' ' && Field[i][j] != '0' && Field[i][j] != 'x') {
				cout << setw(3) << Field[i][j];
			}
			
			else if (Field[i][j] == 'x'){
				cout << setw(3) << '*';

			}
			else {
				cout << setw(3) << '*';
			}
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

			Field[mineX][mineY] = 'x';
			i++;
		}
	}
}

bool Shot(int x, int y) {


	if (Field[x][y] == 'x') {
		return false;
	}

	int count = 0;
	for (int i = x - 1; i <= x + 1 && i<sizeI; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			if ( Field[i][j] == 'x') count++;
		}
	}
	
	Field[x][y] = 48+count;
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
		cout << setw(3) << i + 1;
	}
	cout << endl;
	cout << "  ";

	for (int i = 0; i < sizeJ; i++) {
		cout << setw(3) << "---";
	}
	cout << endl;

	for (int i = 0; i < sizeI; i++) {
		cout << static_cast<char>(i + 65) << "|";

		for (int j = 0; j < sizeJ; j++) {
			if (Field[i][j] == ' ') {
				cout << setw(3) << '*';
			} 
			else {
			cout <<  setw(3) << Field[i][j];
			}
		}
		cout << endl;
	}

	cout << "Game Over" << endl;

}