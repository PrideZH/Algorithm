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

void bubble_sort(int* array, int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		bool isSwap = false;
		for (int j = 0; j < size - i - 1; ++j)
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				isSwap = true;
			}
		if (!isSwap) break;
	}
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
	bubble_sort(array, size);

	// 打印数组
	print(array, size);

	system("pause");
	
	return 0;
}
