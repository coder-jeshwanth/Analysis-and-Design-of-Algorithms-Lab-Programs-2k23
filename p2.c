#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int binarySearch(int a[], int key, int n, int first, int last)
{
    int mid, i, j, temp;
    if (last < first)
        return -1;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    while (first <= last)
    {
        mid = (first + last) / 2;
        if (key == a[mid])
            return mid + 1;
        else if (key < a[mid])
            last = mid - 1;
        else
            first = mid + 1;
    }
    return -1;
}

int main()
{
    char ch;
    int a[100], n, i, key, res, first, last;
    clock_t st, et;

    printf("Enter the number of elements in the array:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter the key element to search:\n");
    scanf("%d", &key);

    first = 0;
    last = n - 1;

    st = clock();
    res = binarySearch(a, key, n, first, last);
    printf("The sorted array is:");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    et = clock();
    double time_taken = (((double)(et - st)) / CLOCKS_PER_SEC) * 1000;

    if (res == -1)
    {
        printf("\nThe search element is not found\n");
        printf("The execution time is = %f milliseconds.\n", time_taken);
        exit(0);
    }
    else
    printf("\nThe search element is found at position %d.\n", res);
    printf("The execution time is = %d. of Milli seconds", time_taken);
}
