// Execrise3_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;


bool error_type(char input[10])
{
	for (int i = 0; i <= 10; i++)
	{
		if (isdigit(input[i]))
		{
			return true;
		}
		else return false;
	};
}



int main()
{
	char input[10];
	cout << "input test: " << endl;
	cin >> input;

	if (error_type(input)) {
		cout << "ok!!!" << endl;
	};

	return 0;
}
