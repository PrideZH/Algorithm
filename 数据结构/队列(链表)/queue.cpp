#include "queue.h"

PQUEUE newQueue()
{
	PQUEUE queue = (PQUEUE)malloc(sizeof(QUEUE));
	PQNODE head = (PQNODE)malloc(sizeof(QNODE));
	head->next = NULL;
	queue->front = head;
	queue->rear = head;
	queue->size = 0;
	return queue;
}

void enqueue(PQUEUE queue, T value)
{
	// 初始化节点
	PQNODE node = (PQNODE)malloc(sizeof(QNODE));
	node->value = value;
	node->next = NULL;
	// 入队
	queue->rear->next = node;
	queue->rear = node;

	queue->size++;
}

T dequeue(PQUEUE queue)
{
	PQNODE node = queue->front->next;
	if (NULL == node)
		return NULL;

	if (queue->front->next == queue->rear)
		queue->rear = queue->front;

	queue->front->next = node->next;
	int value = node->value;
	free(node);

	queue->size--;

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
	return queue->size;
}