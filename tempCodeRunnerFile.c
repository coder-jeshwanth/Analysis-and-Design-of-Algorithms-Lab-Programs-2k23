#include<stdio.h>
#include<conio.h>
int w[50],p[50],i,n,capacity,maxprofit;
int maximum(int x,int y){
    if(x>y)
    {
        return x;
    }
    else
    return y;
}
knapsack(int i, int c)
{
    if(i==n)
    return((c<w[n])?0: p[n]);

    if(c<w[i])
    return knapsack(i+1,c);
    return maximum(knapsack(i+1,c),knapsack(i+1,c-w[i])+p[i]);
}
void main()
{
    printf("Enter the no of objects: ");
    scanf("%d",&n);

    printf("Enter the weights: \n");
    for(i=0;i<n;i++)
    scanf("%d",&w[i]);

    printf("Enter the profits: \n");
    for(i=0;i<n;i++)
    scanf("%d",&p[i]);

    printf("Enter the capacity: \n");
    scanf("%d",&capacity);

    maxprofit = knapsack(0,capacity);
    printf("\nmaximum profit = %d",maxprofit);
    getch();

}