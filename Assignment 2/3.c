//c program to pass an array to a function using call by reference ,update the array values in the function print the array elements both in the function and in the calling function

#include<stdio.h>
void update_array(int *arr,int size);
int main()
{
	int s;
	printf("Enter size of array :");
	scanf("%d",&s);
	int a[s];
	printf("Enter Array Elements :\n");
	for(int i=0;i<s;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("The array elements in the main function (Before updation) :\n");
	for(int i=0;i<s;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	update_array(a,s); //calling the function by array reference
	printf("The array elements in the main function (After updation) :\n");
	for(int i=0;i<s;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
void update_array(int *arr,int size)
{
	for(int i=0;i<size;i++)
	{
		arr[i]+=15; //updating array by adding 15 with each element
	}
	printf("The array elements in the called function (After updation) :\n");
	for(int i=0;i<size;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}
