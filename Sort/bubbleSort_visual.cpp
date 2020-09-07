#include <iostream>
#include <time.h>
#include <graphics.h>

#define SCREEN_SIZE 600

using namespace std;

void show(int* array, int size, int i = NULL, int j = NULL)
{
	int p = SCREEN_SIZE / size;
	BeginBatchDraw();
	cleardevice();
	// 绘制数组
	setfillcolor(WHITE);
	for (int i = 0; i < size; ++i)
		fillrectangle(i * p, SCREEN_SIZE - (array[i] + 1) * p, (i + 1) * p, SCREEN_SIZE);
	// 绘制比较元素
	if (i != NULL) {
		setfillcolor(BLUE);
		fillrectangle(i * p, SCREEN_SIZE - (array[i] + 1) * p, (i + 1) * p, SCREEN_SIZE);
	}
	// 绘制交换元素
	if (j != NULL) {
		setfillcolor(RED);
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

void bubble_sort(int* array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		bool isSwap = false;
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				show(array, size, j, j + 1);
				swap(array[j], array[j + 1]);
				isSwap = true;
			}
			else
				show(array, size, j);
		}
		if (!isSwap) break;
	}
	show(array, size);
}

int main()
{
	// 获得随机数组
	const int size = 50;
	int* array = new int[size];
	for (int i = 0; i < size; ++i)
		array[i] = i;
	shuffe(array, size);

	// 可视化
	initgraph(SCREEN_SIZE, SCREEN_SIZE);
	setlinecolor(BLACK);
	show(array, size);

	// 排序
	bubble_sort(array, size);

	system("pause");

	return 0;
}
