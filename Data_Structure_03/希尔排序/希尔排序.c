#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

void ShellSort(int *arr, int length)
{
	int increasement = length;

	do
	{
		increasement = increasement / 3 + 1;

		for (int i = 0;i < increasement;++i)
		{
			int k;
			for (int j = i + increasement;j < length;j += increasement)
			{
				if (arr[j] < arr[j - increasement])
				{
					int temp = arr[j];

					for (k = j - increasement;k >= 0 && temp < arr[k];k -= increasement)
					{
						arr[k + increasement] = arr[k];
					}
					arr[k + increasement] = temp;
				}
			}
		}

	} while (increasement > 1);

}


int main(void)
{
	int arr[] = { 4,2,8,0,5,7,1,3,9,6 };

	ShellSort(arr, 10);

	for (int i = 0;i < 10;++i)
	{
		printf("%d ", arr[i]);
	}

	puts("");

	system("pause");

	return 0;
}