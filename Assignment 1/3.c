#include<stdio.h>
 int main()
{
    float Centigrade,Fahrenheit;
    printf("\n Enter the Temparature in Centigrade : ");
    scanf("%f",&Centigrade);
    Fahrenheit =(Centigrade*9/5)+ 32;
    printf("%f Centigrade =%f Fahrenheit\n", Centigrade,Fahrenheit);
 return 0;
}
