#if !defined(DSA_STACK_H)
#define DSA_STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct Stack {
    int top;
    size_t capacity;
    int *array;
} Stack;

Stack *create_stack(size_t capacity);
bool is_full(Stack *stack);
bool is_empty(Stack *stack);
void push(Stack *stack, int item);
int pop(Stack *stack);
int peek(Stack *stack);
void free_stack(Stack *stack);

#endif // DSA_STACK_H