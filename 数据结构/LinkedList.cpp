#include "LinkedList.h"

using namespace std;

PNODE newLinkedList()
{
	PNODE head = (PNODE)malloc(sizeof(NODE));
	head->next = NULL;
	return head;
}

int size(PNODE head)
{
	int count = 0;
	for (PNODE p = head; p->next != NULL; p = p->next) count++;
	return count;
}

void add(PNODE head, double value)
{
	// 初始化节点
	PNODE node = (PNODE)malloc(sizeof(NODE));
	node->value = value;
	node->next = NULL;
	// 获得尾节点
	PNODE tail;
	for (tail = head; tail->next != NULL; tail = tail->next);
	// 链接
	tail->next = node;
}

void add(PNODE head, int index, double value)
{
	PNODE p = head;
	for (int i = 0; p->next != NULL; ++i, p = p->next)
		if (i == index)
		{
			// 初始化节点
			PNODE node = (PNODE)malloc(sizeof(NODE));
			node->value = value;
			// 插入
			node->next = p->next;
			p->next = node;
			return;
		}
}

double get(PNODE head, int index)
{
	PNODE p = head;
	for (int i = 0; p->next != NULL; ++i, p = p->next)
		if (i == index)
			return p->next->value;
	return NULL;
}

void remove(PNODE head, double value)
{
	for (PNODE p = head; p->next != NULL; p = p->next)
		if (p->next->value == value)
		{
			// 删除节点
			PNODE node = p->next;
			p->next = p->next->next;
			free(node);
			return;
		}
}

double remove(PNODE head, int index)
{
	PNODE p = head;
	for (int i = 0; p->next != NULL; ++i, p = p->next)
		if (i == index)
		{
			// 获得节点元素 
			PNODE node = p->next;
			double value = node->value;
			// 删除节点
			p->next = p->next->next;
			free(node);
			// 返回节点元素
			return value;
		}
	return NULL;
}

void removeAll(PNODE head, double value)
{
	for (PNODE p = head; p->next != NULL;)
		if (p->next->value == value)
		{
			// 删除节点
			PNODE node = p->next;
			p->next = p->next->next;
			free(node);
		}
		else
			// 不为该元素继续往下遍历
			p = p->next;
}

void clear(PNODE head)
{
	PNODE p = head;
	while (p->next != NULL)
	{
		PNODE node = p->next;
		p->next = p->next->next;
		free(node);
	}
}

bool isEmpty(PNODE head)
{
	return NULL == head->next;
}

PNODE clone(PNODE head)
{
	PNODE new_head = (PNODE)malloc(sizeof(NODE));
	new_head->next = NULL;
	for (PNODE p = head, new_p = new_head; p->next != NULL; p = p->next)
	{
		PNODE node = (PNODE)malloc(sizeof(NODE));
		node->value = p->next->value;
		node->next = NULL;
		new_p->next = node;
		new_p = node;
	}
	return new_head;
}

void print(PNODE head)
{
	cout << "[";
	for (PNODE p = head; p->next != NULL; p = p->next)
		cout << p->next->value << ((p->next->next == NULL) ? "]" : ",");
}