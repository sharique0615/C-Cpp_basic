
//q1
//21052790

#include <stdio.h>

int leftmostBinarySearch(int arr[], int size, int key, int *comparisons) {
    int left = 0, right = size - 1;
    int position = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        (*comparisons)++;
        
        if (arr[mid] == key) {
            position = mid;
            right = mid - 1; 
        } else if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return position;
}

int main() {
    int size, key;
    printf("Enter size of array: ");
    scanf("%d", &size);
    
    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    int comparisons = 0;
    int position = leftmostBinarySearch(arr, size, key, &comparisons);
    
    if (position != -1) {
        printf("%d found at index position %d\n", key, position);
    } else {
        printf("%d not found in the array\n", key);
    }
    printf("Number of comparisons: %d\n", comparisons);
    
    return 0;
}
