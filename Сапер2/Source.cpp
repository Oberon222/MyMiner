#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main() {
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
				cout << "You have chosen the easy level:"
					"the size of the field is 5x5;"
					"number of mines 10." << endl;
				FieldInit(5, 5);
				Set_Mine(10);
				
				break;
			}
			case 2:
			{
				cout << "You have chosen the medium level:"
					"the size of the field is 10x10;"
					"number of mines 30." << endl;
				FieldInit(10, 10);
				Set_Mine(30);

				break;
			}
			case 3:
			{
				cout << "You have chosen the hard level:"
					"the size of the field is 15x15;"
					"number of mines 40." << endl;
				FieldInit(15,15);
				Set_Mine(40);

				break;
			}
			case 4:
			{
				cout << "Enter a field size" << endl;
				cin >> userI >> userJ;
				cout << "Enter the number of min" << endl;
				cin >> userMineCount;
				FieldInit(userI, userJ);
				Set_Mine(userMineCount);

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