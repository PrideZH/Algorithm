#pragma once

#include <iostream>
#include <stdlib.h>

typedef struct Node *ArrayList;
struct Node
{
	int *array; // 数组
	int length; // 数组空间大小
	int size; // 元素数
};

// 创建数组 默认大小为10
ArrayList newArrayList();

// 创建数组指定数组大小
ArrayList newArrayList(int length);

// 添加元素
void add(ArrayList list, int value);

// 指定下标插入元素
void add(ArrayList list, int index, int value);

// 获得指定下标元素
double get(ArrayList list, int index);

// 删除指定下标元素
double remove(ArrayList list, int index);

// 删除指定的第一个出现的元素
void remove(ArrayList list, double value);

// 删除指定的所有元素
void removeAll(ArrayList list, double value);

// 获得数组大小
int size(ArrayList list);

// 判断是否为空
bool isEmpty(ArrayList list);

// 清空元素
void clear(ArrayList list);

// 拷贝数组
ArrayList clone(ArrayList list);

// 顺序排序 使用快排
void sort(ArrayList list);

// 打印
void print(ArrayList list);

