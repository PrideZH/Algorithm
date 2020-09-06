#pragma once

#include <iostream>
#include <stdlib.h>

typedef struct Node NODE, *PNODE;
struct Node
{
	double value;
	PNODE next;
};

// 初始化链表
PNODE newLinkedList();

// 获得链表大小
int size(PNODE head);

// 使用尾插添加元素
void add(PNODE head, double value);

// 指定下标插入元素
void add(PNODE head, int index, double value);

// 获得指定下标元素
double get(PNODE head, int index);

// 移除指定元素
void remove(PNODE head, double value);

// 移除指定下标元素
double remove(PNODE head, int index);

// 移除指定元素的全部节点
void removeAll(PNODE head, double value);

// 清空链表
void clear(PNODE head);

// 判断是否为空
bool isEmpty(PNODE head);

// 克隆链表
PNODE clone(PNODE head);

// 打印链表
void print(PNODE head);