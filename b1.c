#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int s[10] = {0};

void dfs(int n,int a[50][50],int u)
{
    int v;
    s[u]=1;
    printf("%d",u);
    for(v=1;v<=n;v++)
    if(a[u][v] == 1 && s[v] == 0)
    dfs(n,a,v);
}

void main()
{
    int i,j,n,a[50][50],src;

    printf("Enter the no of objects: ");
    scanf("%d",&n);

    printf("Enter the adjacency of matrix: \n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);

    printf("Enter the source vertex\n");
    scanf("%d",&src);

    if(src<=n)
    {
        dfs(n,a,src);
        printf("\nThe nodes which are reachable from %d are: \n ",src);
        for(i=1;i<=n;i++)
        if(s[i])
        printf("%d",i);
    }
    else
    printf("try again later");
}