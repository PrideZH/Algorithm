#include <iostream>
#include <time.h>
#include <vector>
#include <graphics.h>

#define SCREEN_SIZE 600
#define SIZE 150

#define NUM 10 // Ͱ����

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

void quicksort(int* array, int left, int right, int begin)
{
	if (left > right)
		return;

	// ��û���
	swap(array[begin + (right + left) / 2], array[begin + left]);
	int pivot = array[begin + left];

	int l = left;
	int r = right;
	while (l != r)
	{
		while (array[begin + r] >= pivot && l < r)
			r--;
		while (array[begin + l] <= pivot && l < r)
			l++;
		if (l < r)
			swap(array[begin + l], array[begin + r]);
		show(array, SIZE, begin + l, begin + r);
	}

	// ������λ
	swap(array[begin + left], array[begin + l]);

	quicksort(array, left, l - 1, begin);
	quicksort(array, l + 1, right, begin);
}

void bucket_sort(int *array, int size)
{
	// �������Χ
	int min = array[0], max = array[0];
	for (int i = 0; i < size; ++i)
	{
		if (array[i] < min) min = array[i];
		else if (array[i] > max) max = array[i];
	}

	// ����Ͱ
	vector<int> buckets[NUM];
	for (int i = 0; i < size; ++i)
	{
		show(array, size, i);
		buckets[(NUM - 1) * (array[i] - min) / (max - min)].push_back(array[i]);
	}

	// �������鲢��ʾ
	int array_i = 0;
	for (int bucket_i = 0; bucket_i < NUM; ++bucket_i)
		for (int i = 0; i < buckets[bucket_i].size(); ++i)
		{
			show(array, size, array_i);
			array[array_i++] = buckets[bucket_i][i];
		}
	show(array, size);

	// Ͱ������
	int begin = 0; // Ͱ��Ԫ��ԭ����λ��
	for (int i = 0; i < NUM; ++i)
	{
		quicksort(array, 0, buckets[i].size() - 1, begin);
		begin += buckets[i].size();
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
	Sleep(8000);
	// ����
	bucket_sort(array, SIZE);

	show(array, SIZE);

	system("pause");

	return 0;
}
