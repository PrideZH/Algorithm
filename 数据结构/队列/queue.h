#pragma once

#include <iostream>
#include <stdlib.h>

typedef int T;

typedef struct QNode QNODE, *PQNODE;
struct QNode
{
	T value;
	PQNODE next;
};

typedef struct Queue QUEUE, *PQUEUE;
struct Queue
{
	PQNODE front;
	PQNODE rear;
	int size;
};

// 初始化队列
PQUEUE newQueue();

// 入队
void enqueue(PQUEUE queue, T value);

// 出列
T dequeue(PQUEUE queue);

// 清空
void clear(PQUEUE queue);

// 判断是否为空
bool isEmpty(PQUEUE queue);

// 获得队列大小
int size(PQUEUE queue);
