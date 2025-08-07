#include <stdio.h>
#include <stdlib.h>
#include "../include/stack.h"

Stack *create_stack(size_t capacity) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (!stack) {
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    if (!stack->array) {
        free(stack);
        return NULL;
    }
    return stack;
}

bool is_full(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

bool is_empty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int item) {
    if (is_full(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        return -1;  // Stack underflow
    }
    return stack->array[stack->top--];
}

int peek(Stack *stack) {
    if (is_empty(stack)) {
        return -1;  // Stack is empty
    }
    return stack->array[stack->top];
}

void free_stack(Stack *stack) {
    if (stack) {
        free(stack->array);
        free(stack);
    }
}
