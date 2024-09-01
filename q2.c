#include <stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
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
    for (i = 0; i < n - 1; i += 2)
        printf("GCD of %d and %d = %d \n", arr[i], arr[i + 1], gcd(arr[i], arr[i + 1]));
    return 0;
}