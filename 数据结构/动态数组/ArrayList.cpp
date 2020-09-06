#include "arrayList.h"

using namespace std;

ArrayList newArrayList()
{
	return newArrayList(10);
}

ArrayList newArrayList(int length)
{
	ArrayList list = (ArrayList)malloc(sizeof(struct Node));
	list->array = (int *)malloc(sizeof(int) * length);
	list->length = length;
	list->size = 0;
	return list;
}

// 扩容
void expansion(ArrayList list)
{
	int *array = (int *)malloc(sizeof(int) * list->length * 2);
	list->length <<= 1;
	for (int i = 0; i < list->size; ++i)
		array[i] = list->array[i];
	free(list->array);
	list->array = array;
}

void add(ArrayList list, int value)
{
	if (list->size == list->length)
		expansion(list);

	list->array[list->size] = value;
	list->size++;
}

void add(ArrayList list, int index, int value)
{
	if (index < 0 || index > list->size)
		return;

	if (list->size == list->length)
		expansion(list);

	int *array = list->array;
	for (int i = list->size; i >= 0; --i)
	{
		if (index == i)
		{
			array[i] = value;
			list->size++;
			return;
		}
		array[i] = array[i - 1];
	}
}

double get(ArrayList list, int index)
{
	if (index < 0 || index >= list->size)
		return NULL;
	return list->array[index];
}

double remove(ArrayList list, int index)
{
	if (index < 0 || index >= list->size)
		return NULL;

	int *array = list->array;
	int value = array[index];

	for (int i = index; i < list->size - 1; ++i)
	{
		array[i] = array[i + 1];
	}
	list->size--;
	return value;
}

void remove(ArrayList list, double value)
{
	for (int i = 0; i < list->size; ++i)
		if (list->array[i] == value)
		{
			remove(list, i);
			return;
		}
}

void removeAll(ArrayList list, double value)
{
	for (int i = 0; i < list->size; ++i)
		if (list->array[i] == value)
		{
			remove(list, i);
			--i;
		}
}

int size(ArrayList list)
{
	return list->size;
}

bool isEmpty(ArrayList list)
{
	return list->size == 0;
}

void clear(ArrayList list)
{
	free(list);
	*list = *newArrayList();
}

ArrayList clone(ArrayList list)
{
	ArrayList newList = newArrayList(list->length);
	for (int i = 0; i < list->size; ++i)
		newList->array[i] = list->array[i];
	newList->size = list->size;
	return newList;
}

void quicksort(ArrayList list, int left, int right) {
	int i, j;
	if (left > right)
		return;
	// 获得基数
	int pivot = list->array[(right + left) / 2];
	list->array[(right + left) / 2] = list->array[left];
	list->array[left] = pivot;

	i = left;
	j = right;
	while (i != j) {
		while (list->array[j] >= pivot && i < j)
			j--;
		while (list->array[i] <= pivot && i < j)
			i++;
		if (i < j)
		{
			list->array[i] ^= list->array[j];
			list->array[j] ^= list->array[i];
			list->array[i] ^= list->array[j];
		}
	}
	// 基准归位
	list->array[left] = list->array[i];
	list->array[i] = pivot;

	quicksort(list, left, i - 1);
	quicksort(list, i + 1, right);
}

void sort(ArrayList list)
{
	quicksort(list, 0, list->size - 1);
}

void print(ArrayList list)
{
	if (isEmpty(list))
		return;
	cout << "[";
	for (int i = 0; i < list->size; ++i)
		cout << list->array[i] << ((i == list->size - 1) ? "]" : ",");
}