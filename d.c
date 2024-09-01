#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int comparisons = 0;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        comparisons++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void readInputFile(int arr[], int size, const char *filename) {
    FILE *file = fopen(filename, "r");
    for (int i = 0; i < size; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
}

void writeOutputFile(int arr[], int size, const char *filename) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}

int main() {
    while (1) {
        printf("MAIN MENU (MERGE SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. Exit\n");

        int option;
        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 4) {
            break;
        }

        const char *inputFilename;
        const char *outputFilename;

        if (option == 1) {
            inputFilename = "inAsce.dat";
            outputFilename = "outMergeAsce.dat";
        } else if (option == 2) {
            inputFilename = "inDesc.dat";
            outputFilename = "outMergeDesc.dat";
        } else if (option == 3) {
            inputFilename = "inRand.dat";
            outputFilename = "outMergeRand.dat";
        } else {
            printf("Invalid option. Please select a valid option.\n");
            continue;
        }

        int size;
        printf("Enter the size of the array: ");
        scanf("%d", &size);

        int arr[size];
        readInputFile(arr, size, inputFilename);
        printf("Before Sorting: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        comparisons = 0;
        clock_t startTime = clock();
        mergeSort(arr, 0, size - 1);
        clock_t endTime = clock();

        printf("After Sorting: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        printf("Number of Comparisons: %lld\n", comparisons);

        double executionTime = ((double)(endTime - startTime)) / CLOCKS_PER_SEC * 1e9;
        printf("Execution Time (nanoseconds): %f\n", executionTime);

        writeOutputFile(arr, size, outputFilename);
        printf("Sorted data written to %s\n", outputFilename);
    }

    return 0;
}
