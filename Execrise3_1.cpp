// Execrise3_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int choice;
	int input;
	int sum;
	char close_sel;

	do {
		cout << "Select loop type, press in 1, 2 or 3:" << endl;
		cout << setw(5) << "1. " << "While" << endl
			<< setw(5) << "2. " << "do-While" << endl
			<< setw(5) << "3. " << "for" << endl;
		cin >> choice;
		sum = 0;
		switch (choice)
		{
		case 1: cout << endl << "While mode" << endl;
			while (true)
			{
				cout << endl << "Enter an integer value:";
				cin >> input;
				if (input != 0)
				{
					sum += input;
				}
				else
				{
					cout << "the sum of numbers is:" << sum << endl;
					break;
				}
			}
			break;
		
		case 2: cout << endl << "do-While mode" << endl;
			do {
				cout << endl << "Enter an integer value:";
				cin >> input;
				if (input != 0)
				{
					sum += input;
				}
				else
				{
					cout << "the sum of numbers is:" << sum << endl;
					break;
				}
			} while (true);
			break;
		
		case 3: cout << endl << "for loop mode" << endl;
			for (;;)
			{
				cout << endl << "Enter an integer value:";
				cin >> input;
				if (input != 0)
				{
					sum += input;
				}
				else
				{
					cout << "the sum of numbers is:" << sum << endl;
					break;
				}
			}
			break;
		
		default: cout << endl << "You entered a wrong number." << endl;
			break;
		}

		do {
			cout << endl << "Do you want to continue? (y/n)" << endl;
			cin >> close_sel;
			if ((close_sel == 'y') || (close_sel == 'n'))
			{
				cout << "Good Bye!";
				break;
			}
			else cout << "Invalid Character!";
		} while (true);

		

	} while (close_sel == 'y');

	return 0;
}
