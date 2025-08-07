#include <stdio.h>
#include <stdlib.h>

#include "../include/stack.h"

int main() {
    Stack *stack = create_stack(10);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    free_stack(stack);
}