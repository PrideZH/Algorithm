#include <iostream>
#include <time.h>
#include <graphics.h>

#define SCREEN_SIZE 600

using namespace std;

void show(int* array, int size, int now = NULL)
{
	int p = SCREEN_SIZE / size;
	BeginBatchDraw();
	cleardevice();
	// ��������
	setfillcolor(WHITE);
	for (int i = 0; i < size; ++i)
		fillrectangle(i * p, array[i] * p, (i + 1) * p, SCREEN_SIZE);
	// ���Ƶ�ǰ�ƶ�Ԫ��
	if(now != NULL){
		setfillcolor(RED);
		fillrectangle(now * p, array[now] * p, (now + 1) * p, SCREEN_SIZE);
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

void bubble_sort(int* array, int size)
{
	for (int i = 0; i < size - 1; ++i)
		for (int j = 0; j < size - i - 1; ++j)
			if (array[j] > array[j + 1])
			{
				show(array, size, j);
				swap(array[j], array[j + 1]);
			}		
	show(array, size, NULL);
}

int main()
{
	// ����������
	const int size = 50;
	int* array = new int[size];
	for (int i = 0; i < size; ++i)
		array[i] = i;
	shuffe(array, size);

	// ���ӻ�
	initgraph(SCREEN_SIZE, SCREEN_SIZE);
	setlinecolor(BLACK);
	show(array, size, NULL);

	// ����
	bubble_sort(array, size);

	return 0;
}
