
#include <iostream>
using namespace std;

int main()
{
	enum class Shape {
		TRINAGLE,
		RECTANGLE
	};
	enum class Animal {
		DOG,
		CAT
	};

	Shape shape = Shape::TRINAGLE ;
	Animal animal=Animal::DOG;

	if (shape == animal) // compile error here!!!
		cout << "shape and animal are equal!\n";
	else
		cout << "shape and animal are not equal!\n";

	return 0;
}
