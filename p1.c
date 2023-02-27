#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int linearSearch(int a[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (key == a[i])
            return i;
    }
    return -1;
}
void main()
{
    int a[100], n, key, i, res;
    clock_t st, et;

    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the key element to search:\n");
    scanf("%d", &key);

    st = clock();
    res = linearSearch(a, n, key);
    et = clock();
    double time_taken = (((double)(et - st)) / CLOCKS_PER_SEC) * 1000;

    if (res == -1)
    {
        printf("The search element is not found\n");
        printf("The execution time is = %d. of Milli seconds", time_taken);
        exit(0);
    }
    else
    printf("The search element is found at position %d\n", res + 1);
    printf("The execution  time is = %d. of Milli seconds", time_taken);
}