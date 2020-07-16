
#include <iostream>
using namespace std;

int main()
{
	enum class Shape_Animal {
		TRINAGLE,
		RECTANGLE, 
		DOG,
		CAT
	};

	Shape_Animal shape = Shape_Animal::TRINAGLE;
	Shape_Animal animal = Shape_Animal::DOG;

	if (shape == animal)
		cout << "shape and animal are equal!\n";
	else
		cout << "shape and animal are not equal!\n";

	return 0;
}
