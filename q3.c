#include <stdio.h>
int main()
{
    int a, b, n, count = 0;
    printf("enter size of an array : \n");
    scanf("%d", &n);
      printf("enter elemnts of an array : \n");
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break;
            }
        }
    }
    printf("duplicate elements : %d", count);
    int mostRepeatingElement = arr[0];
    int maxRepeats = 0;
    for (int i = 0; i < n; i++)
    {
        int currentElement = arr[i];
        int repeats = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] == currentElement)
            {
                repeats++;
            }
        }
        if (repeats > maxRepeats)
        {
            mostRepeatingElement = currentElement;
            maxRepeats = repeats;
        }
    }
    printf("\nmost repeating elements : %d", mostRepeatingElement);
}