// Exercise4_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void main()
{
	// a
	// float *value;
	// cout << value << endl;
	// description: uninitialized float pointer 'value'.
	float a{ 10.0f };
	float *value{ &a }; //initialized 'value'
	cout << "a)" << endl 
		<<"value:"<< *value << endl << endl;
    
	// b
	//double *dPtr;
	//float *fPtr;
	//fPtr = dPtr;
	// description: a value of type "double *" cannot be assigned to an entity of type "float *"

	double d{ 10.0 };
	float f{ 5.0f };
	double *dPtr{ &d };
	float *fPtr{ &f };
	*fPtr = static_cast<float>(*dPtr); // initialized dPtr and fptr. then convert type double to float.
	cout << "b)" << endl
		<< "fPtr:" << *fPtr << endl
		<< "dPtr" << *dPtr << endl << endl;

	// c
	//int *m, n;
	//m = n;
	// description: a value of type "int" cannot be assigned to an entity of type "int *"

	int *m, n=10; // initialized n value
	m = &n; // store address of n in m
	cout << "c)" << endl
		<< "m:" << *m << endl << endl;

	// d
	//char s[] = "This is a character array";
	//cout << "d)" << endl;
	//for (; *s != '\0'; s++)
	//	cout << *s << ' ';
	// description: s is not l-value, expression must l-value

	char s[] = "This is a character array";
	char *sptr{s}; //initialized address of char array s of first address in sptr. or *sptr{&s[0]}
	cout << "d)" << endl;
	for (; *sptr != '\0'; sptr++)
		cout << sptr[0] << ' ';
	cout << endl << endl;

	// e
	//int *numPtr, result;
	//void *genericPtr = numPtr;
	//result = *genericPtr + 7;
	// description: must be a complete object type, void pointer must convert to int pointer and get address value

	int *numPtr, result, e{ 10 };
	numPtr = &e;
	void *genericPtr{ numPtr };
	result = *(int *)genericPtr + 7; //convert to int pointer and get value.
	cout << "e)" << endl
		 << "result:" << result << endl << endl;

	// f
	//double x = 15.5;
	//double xPtr = *x;
	//cout << xPtr << endl;
	//description: x is not pointer

	double x = 15.5;
	double *xPtr{ &x };
	cout << "f)" <<endl
		 << "xPtr:" << *xPtr << endl << endl;


}

