//c program to read a 2d array and then represent the same array as sparse matrix



#include<stdio.h>
int main()
{
int row,col,i,j,k=0;
int arr[10][10],sm[100][3];
printf("Enter number of rows: ");
scanf("%d",&row);
printf("Enter number of cols: ");
scanf("%d",&col);
printf("Enter no. of elements for the (%dX%d) matrics:\n",row,col);
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
scanf("%d",&arr[i][j]);
if(arr[i][j]!=0)
{
sm[k][0]=i;
sm[k][1]=j;
sm[k][2]=arr[i][j];
k++;
}
}
}
printf("Row\tColumn\tValue\n");
for(i=0;i<k;i++)
printf("%d\t%d\t%d\n",sm[i][0],sm[i][1],sm[i][2]);
}
