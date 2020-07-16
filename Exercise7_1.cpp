#include <iostream>
#include "Date.h"

using namespace std;

int main() {
	// test sample

	// MM/DD/YYYY
	
	Date US{ "02", "28", "2021", 1 };
	// YYYY/MM/DD
	
	Date ISO{ "1970", "02", "20" };
	// MonthStr MM,YYYY
	
	Date String{ "December", "26", "2017", 'a' };
	// default
	
	Date Def{};
	// copy
	
	Date Copy{US};
	Copy.AddDays(45);

	cout << "US format: " << endl;
	cout << US.USFormat() << endl
		<< US.ISOFormat() << endl
		<< US.StringFormat() << endl << endl;

	cout << "ISO format: " << endl;
	cout << ISO.USFormat() << endl
		<< ISO.ISOFormat() << endl
		<< ISO.StringFormat() << endl << endl;

	cout << "String format: " << endl;
	cout << String.USFormat() << endl
		<< String.ISOFormat() << endl
		<< String.StringFormat() << endl << endl;

	cout << "default format:" << endl;
	cout << Def.USFormat() << endl
		<< Def.ISOFormat() << endl
		<< Def.StringFormat() << endl << endl;

	cout << "copy from US:\n";
	cout << Copy.USFormat() << endl
		<< Copy.ISOFormat() << endl
		<< Copy.StringFormat() << endl << endl;

	
	// Date Array
	cout << "array:\n";
	Date DateArr[7];
	for(int i=0;i<7;i++){
		DateArr[i].AddDays(i);
		cout << DateArr[i].USFormat() <<endl;
	}

}