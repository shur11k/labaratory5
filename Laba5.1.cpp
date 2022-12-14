#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <iostream>

void task1(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
				arr[i][j] = arr[j][i];
			
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}
void task2(int** arr, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i][j] != 0)
			{
				count++;
			}
		}
	}
	printf("Size of graph: ");
	printf("%d", count);
	printf("\n");
}

void task3(int** arr, int n)
{
	int domcount = 0;
	int izolcount = 0;
	int endcount = 0;	
	for (int i=0; i< n; i++)
	{
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] != 0)
			{
				sum++;
			}
		}

		if (sum == n-1)
		{
			if (sum == n - 1)
			{
				domcount++;			
			}
			printf("Dominanting top index: %d",i);
			printf("\n");
		}
		if(sum == 0)
		{
			if (sum == 0)
			{
				izolcount++;
			}
			printf("isolated vertex index %d",i);
			printf("\n");
		}
		if (sum == 1)
		{
			if (sum == 1)
			{
				endcount++;
			}
			printf("Ending vertrex index %d",i);
			printf("\n");
		}
	}
	printf("Amount of dominating vertexes %d", domcount);
	printf("\n");
	printf("Amount of isolated vertexes %d", izolcount);
	printf("\n");
	printf("Amount of ending vertexes %d", endcount);
	printf("\n");
}

int main()
{
	srand(time(NULL));
	int n;
	printf("Enter the number of graph verticles: ");
	scanf("%d", &n);

	int** arr = (int**)malloc(n * sizeof(int*));

	task1(arr, n);
	task2(arr, n);
	task3(arr, n);
	system("pause");
	return 0;
}
