#if !defined(DSA_STACK_H)


#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"  

void clearScreen();
void printStack();
void push(int value);
void pop();
void stackMenu();



#endif // DSA_STACK_H