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

// ��ʼ������
PQUEUE newQueue();

// ���
void enqueue(PQUEUE queue, T value);

// ����
T dequeue(PQUEUE queue);

// ���
void clear(PQUEUE queue);

// �ж��Ƿ�Ϊ��
bool isEmpty(PQUEUE queue);

// ��ö��д�С
int size(PQUEUE queue);
