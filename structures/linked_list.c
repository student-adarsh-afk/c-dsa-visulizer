
#include "../include/linked_list.h"
#include "../include/utils.h"


node* head = NULL;

    node*createNode(int data){

    node *newNode = (node*)malloc(sizeof(node));
    if(!newNode){
        printf(RED "Memory allocation failed.\n" RESET);
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
    }

   void printList() {
    clearScreen();
    if (head == NULL) {
        printf(RED "List is empty.\n" RESET);
        return;
    }
    printf(GREEN "Linked List elements:\n" RESET);
    node* temp = head;
    while (temp != NULL) {
        
        printf("[%3d | %p] -> ", temp->data, (void*)temp->next);
        if (temp->next == NULL) {
            printf("NULL\n");
        }
        
        temp = temp->next;
    }

}



    void insert(int data){
        node* newNode = createNode( data);
        if (head == NULL) {
            head=newNode;
            printf(GREEN "Inserted: %d\n" RESET, data);
            printList();
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        printf(GREEN "Inserted: %d\n" RESET, data);
        printList();
    }

    void deleteNode(int data){
        node*temp=head;
        node*prev=NULL;
        while(temp!=NULL && temp->data!=data){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf(RED "Element not found.\n" RESET);
            return;
        }
        if(prev==NULL){
            head=temp->next;
        }
        else{
            prev->next=temp->next;
        }
        printf(GREEN "Deleted: %d\n" RESET, data);
        printList();
        free(temp);
        return;
    }

    void freeList(){
        node* temp = head;
        while (temp != NULL) {
            node* next = temp->next;
            free(temp);
            temp = next;
        }
        head = NULL;
    }



    void linkedListMenu(){
        while(1){
            printf("\n======linked list visulizer======\n");
            printf("1. insert\n");
            printf("2. delete\n");
            printf("3. display\n");
            printf("4. exit\n");
            int choice;
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1: {
                    int data;
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insert( data);
                    break;
                }
                case 2: {
                    int data;
                    printf("Enter data to delete: ");
                    scanf("%d", &data);
                    deleteNode( data);
                    break;
                }
                case 3:
                    printList();
                    break;
                case 4:
                    freeList();
                    exit(0);
                default:
                    printf(RED "Invalid choice. Please try again.\n" RESET);
            }
        }
    }
