#include"../include/utils.h"
#include "../include/binomial_search.h"



void print_array_with_markers(int arr[], int n, int left, int mid, int right) {
    for (int i = 0; i < n; ++i) {
        if (i == mid) {
            printf( CYAN "[%2d]" RESET " ", arr[i]);
        } 
        else if(i==left ||i==right){
            printf(GREEN " %2d " RESET " ", arr[i]);
        }
        else if (i < left) {
            printf(RED " %2d " RESET " ", arr[i]);
        } else if (i > right) {
            printf(RED " %2d " RESET " ", arr[i]);
        } else {
            printf(" %2d  ", arr[i]);
        }
    }
    printf("\n");
}


void binomialVisualize(int arr[], int size,int target) {
    int st=0;
    int end=size-1;

    while(st<=end){
        int mid= st + (end - st) / 2;
        if(arr[mid]==target){
            print_array_with_markers(arr, size, st, mid, end);
            printf(GREEN "Found %d at index %d\n" RESET, target, mid);
            return;
        }
        else if(arr[mid]<target){
            print_array_with_markers(arr, size, st, mid, end);
            st=mid+1;
        }
        else{
            print_array_with_markers(arr, size, st, mid, end);
            end=mid-1;
        }
    }
    printf(RED "Element not found.\n" RESET);
}

int main(){
    printf("\033[H\033[J");
    printf("=== Binomial Search Visualizer ===\n");
    int arr[] = {74,84,96,110,115,122,134,145,156,176,189,201,214,227,240,252,265,287,300,};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("array is :");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }


    while(1){
        char choice;
        int target;
        printf("\nEnter the element to search: ");
        scanf("%d", &target);
        binomialVisualize(arr, size, target);

        printf("Do you want to search another element? (y/n): ");
        scanf(" %c", &choice);
        if (choice != 'y') {
            break;
        }
    }

    // printf("\nEnter the element to search: ");
    
    // int target;
    // scanf("%d", &target);

    // binomialVisualize(arr, size, target);

    return 0;
}

