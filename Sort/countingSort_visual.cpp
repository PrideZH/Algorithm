#include <iostream>
#include <time.h>
#include <graphics.h>

#define SCREEN_SIZE 600

using namespace std;

void show(int* array, int size, int i = NULL)
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
	EndBatchDraw();
	Sleep(20);
}

void shuffe(int* array, int size)
{
	srand((unsigned)time(NULL));
	for (int i = size - 1; i > 0; --i)
		swap(array[i], array[rand() % (i + 1)]);
}

void counting_sort(int* array, int size)
{
	// 获得范围
	int minNum = array[0];
	int maxNum = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] < minNum)
			minNum = array[i];
		if (array[i] > maxNum)
			maxNum = array[i];
	}

	// 创建桶
	int* bucketArray = new int[maxNum - minNum + 1]{ 0 };

	// 计数
	for (int i = 0; i < size; ++i)
	{
		bucketArray[array[i] - minNum]++;
		show(array, size, i);
	}

	// 返回数组
	int index = 0;
	for (int i = minNum; i <= maxNum; ++i)
		for (int j = 0; j < bucketArray[i]; ++j)
		{
			array[index++] = i;
			show(array, size, i);
		}

	show(array, size);
}

int main()
{
	// 获得随机数组
	const int size = 100;
	int* array = new int[size];
	for (int i = 0; i < size; ++i)
		array[i] = i;
	shuffe(array, size);

	// 可视化
	initgraph(SCREEN_SIZE, SCREEN_SIZE);
	setlinecolor(BLACK);
	show(array, size);
	Sleep(5000);
	// 排序
	counting_sort(array, size);

	system("pause");

	return 0;
}
