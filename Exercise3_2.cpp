// Exercise3_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	char show_i;

	cout << "ASCII table:" << endl << "=========================================================================";
		
	for (int i = 0; i <= 127; i++) {
;		switch (i)
		{
		case 0:   //NULL
			show_i = 32;
				break;
		case 7:   //BEL 
			show_i = 32;
			break;
		case 8:   //BS 
			show_i = 32;
			break;
		case 9:   //HT 
			show_i = 32;
			break;
		case 10:  //LF
			show_i = 32;
			break;
		case 13:  //CR
			show_i = 32;
			break;
		case 127: //DEL
			show_i = 32;
			break;
		default:
			show_i = i;
			break;
		}

		if (i % 8 == 0)
			cout << endl << "|";
			
		cout << setw(5) << hex  << i
			 << setw(3) << show_i << "|";
	}
	cout <<endl<< "=========================================================================" <<endl;
	return 0;
}
