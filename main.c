
#include "../include/queue.h"
#include "../include/stack.h"
#include "../include/linked_list.h"
#include "../include/utils.h"
#include "../include/merge_sort.h"

void mainMenu(){
    
    printf("===welcome to data structure visualizer===\n");
    printf("1. Stack\n");
    printf("2. Queue\n");
    printf("3. Linked List\n");
    printf("4. Binomial Search\n");
    printf("5. Merge Sort\n");
    printf("6. Exit\n");


    printf( "Enter your choice: " );
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            clearScreen();
            stackMenu();
            break;
        case 2:
            clearScreen();
            queueMenu(); // Placeholder for queue menu
            break;
        case 3:
            clearScreen();
            linkedListMenu(); // Placeholder for linked list menu
            break;
        case 4:
            system("binomial_search.exe");
            break;
        case 5:
            clearScreen();
            mergeMenu();
            break;
        case 6:
            clearScreen();
            printf("Exiting...\n");
            exit(0);

        default:
            clearScreen();
            printf("Invalid choice! Please try again.\n");
            mainMenu();
    }
}

int main() {
    
    mainMenu();
    return 0;
}