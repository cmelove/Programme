#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void insert_Sort(int * arr, int num)
{
	if (NULL == arr)
	{
		return;
	}

	if (num <= 0)
	{
		return;
	}

	for (int i = 1;i < num;++i)
	{
		if (arr[i] > arr[i - 1])
		{
			int temp = arr[i];

			int j;

			for (j = i - 1;j >= 0 && arr[j] < temp;--j)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}
}

int main(void)
{
	int arr[] = { 4,2,8,0,5,7,1,3,9,6 };

	insert_Sort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0;i < sizeof(arr) / sizeof(int);++i)
	{
		printf("%d ", arr[i]);
	}

	puts("");

	system("pause");

	return 0;
}