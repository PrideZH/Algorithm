#include <iostream>
#include <time.h>
#include <vector>

#define NUM 10 // 桶数量 

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

void quicksort(vector<int>& bucket, int left, int right)
{
	if (left > right)
		return;

	// 获得基数
	swap(bucket[(right + left) / 2], bucket[left]);
	int pivot = bucket[left];

	int l = left;
	int r = right;
	while (l != r)
	{
		while (bucket[r] >= pivot && l < r)
			r--;
		while (bucket[l] <= pivot && l < r)
			l++;
		if (l < r)
			swap(bucket[l], bucket[r]);
	}

	// 基数归位
	swap(bucket[left], bucket[l]);

	quicksort(bucket, left, l - 1);
	quicksort(bucket, l + 1, right);
}

void bucket_sort(int *array, int size)
{
	// 获得数范围
	int min = array[0], max = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] < min) min = array[i];
		else if (array[i] > max) max = array[i];
	}

	// 放入桶
	vector<int> buckets[NUM];
	for (int i = 0; i < size; ++i)
		buckets[(NUM - 1) * (array[i] - min) / (max - min)].push_back(array[i]);
	// 桶内排序
	for (int i = 0; i < NUM; ++i)
		quicksort(buckets[i], 0, buckets[i].size() - 1);

	// 输出到数组
	int array_i = 0;
	for (int bucket_i = 0; bucket_i < NUM; ++bucket_i)
		for (int i = 0; i < buckets[bucket_i].size(); ++i)
			array[array_i++] = buckets[bucket_i][i];
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
	bucket_sort(array, size);

	// 打印数组
	print(array, size);

	system("pause");
	
	return 0;
}
