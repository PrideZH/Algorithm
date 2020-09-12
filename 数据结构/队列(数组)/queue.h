#pragma once

#include <iostream>
#include <stdlib.h>

#define QSIZE 100

typedef int T;

typedef struct Queue QUEUE, *PQUEUE;
struct Queue
{
	T queue[QSIZE];
	int rear, front;
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

// 打印
void print(PQUEUE queue);
