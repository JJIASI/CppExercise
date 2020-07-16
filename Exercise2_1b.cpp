// Exercise2_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int summate(int input_value)
{
	int ans=0;
	for (int i = 1; i <= input_value; i++)
	{
		ans += i;
	}

	return ans;
}

int main()
{
	float input_value;
	bool err;
	char arr[1];
	
	do {
		cout << "Please enter a positive integer number:";
		err = false;
		cin >> input_value;

		if (cin.fail())
		{
			cin.clear();
			cin >> arr;
			err = true;
			cout << "Invalid input!\n";
		}
		else if (input_value-(int)input_value!= 0)
		{
			err = true;
			cout << "Invalid input!\n";
		}
		else if (input_value < 0)
		{
			err = true;
			cout << "Invalid input!\n";
		}
	} while (err);
	
	cout << "The summation answer is: \n"
		 << summate(int(input_value));

	return 0;
}