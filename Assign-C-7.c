#include<stdio.h>
#include<math.h>
void main()
{

    int a,b,sum=0,remainder,reverse=0;
    printf("Enter the number whos has to checked for palindrome:\t\n");
    scanf("%d",&a);
    b=a;
    while (a!=0)
    {
        remainder=a%10;
        reverse=reverse*10+remainder;
        a=a/10;
    }
    if(reverse==b) printf("Palindrome\n");
    else printf("Not Palindrome\n");


}
