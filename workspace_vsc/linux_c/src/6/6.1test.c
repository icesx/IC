#include <stdio.h>
void BubbleSort(int *pData, int count)
{
	int temp, i, j;
	for (i = 0; i < count; i++)
		for (j = count - 1; j > i; j--)
		{
			if (pData[j] < pData[j - 1])
			{
				temp = pData[j];
				pData[j] = pData[j - 1];
				pData[j - 1] = temp;
			}
		}
}
int main()
{
	struct student
	{
		int age;
		char name[20];
		float score;
	} stu = {20, "cff", 89};

	int i;
	int Data[] = {10, 9, 8, 7, 6, 5};
	BubbleSort(Data, 6);
	for (i = 0; i < 6; i++)
	{
		printf("%d ", Data[i]);
	}
	printf("\n");
	return 0;
}
