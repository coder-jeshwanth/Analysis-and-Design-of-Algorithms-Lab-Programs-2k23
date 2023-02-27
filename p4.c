#include <stdio.h>
#include <conio.h>
#include <time.h>

void Merge(int A[10], int low, int mid, int high)
{
    int i, j, k, c[10];
    i = low;
    k = low;
    j = mid + 1;
    while ((i <= mid) && (j <= high))
    {
        if (A[i] <= A[j])
        {
            c[k] = A[i];
            i++;
            k++;
        }
        else
        {
            c[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        c[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = A[j];
        k++;
        j++;
    }
    for (i = low; i <= k - 1; i++)
        A[i] = c[i];
}

void MergeSort(int A[10], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, mid, high);
    }
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
    MergeSort(A, 0, n - 1);
    et = clock();

    double time_taken = (((double)(et - st)) / CLOCKS_PER_SEC) * 1000;

    printf("sorted list of elements:");
    for (i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\nThe execution time is = %lf. of Milli seconds", time_taken);
    getch();
}
