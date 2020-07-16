// Exercise2_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

int summate(int input_value)
{
	int ans=0;

	for (int i = 1; i <= input_value; i++)
	{
		ans += i;
	}

	return ans;
}


int main()
{
	float input_value;
	bool err;
	int status = 0;

	
	do {
		printf("Please enter a positive integer number:");
		err = false;
		status = scanf("%f", &input_value);

		if (status==0)
		{
			while (getchar() != '\n');
			err = true;
			printf("Invalid input!\n");
		}
		else if (input_value - (int)input_value != 0)
		{
			err = true;
			printf("Invalid input!\n");
		}
		else if (input_value < 0)
		{
			err = true;
			printf("Invalid input!\n");
		}
	} while (err);

	printf("The summation answer is: %d\n", summate(input_value));

	return 0;
}

