#include <iostream>
#include <time.h>
#include <graphics.h>

#define SCREEN_SIZE 600
#define SIZE 200

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
	// 绘制处理元素
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

void quicksort(int *array, int left, int right)
{
	if (left > right)
		return;

	// 获得基数
	swap(array[(right + left) / 2], array[left]);
	int pivot = array[left];

	int l = left;
	int r = right;
	while (l != r) 
	{
		while (array[r] >= pivot && l < r)
			r--;
		while (array[l] <= pivot && l < r)
			l++;
		show(array, SIZE, l, r);
		if (l < r)
			swap(array[l], array[r]);
	}

	// 基数归位
	swap(array[left], array[l]);

	quicksort(array, left, l - 1);
	quicksort(array, l + 1, right);
}

void quick_sort(int* array, int size)
{
	quicksort(array, 0, size - 1);
}

int main()
{
	// 获得随机数组
	int* array = new int[SIZE];
	for (int i = 0; i < SIZE; ++i)
		array[i] = i;
	shuffe(array, SIZE);
	
	// 可视化
	initgraph(SCREEN_SIZE, SCREEN_SIZE);
	setlinecolor(BLACK);
	show(array, SIZE);

	// 排序
	quick_sort(array, SIZE);

	show(array, SIZE);

	system("pause");

	return 0;
}
