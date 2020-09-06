#pragma once

#include <iostream>
#include <stdlib.h>

typedef struct Node NODE, *PNODE;
struct Node
{
	double value;
	PNODE next;
};

// ��ʼ������
PNODE newLinkedList();

// ��������С
int size(PNODE head);

// ʹ��β�����Ԫ��
void add(PNODE head, double value);

// ָ���±����Ԫ��
void add(PNODE head, int index, double value);

// ���ָ���±�Ԫ��
double get(PNODE head, int index);

// �Ƴ�ָ��Ԫ��
void remove(PNODE head, double value);

// �Ƴ�ָ���±�Ԫ��
double remove(PNODE head, int index);

// �Ƴ�ָ��Ԫ�ص�ȫ���ڵ�
void removeAll(PNODE head, double value);

// �������
void clear(PNODE head);

// �ж��Ƿ�Ϊ��
bool isEmpty(PNODE head);

// ��¡����
PNODE clone(PNODE head);

// ��ӡ����
void print(PNODE head);