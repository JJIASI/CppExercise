// Exercise6_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

// prototype
double(*pfun)(double, int); // declared pointer to fun
double pow(int digits);
double func_a(double input, int digits);
double func_b(double input, int digits);

int main()
{
	double input{ 27182.8182846 };
	cout << endl << "original value:" << fixed << setprecision(7) << endl
		<< input << endl << endl;
	pfun = func_a;
	cout << "a)" << endl;
	cout << fixed << setprecision(7) << pfun(input, 0) << endl << endl;
	cout << "b)" << endl;
	cout << fixed << setprecision(7) << pfun(input, 1) << endl << endl;
	cout << "c)" << endl;
	cout << fixed << setprecision(7) << pfun(input, 2) << endl << endl;
	cout << "d)" << endl;
	cout << fixed << setprecision(7) << pfun(input, 3) << endl << endl;


	pfun = func_b;
	cout << "e)" << endl;
	cout << fixed << setprecision(7) << pfun(input, 1) << endl << endl;
	cout << "f)" << endl;
	cout << fixed << setprecision(7) << pfun(input, 2) << endl << endl;
	cout << "g)" << endl;
	cout << fixed << setprecision(7) << pfun(input, 3) << endl << endl;


	return 0;
}

double func_a(double input, int digits) {
	double pow_value{ pow(digits) };
	input *= pow_value;
	return floor(input + .5)/ pow_value;
}

double func_b(double input, int digits) {
	double pow_value{ pow(digits) };
	input /= pow_value;
	return floor(input + .5) * pow_value;
}

double pow(int digits) {
	int output{1};
	for (int i = 1; i <= digits; i++) {
		output *= 10;
	}
	return output;
}