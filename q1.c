#include <stdio.h>
void decBin(int n, int i, int *bin)
{
    if (n == 0)
        return;
    bin[i] = n % 2;
    decBin(n / 2, i + 1, bin);
}
int main()
{
    int n;
    printf("Enter n = ");
    scanf("%d", &n);
    int arr[n], i;
    printf("Enter %d values \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < n; i++)
    {
        int bin[16] = {0};
        decBin(arr[i], 0, bin);
        int j;
        for (j = 15; j >= 0; j--)
            printf("%d", bin[j]);
        printf("\n");
    }
    return 0;
}