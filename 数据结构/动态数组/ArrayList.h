#pragma once

#include <iostream>
#include <stdlib.h>

typedef struct Node *ArrayList;
struct Node
{
	int *array; // ����
	int length; // ����ռ��С
	int size; // Ԫ����
};

// �������� Ĭ�ϴ�СΪ10
ArrayList newArrayList();

// ��������ָ�������С
ArrayList newArrayList(int length);

// ���Ԫ��
void add(ArrayList list, int value);

// ָ���±����Ԫ��
void add(ArrayList list, int index, int value);

// ���ָ���±�Ԫ��
double get(ArrayList list, int index);

// ɾ��ָ���±�Ԫ��
double remove(ArrayList list, int index);

// ɾ��ָ���ĵ�һ�����ֵ�Ԫ��
void remove(ArrayList list, double value);

// ɾ��ָ��������Ԫ��
void removeAll(ArrayList list, double value);

// ��������С
int size(ArrayList list);

// �ж��Ƿ�Ϊ��
bool isEmpty(ArrayList list);

// ���Ԫ��
void clear(ArrayList list);

// ��������
ArrayList clone(ArrayList list);

// ˳������ ʹ�ÿ���
void sort(ArrayList list);

// ��ӡ
void print(ArrayList list);

