// Exercise4_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	char str[] = "12.8 18.5 -2.8 4.96 11.74 7.93 -6.18 2.855 14.82";
	char delim[] = " ";
	char *pch;
	double sum{0.0};
	int len{ 0 };

	cout << endl << "Splitting String: " << str << endl;
	pch = strtok(str, delim);

	while (pch != NULL)
	{
		sum += atof(pch);
		len += 1;
		pch = strtok(NULL, delim);
	}

	cout << "The sum is: " << sum << endl;
	cout << "The average is: " << sum / len << endl;

}
