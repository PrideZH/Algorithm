#pragma once

#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef int datatype;

typedef struct Stack STACK, *PSTACK;
struct Stack {
	datatype data[MAXSIZE];
	int top;
};

// ����ջ
PSTACK newStack();

// �ж��Ƿ�Ϊ��
bool isEmpty(PSTACK stack);

// ��ջ
int push(PSTACK stack, datatype value);

// ��ջ
int pop(PSTACK stack, datatype *value);

// ȡջ��
int getTop(PSTACK stack, datatype *value);