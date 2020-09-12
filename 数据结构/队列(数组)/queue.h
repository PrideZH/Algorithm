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

// ��ӡ
void print(PQUEUE queue);
