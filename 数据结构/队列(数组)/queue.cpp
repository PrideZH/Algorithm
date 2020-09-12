#include "queue.h"

using namespace std;

PQUEUE newQueue()
{
	PQUEUE queue = (PQUEUE)malloc(sizeof(QUEUE));
	queue->front = queue->rear = 0;
	return queue;
}

void enqueue(PQUEUE queue, T value)
{
	// 队满
	if ((queue->rear + 1) % QSIZE == queue->front)
	{
		cout << "队满" << endl;
		return;
	}

	// 入队
	queue->queue[queue->rear] = value;

	queue->rear = (queue->rear + 1) % QSIZE;
}

T dequeue(PQUEUE queue)
{
	if (isEmpty(queue))
	{
		cout << "队空" << endl;
		return NULL;
	}

	T value = queue->queue[queue->front];

	queue->front = (queue->front + 1) % QSIZE;

	return value;
}

void clear(PQUEUE queue)
{
	free(queue);
	*queue = *newQueue();
}

bool isEmpty(PQUEUE queue)
{
	return queue->front == queue->rear;
}

int size(PQUEUE queue)
{
	return (queue->rear - queue->front + QSIZE) % QSIZE;
}

void print(PQUEUE queue)
{
	if (isEmpty(queue))
		return;
	cout << "[";
	for (int i = queue->front; i < queue->rear; ++i)
		cout << queue->queue[i] << (i == queue->rear - 1 ? "]" : ",");
}