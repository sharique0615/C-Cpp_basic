#include <stdio.h>
#include <stdlib.h>

typedef struct ITEM {
  int item_id;
  float item_profit;
  float item_weight;
  float profit_weight_ratio;
} ITEM;

int compare_items(const void *a, const void *b) {
  ITEM *i1 = (ITEM *)a;
  ITEM *i2 = (ITEM *)b;
  return i1->profit_weight_ratio > i2->profit_weight_ratio ? -1 : 1;
}

float fractional_knapsack(int n, ITEM items[], float capacity) {
  float max_profit = 0.0f;
  float current_capacity = 0.0f;

  qsort(items, n, sizeof(ITEM), compare_items);

  for (int i = 0; i < n; ++i) {
    if (current_capacity + items[i].item_weight <= capacity) {
      current_capacity += items[i].item_weight;
      max_profit += items[i].item_profit;
      items[i].profit_weight_ratio = 1.0f;
    } else {
      float remaining_capacity = capacity - current_capacity;
      float fraction = remaining_capacity / items[i].item_weight;
      max_profit += fraction * items[i].item_profit;
      items[i].profit_weight_ratio = fraction;
      break;
    }
  }

  printf("Item No\tProfit\tWeight\tAmount to be taken\n");
  for (int i = 0; i < n; ++i) {
    printf("%d\t%.2f\t%.2f\t%.2f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, items[i].profit_weight_ratio);
  }

  return max_profit;
}

int main() {
  int n;
  printf("Enter the number of items: ");
  scanf("%d", &n);

  ITEM items[n];
  for (int i = 0; i < n; ++i) {
    printf("Enter the profit and weight of item no %d: ", i + 1);
    scanf("%f %f", &items[i].item_profit, &items[i].item_weight);
    items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    items[i].item_id = i + 1;
  }

  float capacity;
  printf("Enter the capacity of knapsack:");
  scanf("%f", &capacity);

  float max_profit = fractional_knapsack(n, items, capacity);
  printf("Maximum profit: %.2f\n", max_profit);

  return 0;
}