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
	const int size = 100;
	int* array = new int[size];
	for (int i = 0; i < size; ++i)
		array[i] = i;
	shuffe(array, size);

	// 打印数组
	print(array, size);

	// 排序
	quick_sort(array, size);

	// 打印数组
	print(array, size);

	system("pause");
	
	return 0;
}
