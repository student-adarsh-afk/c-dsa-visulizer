#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

int front = 0;
int rear = -1;
int queue[MAX];

void printQueue (){
     clearScreen();
     // printf("-------------\n");
     if(front>rear){
          printf(RED "Queue is empty.\n" RESET);
          return;
     }

     
     printf(GREEN"Queue elements:\n \n" RESET);
     printf(CYAN "Front -> " RESET);
     for(int i = front; i <= rear; i++){
          printf("|%d ", queue[i]);
     }
     printf("|");
     printf(CYAN "<- Rear\n" RESET);
     
}


void enqueue(int value){
     if(rear == MAX - 1){
          printf(RED "Queue is full.\n" RESET);
          return;
     }
     queue[++rear] = value;
     printf(GREEN "Enqueued: %d\n" RESET, value);
}

void dequeue(){
     if(front>rear){
          printf(RED "Queue is empty.\n" RESET);
          return;
     }
     front++;
     printf(GREEN "Dequeued: %d\n" RESET, queue[front - 1]);
}

void queueMenu(){
     int value,choice;
     while(1){
          printf("\n====== Queue Visualizer ======\n");
          printf("1. Enqueue\n");
          printf("2. Dequeue\n");
          printf("3. Print Queue\n");
          printf("4. Exit\n");
          printf("Enter choice: ");
          scanf("%d", &choice);

          switch(choice){
               case 1:
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(value);
                    break;
               case 2:
                    dequeue();
                    break;
               case 3:
                    printQueue();
                    break;
               case 4:
                    exit(0);
               default:
                    printf(RED "Invalid choice. Try again.\n" RESET);
          }
     }
}
