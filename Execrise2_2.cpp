// Execrise2_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	enum Shape {
		TRINAGLE,
		RECTANGLE
	};
	enum Animal {
		DOG, // change value setting to fix shape and animal are equal issue.
		CAT
	};

	Shape shape1 = TRINAGLE;
	Shape shape2 = TRINAGLE;

	if (shape1 == shape2)
		cout << "shape1 and shape2 are equal!\n";
	else
		cout << "shape1 and shape2 are not equal!\n";

	return 0;
}
