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

// 创建栈
PSTACK newStack();

// 判断是否为空
bool isEmpty(PSTACK stack);

// 进栈
int push(PSTACK stack, datatype value);

// 出栈
int pop(PSTACK stack, datatype *value);

// 取栈顶
int getTop(PSTACK stack, datatype *value);