#include <iostream>
#include <time.h>
#include <vector>
#include <graphics.h>

#define SCREEN_SIZE 600
#define SIZE 50

using namespace std;

void show(int* array, int size, int i = NULL, int j = NULL)
{
	int p = SCREEN_SIZE / size;
	BeginBatchDraw();
	cleardevice();
	// ��������
	setfillcolor(WHITE);
	for (int i = 0; i < size; ++i)
		fillrectangle(i * p, SCREEN_SIZE - (array[i] + 1) * p, (i + 1) * p, SCREEN_SIZE);
	// ���ƴ���Ԫ��
	if (i != NULL) {
		setfillcolor(RED);
		fillrectangle(i * p, SCREEN_SIZE - (array[i] + 1) * p, (i + 1) * p, SCREEN_SIZE);
	}
	if (j != NULL) {
		setfillcolor(BLUE);
		fillrectangle(j * p, SCREEN_SIZE - (array[j] + 1) * p, (j + 1) * p, SCREEN_SIZE);
	}
	EndBatchDraw();
	Sleep(20);
}

void shuffe(int* array, int size)
{
	srand((unsigned)time(NULL));
	for (int i = size - 1; i > 0; --i)
		swap(array[i], array[rand() % (i + 1)]);
}

void selection_sort(int *array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		int min = i;
		for (int j = i + 1; j < size; ++j)
		{
			if (array[j] < array[min])
				min = j;
			show(array, size, j, min);
		}

		if (i != min)
		{
			swap(array[i], array[min]);
			show(array, size, i, min);
		}
	}
}

int main()
{
	// ����������
	int* array = new int[SIZE];
	for (int i = 0; i < SIZE; ++i)
		array[i] = i;
	shuffe(array, SIZE);
	
	// ���ӻ�
	initgraph(SCREEN_SIZE, SCREEN_SIZE);
	setlinecolor(BLACK);
	show(array, SIZE);

	// ����
	selection_sort(array, SIZE);

	show(array, SIZE);

	system("pause");

	return 0;
}
