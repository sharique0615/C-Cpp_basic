#include <stdio.h>

// Structure for an item which stores weight and corresponding value of Item
struct Item {
    int profit, weight;
};

// Comparison function to sort Item according to profit/weight ratio
static int cmp(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;

    double r1 = (double)item1->profit / (double)item1->weight;
    double r2 = (double)item2->profit / (double)item2->weight;

    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

// Main greedy function to solve problem
double fractionalKnapsack(int W, struct Item arr[], int N) {
    // Sorting Item on basis of ratio
    qsort(arr, N, sizeof(struct Item), cmp);

    double finalvalue = 0.0;

    // Looping through all items
    for (int i = 0; i < N; i++) {
        // If adding Item won't overflow, add it completely
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        // If we can't add current Item, add fractional part of it
        else {
            finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }

    // Returning final value
    return finalvalue;
}

// Driver code
int main() {
    int W = 50;
    struct Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Function call
    printf("%lf", fractionalKnapsack(W, arr, N));
    return 0;
}
