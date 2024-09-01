#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        (*comparisons)++;
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons);
        quickSort(arr, low, pi - 1, comparisons);
        quickSort(arr, pi + 1, high, comparisons);
    }
}
void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    FILE *inputFile, *outputFile;
    int option;
    int comparisons = 0;

    do {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        printf("Enter option: ");
        scanf("%d", &option);

        if (option >= 1 && option <= 3) {
            char inputFileName[20], outputFileName[20];
            if (option == 1) {
                strcpy(inputFileName, "inAsce.dat");
                strcpy(outputFileName, "outQuickAsce.dat");
            } else if (option == 2) {
                strcpy(inputFileName, "inDesc.dat");
                strcpy(outputFileName, "outQuickDesc.dat");
            } else {
                strcpy(inputFileName, "inRand.dat");
                strcpy(outputFileName, "outQuickRand.dat");
            }

            inputFile = fopen(inputFileName, "r");
            if (inputFile == NULL) {
                printf("Error opening input file.\n");
                exit(1);
            }

            int size;
            fscanf(inputFile, "%d", &size);
            int arr[size];

            for (int i = 0; i < size; i++) {
                fscanf(inputFile, "%d", &arr[i]);
            }

            fclose(inputFile);

            comparisons = 0;
            quickSort(arr, 0, size - 1, &comparisons);

            outputFile = fopen(outputFileName, "w");
            if (outputFile == NULL) {
                printf("Error opening output file.\n");
                exit(1);
            }

            for (int i = 0; i < size; i++) {
                fprintf(outputFile, "%d ", arr[i]);
            }

            fclose(outputFile);

            printf("Before Sorting: ");
            displayArray(arr, size);
            printf("After Sorting: ");
            displayArray(arr, size);
            printf("Number of Comparisons: %d\n", comparisons);

            if (comparisons == (size * (size - 1)) / 2) {
                printf("Scenario: Best-case partitioning\n");
            } else if (comparisons == (size * (size - 1))) {
                printf("Scenario: Worst-case partitioning\n");
            } else {
                printf("Scenario: Neither best-case nor worst-case partitioning\n");
            }
        } else if (option != 4) {
            printf("Invalid option.\n");
        }
    } while (option != 4);

    return 0;
}
