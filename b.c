//21052790
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int size, int *comparisons) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            (*comparisons)++;
        }
        
        arr[j + 1] = key;
    }
}

void displayFileContents(const char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening the file %s\n", filename);
        return;
    }
    
    printf("Content of the file %s:\n", filename);
    int num;
    while (fscanf(file, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    
    fclose(file);
    printf("\n");
}

int main() {
    int choice;
    
    do {
        printf("MAIN MENU (INSERTION SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. EXIT\n");
        
        printf("Enter option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
            case 2:
            case 3: {
                char inputFileName[20];
                char outputFileName[20];
                int arr[500];
                int size;
                int comparisons = 0;
                
                switch (choice) {
                    case 1:
                        strcpy(inputFileName, "inAsce.dat");
                        strcpy(outputFileName, "outInsAsce.dat");
                        break;
                    case 2:
                        strcpy(inputFileName, "inDesc.dat");
                        strcpy(outputFileName, "outInsDesc.dat");
                        break;
                    case 3:
                        strcpy(inputFileName, "inRand.dat");
                        strcpy(outputFileName, "outInsRand.dat");
                        break;
                }
                
                FILE *inputFile = fopen(inputFileName, "r");
                
                if (inputFile == NULL) {
                    printf("Error opening the input file %s\n", inputFileName);
                    break;
                }
                
                size = 0;
                while (fscanf(inputFile, "%d", &arr[size]) != EOF) {
                    size++;
                }
                fclose(inputFile);
                
                insertionSort(arr, size, &comparisons);
                
                FILE *outputFile = fopen(outputFileName, "w");
                
                if (outputFile == NULL) {
                    printf("Error opening the output file %s\n", outputFileName);
                    break;
                }
                
                for (int i = 0; i < size; i++) {
                    fprintf(outputFile, "%d ", arr[i]);
                }
                fclose(outputFile);
                
                printf("Before Sorting:\n");
                displayFileContents(inputFileName);
                
                printf("After Sorting:\n");
                displayFileContents(outputFileName);
                
                printf("Number of comparisons: %d\n", comparisons);
                
                break;
            }
            case 4:
                printf("out\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);
    
    return 0;
}
