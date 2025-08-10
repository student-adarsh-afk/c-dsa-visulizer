#include "../include/merge_sort.h"

#include "../include/utils.h"

// Helper to print subarray
void printSubArray(int arr[], int start, int end) {
    printf("[");
    for (int i = start; i <= end; i++) {
        printf("%d", arr[i]);
        if (i < end) printf(", ");
    }
    printf("]");
}

// Merge function with your style + visualization
void merge(int arr[], int size, int st, int mid, int end) {
    // Show what’s being merged
    printSubArray(arr, st, mid);
    printf(" + ");
    printSubArray(arr, mid + 1, end);
    printf(CYAN " = "RESET);

    int temp[end - st + 1];
    int i = st, j = mid + 1, k = 0;

    while (i <= mid && j <= end)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= end) temp[k++] = arr[j++];

    for (i = st, k = 0; i <= end; i++, k++)
        arr[i] = temp[k];

    // Show result after merge
    printSubArray(arr, st, end);
    printf("\n");
}

// Recursive merge sort with splitting print
void mergeSort(int arr[], int size, int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;

        // Show split
        printf(CYAN"Split: "RESET);
        printSubArray(arr, st, end);
        printf(" "CYAN"INTO"RESET" ");
        printSubArray(arr, st, mid);
        printf(CYAN" + "RESET);
        printSubArray(arr, mid + 1, end);
        printf("\n");

        mergeSort(arr, size, st, mid);
        mergeSort(arr, size, mid + 1, end);
        merge(arr, size, st, mid, end);
    }
}

int *arr;
int size;

void mergeMenu(){
    while(1){
        int choice;
        
        printf("\n====== Merge Sort Visualizer ======\n");
        printf("1. Enter array elements\n");
        printf("2. Visualize merge sort\n");
        printf("3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("Enter the number of elements: ");
            scanf("%d", &size);
            arr = (int*)malloc(size * sizeof(int));
            printf("Enter the elements:\n");
            for (int i = 0; i < size; i++) {
                scanf("%d", &arr[i]);
            }
            break;
            case 2:
                if (arr == NULL) {
                    printf(RED"Please enter the array elements first.\n"RESET);
                    break;;
                }
                mergeSort(arr, size, 0, size - 1);
                break;
            case 3:
                printf(RED"Exiting...\n"RESET);
                return;
            default:
                printf(RED"Invalid choice. Please try again.\n"RESET);
        }
    }
}
