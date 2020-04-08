#include "Header.h"
#include <iostream>
#include <ctime>

using namespace std;

int sizeI = 5;
int sizeJ = 5;
char** Field = new char*[sizeI];
int countMine;

void FieldInit(int m, int n) {
	Field = new char* [m];

	cout << "  ";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << "---";
	}
	cout << endl;

	for (int i = 0; i < m; i++)
	{
		Field[i] = new char[n];
		for (int j = 0; j < n; j++)
		{
			Field[i][j] = '*';
		}
	}

	for (int i = 0; i < m; i++) {
		cout << (char)(i + 65) << "|";
		for (int j = 0; j < n; j++) {
			cout << Field[i][j] << " ";
		}
		cout << endl;
	}
}

void Set_Mine(int countMine) {
	srand(time(0));

	int mineX;
	int mineY;
	for (int i = 0; i < countMine; i++)
	{
		mineX = rand() % sizeI;
		mineY = rand() % sizeJ;
		if (Field[mineX][mineY] = '$') {

			Field[mineX+1][mineY+1] = '$';
		}
	}
}

void Shot(int mineX, int mineY) {
	if (Field[mineX][mineY] = '$') {
		cout << "Game over!!!" << endl;
	}
	int count = 0;
	for (int i = mineX - 1; i <= mineX + 1 && i < sizeI; i++) {
		for (int j = mineY - 1; j <= mineY + 1 && j < sizeJ; j++) {
			if (Field[i][j] == '$') {
				count++;
			}
		}
	}

	Field[mineX][mineY] = count;
}

void Game() {
	void FieldInit(int m, int n);
	void Set_Mine(int countMine);
	char x;
	int y;
	do
	{
		cout << "Enter the shot coordinates" << endl;
		cin >> x >> y;
		x = x - 65;
		y = y - 1;

	} while ( Shot(x,y));

	
}