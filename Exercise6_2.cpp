

#define _USE_MATH_DEFINES

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

double get_volume(double radius, double height);
bool check_val(double val);

int main(int argc, char* argv[])
{
	char *rptr = NULL;
	char *hptr = NULL;
	bool check_r = false;
	bool check_h = false;
	double radius{};
	double height{};
	double volume{};

	// get parameter value
	// -r radius
	// -h height
	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-') {
			switch (argv[i][1]) 
			{
			case 'r':
				rptr = argv[i+1];
				cout << "radius: " << rptr << endl;
				check_r = true;
				break;
			case 'h':
				hptr = argv[i+1];
				cout << "height: " << hptr << endl;
				check_h = true;
				break;
			}
		}
	}
	

	//check input
	try {
		if (check_r && check_h) {
			radius = atof(rptr);
			height = atof(hptr);
			// check value
			if (check_val(radius) && check_val(height)) {
				volume = get_volume(radius, height);
				cout << "volume: " << volume << endl;
			}
		}
		else throw "Please input radius or height! \n -r radius \n -h height";
	}
	catch (const char eMsg[]) {
		cout << eMsg << endl;
	}
}

double get_volume(double radius, double height) {

	return M_PI * pow(radius, 2.0)*height;
}


bool check_val(double val)
{
	bool c{};
	try {
		if (val <= 0) 
		{
			c = false;
			throw val;
		}
		else c = true;
	}
	catch (double badval) {
		cout << double(badval) << " is bad value." << endl;
	}

	return c;
}