#include <iostream>
#include <time.h>

using namespace std;

void shuffe(int* array, int size)
{
	srand((unsigned)time(NULL));
	for (int i = size - 1; i > 0; --i)
		swap(array[i], array[rand() % (i + 1)]);
}

void print(int* array, int size)
{
	cout << "[";
	int i;
	for (i = 0; i < size - 1; ++i)
		cout << array[i] << ",";
	cout << array[i] << "]" << endl;
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
	int* bucketArray = new int[maxNum - minNum + 1] {0};

	// 计数
	for (int i = 0; i < size; ++i)
		bucketArray[array[i] - minNum]++;

	// 返回数组
	int index = 0;
	for (int i = minNum; i <= maxNum; ++i)
		for (int j = 0; j < bucketArray[i]; ++j)
			array[index++] = i;
}

int main()
{
	// 获得随机数组
	const int size = 100;
	int* array = new int[size];
	for (int i = 0; i < size; ++i)
		array[i] = i;
	shuffe(array, size);

	// 打印数组
	print(array, size);

	// 排序
	counting_sort(array, size);

	// 打印数组
	print(array, size);

	system("pause");
	
	return 0;
}
