#ifndef QUEUE_H
#define QUEUE_H

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m" 
#define CYAN "\033[1;36m"


#define MAX 10
    extern int queue[MAX];


void printQueue();
void enqueue(int value);
void dequeue();
void queueMenu();








#endif