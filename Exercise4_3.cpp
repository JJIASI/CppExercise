// Exercise4_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 80

bool duplicate_ckeck(int data[],int num, int n) {
	bool duplicateBool=false;
	
	for (int i = 0; i <= n; i++) {
		if (data[i] == num) {
			duplicateBool = true;
			//printf("duplicate number: ");
			//printf("%d\n", num);
			break;
		}
	}
	return duplicateBool;
}

void swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void bubbleSort(int data[], int n) {
	int switch_times = 0;
	do
	{
		switch_times = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (data[i] > data[i + 1])
			{
				swap(data[i], data[i + 1]);
				switch_times += 1;
			}
		}
		//printf("times: %d\n", switch_times);
	} while (switch_times !=0);
}

void main()
{
	srand(time(NULL));
	int data[MAX];
	int num;

	for (int n = 0; n < MAX; n++)
	{
		do {
			num = rand() % 1000 + 1;
		} while (duplicate_ckeck(data, num, n));
		data[n] = num;
	}

	bubbleSort(data, MAX);
	for (int i = 0; i < MAX; i++) {
		if (i % 8 == 0) {
			printf("\n");
		}
		printf("%5d", data[i]);

	}
	
}
