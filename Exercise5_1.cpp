// Exercise5_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Function prototype
int Factorial(int n); // a
double Add(double a, double b); // b
int A(void); //c
int* Product(void); //d

int main(int argc, char* argv[])
{
	//a
	int input{};
	cout << "a)"
		<< "Factorial test (Please key in positive integer): " << endl;
	cin >> input;
	cout << "Ans: " << Factorial(input) << endl << endl;

	//b
	int a{}, b{};
	cout << "b)" << "Add test: " << endl
		<< "a:";
	cin >> a;
	cout << "b:";
	cin >> b;
	cout << "Ans:" << Add(a, b) << endl << endl;

	//c
	cout << "c)" << endl;
	A();
	cout << endl;

	// d
	cout << "d)" << endl;
	int* ptr{};
	ptr = Product();
	cout << "Result is: " << *ptr << endl;
	delete ptr; // release memeory from "Product()" created
	ptr = nullptr;
	return 0;
}


// a)
//int Factorial(int n) {
//	if (n <= 1)
//		return 1;
//	else
//		n * Factorial(n - 1);
//}
//  In recursive function didn't return value for recursive step.

int Factorial(int n) {
	if (n <= 1)
		return 1;
	else
		return n * Factorial(n - 1);
}

// b)
//double Add(double a, double b) {
//	double result;
//	result = a + b;
//}
// Didn't return value

double Add(double a, double b) {
	double result;
	result = a + b;
	return result;
}


// c)
//int A(void) {
//	cout << "Inside function A" << endl;
//	int B(void) {
//		cout << "Inside function B" << endl;
//	};
//}
// nested function cannot compile

int A(void) {
	cout << "Inside function A" << endl;
	auto B = [](void) {
		cout << "Inside function B" << endl;
	}; // declares a lambda, which can be called like a function.
	B();
	return 0;
}

// d)
//void Product(void) {
//	int a, b, c, *result;
//	cout << "Enter three integers:";
//	cin >> a >> b >> c;
//	*result = a * b * c;
//}
// 
// didn't return anything

// return int pointer
int* Product(void) {
	int a, b, c, *result{ new int{} }; // create int memeory location for *result
	cout << "Enter three integers:"<< endl;
	cin >> a >> b >> c;
	*result = a * b * c;
	return result;
}

