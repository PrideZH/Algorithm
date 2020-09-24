#include "stack.h"

PSTACK newStack() {
	PSTACK stack = (PSTACK)malloc(sizeof(STACK));
	stack->top = -1;
	return stack;
}

bool isEmpty(PSTACK stack) {
	return stack->top == -1;
}

int push(PSTACK stack, datatype value) {
	if (stack->top == MAXSIZE - 1) 
		return 0;

	stack->data[++stack->top] = value;
	return 1;
}

int pop(PSTACK stack, datatype *value) {
	if (isEmpty(stack))
		return 0;

	*value = stack->data[stack->top--];
	return 1;
}

int getTop(PSTACK stack, datatype *value) {
	if (isEmpty(stack))
		return 0;

	*value = stack->data[stack->top];
	return 1;
}