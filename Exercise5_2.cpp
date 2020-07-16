// Exercise5_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int WhatIsThisA(const int b[], int size); //a
int WhatIsThisB(const char* s); //b
int WhatIsThisC(const char* s1, const char* s2); //c

int main()
{
	// a
	//example
	// 5 + 4 + 3 + 2 + 1 = 15
	int b[]{ 1,2,3,4,5 };
	int size{ 5 };
	cout << "a)" << endl;
	cout << WhatIsThisA(b, size) << endl << endl;

	//b
	//example
	//length = 14
	char s[] = "This is B Test"; 
	char *sptr{ s };
	cout << "b)" << endl;
	cout << WhatIsThisB(sptr) << endl<< endl;

	//c
	//example
	//s1 > s2 -> 1
	char s1[] = "3011";
	char s2[] = "302";
	char *s1ptr{ s1 };
	char *s2ptr{ s2 };
	cout << "c)" << endl;
	cout << WhatIsThisC(s1ptr, s2ptr) << endl;

}


//a
//Explain what do the following functions do?
//add all number in an int array, from back to front.
int WhatIsThisA(const int b[], int size)
{
	if (size <= 0) return 0;
	if (size == 1)
		return b[0];
	else
		return b[size - 1] + WhatIsThisA(b, size - 1);
}

//b
//Explain what do the following functions do?
//counts the number of characters in char array
int WhatIsThisB(const char* s)
{
	int x = 0;
	for (x = 0; *s != '\0'; s++)
		++x;
	return x;
}

//c
//Explain what do the following functions do?
//compare char array s1 with s2, from front to back.
//if(s1 > s2) -> 1
//if(s1 < s2) -> -1
//if(s1 == s2 ) -> 0
int WhatIsThisC(const char* s1, const char* s2)
{
	for (; *s1 != '\0' && *s2 != '\0'; s1++, s2++)
		if (*s1 != *s2)
			return (*s1 > *s2) ? 1 : -1;
	if (*s1 == '\0' && *s2 == '\0')
		return 0;
	else
	{
		cout << *s1 << endl;
		cout << *s2 << endl;
		return (*s1 > *s2) ? 1 : -1;
	}

}