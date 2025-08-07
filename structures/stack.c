#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep()

#define MAX 5

int stack[MAX];
int top = -1;

// ANSI color codes (optional)
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"      //

// Function to clear screen (optional)
void clearScreen() {
    printf("\033[2J\033[1;1H");  // ANSI escape code to clear terminal
}

// Stack Visual Display
void printStack() {
    clearScreen();
    printf("Current Stack:\n");
    printf("--------------\n");

    if (top == -1) {
        printf(RED "Stack is empty.\n" RESET);
        return;
    }

    for (int i = top; i >= 0; i--) {
        printf("|   %d   |\n", stack[i]);
        printf("--------\n");
    }

    printf(GREEN "TOP --> %d\n" RESET, stack[top]);
}

// Push operation
void push(int value) {
    if (top == MAX - 1) {
        printf(RED "Stack Overflow!\n" RESET);
        sleep(1);
        return;
    }
    stack[++top] = value;
    printStack();
    sleep(1);
}

// Pop operation
void pop() {
    if (top == -1) {
        printf(RED "Stack Underflow!\n" RESET);
        sleep(1);
        return;
    }
    printf(GREEN "Popped: %d\n" RESET, stack[top--]);
    sleep(1);
    printStack();
}

// Menu
void stackMenu() {
    int choice, value;
    while (1) {
        printf("\n====== Stack Visualizer ======\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printStack();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}


