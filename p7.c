#include <stdio.h>
#include <conio.h>
int i, j, a[20][20], visited[20], n, label = 0, k, I[10], v, w;

void initiate()
{
    for (i = 1; i <= n; i++)
        visited[i] = 0, I[i] = 0;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = 0;
}
void dfs(int v)
{
    visited[v] = 1;
    I[v] = label;
    for (i = 1; i <= n; i++)
        if (a[v][i] && visited[i] == 0)
            dfs(i);
}
void component_label()
{
    int i;
    for (i = 1; i <= n; i++)
    {
        if (I[i] == 0)
        {
            label++;
            for (k = 1; k <= n; k++)
                visited[i] = 0;
            dfs(i);
        }
    }
    if (label > 1)
        printf("\nDisconnected Graph.");
    else
        printf("\nConnected graph");
    printf("\nNo of connected elements:%d", label);
    for (i = 1; i <= n; i++)
        printf("\nVertex %d belongs to component %d", i, I[i]);
}
void main()
{
    char ch;
    printf("\nEnter the no vertices: ");
    scanf("%d", &n);

    initiate();
    do
    {
        printf("\nEnter the adjacent vertices: ");
        scanf("%d%d", &v, &w);
        if (v < 0 || v > n || w < 0 || w > n)
            printf("\nInvalid vertex.");
        else
        {
            a[v][w] = 1;
            a[w][v] = 1;
        }
        printf("\nDo you want to continue:");
        fflush(stdin);
        scanf("%c", &ch);
    } while (ch == 'y' || ch == 'y');
    printf("The adjacency matrix is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%3d", a[i][j]);
        printf("\n");
    }
    component_label();
    getch();
}