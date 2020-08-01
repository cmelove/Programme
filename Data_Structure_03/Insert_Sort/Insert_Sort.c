#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void Show_Element(int * arr, int num)
{
	if (NULL == arr)
	{
		return;
	}
	if (num <= 0)
	{
		return;
	}

	for (int i = 0;i < num;++i)
	{
		printf("%d ", arr[i]);
	}
	puts("");

	return;
}

void Insert_Sort(int * arr, int num)
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

			for (j = i - 1;j >= 0 && temp > arr[j];--j)
			{
				arr[j + 1] = arr[j];
			}
			arr[j + 1] = temp;
		}
	}

	return;
}

void Shell_Sort(int * arr, int num)
{
	if (NULL == arr)
	{
		return;
	}
	if (num <= 0)
	{
		return;
	}

	int inc = num;

	do
	{
		inc = inc / 3 + 1;
		printf("inc=%d\n", inc);

		for (int i = 0;i < inc;++i)
		{
			for (int j = i + inc;j < num;j += inc)
			{
				if (arr[j] < arr[j - inc])
				{
					int temp = arr[j];
					int k;
					for (k = j - inc;k >= 0 && temp < arr[k];k -= inc)
					{
						arr[k + inc] = arr[k];
					}
					arr[k + inc] = temp;
				}
			}
		}
	} while (inc > 1);
}

void test01()
{
	int array[] = { 4,0,5,1,9,3,7,6,2,8 };

	int num = sizeof(array) / sizeof(int);

	//Insert_Sort(array, num);

	Shell_Sort(array, num);

	Show_Element(array, num);
}



int main(void)
{
	test01();


	system("pause");

	return 0;
}