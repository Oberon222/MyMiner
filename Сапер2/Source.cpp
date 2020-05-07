#include <iostream>
#include <string>
#include "Header.h"
#include <chrono>
#include <thread>
#include <Windows.h>
#include <conio.h>
#include <list>
#include <fstream>
using namespace std;

int main() {
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int action;
	int action2;
	int userI;
	int userJ;
	int userMineCount;

	do
	{
		cout << "1) Start the game" << endl;
		cout << "2) Exit" << endl;
		cin >> action;

		switch (action)
		{
		case 1:
		{
			cout << "Choose the difficulty level of the game: "
				"1 - easy, 2 - medium, 3 - hard, 4 - my level " << endl;
			cin >> action2;

			switch (action2)
			{
			case 1:
			{
				SetConsoleTextAttribute(hConsole, 10);
				cout << "You have chosen the EASY level" << endl;
				SetConsoleTextAttribute(hConsole, 7);
					
				InitSizeI(10);
				InitSizeJ(10);
				InitCountMine(10);

				Game();
				
				break;
			}
			case 2:
			{
				SetConsoleTextAttribute(hConsole, 14);
				cout << "You have chosen the MEDIUM level" << endl;
				SetConsoleTextAttribute(hConsole, 7);

				InitSizeI(16);
				InitSizeJ(16);
				InitCountMine(40);
								
				Game();

				break;
			}
			case 3:
			{
				SetConsoleTextAttribute(hConsole, 12);
				cout << "You have chosen the HARD level." << endl;
				SetConsoleTextAttribute(hConsole, 7);

				InitSizeI(16);
				InitSizeJ(30);
				InitCountMine(100);
				
				Game();

				break;
			}
			case 4:
			{
				SetConsoleTextAttribute(hConsole, 13);
				do
				{
					cout << "You can create your own level." << endl;
					cout << endl;
			
					cout << "Enter size is vertically (max 26)-> ";
					cin >> userI;
								
				} while (userI>26);

				cout << "Enter size is horizontal -> ";
				cin >> userJ;
				cout << "Enter the number of min -> ";
				cin >> userMineCount;
				SetConsoleTextAttribute(hConsole, 7);
				InitSizeI(userI);
				InitSizeJ(userJ);
				InitCountMine(userMineCount);

				Game();
				break;
			}
			}
			break;
		}

		case 2:
		{
			cout << "Goodbye :)" << endl;
			break;
		}
		}
	} while (action != 2);

	system("pause");
	return 0;
}