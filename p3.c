#include <stdio.h>
#include <conio.h>
#include <time.h>
void quicksort(int A[10], int low, int high)
{
    int j;
    if (low < high)
    {
        j = partition(A, low, high);
        quicksort(A, low, j - 1);
        quicksort(A, j + 1, high);
    }
}
int partition(int A[10], int low, int high)
{
    int pivot, j, temp, i;
    pivot = low;
    i = low;
    j = high;
    while (i < j)
    {
        while (i < high && A[i] <= A[pivot])
            i++;
        while (A[j] > A[pivot])
            j--;
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[pivot];
    A[pivot] = A[j];
    A[j] = temp;
    return j;
}
void main()
{
    int i, n, A[10];
    clock_t st, et;

    printf("Enter the number of elements of array:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);

    st = clock();
    quicksort(A, 0, n - 1);
    et = clock();

    double time_taken = (((double)(et - st)) / CLOCKS_PER_SEC) * 1000;

    printf("Sorted list of elements:");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\nThe execution time is = %d. of Milli seconds", time_taken);
    getch();
}