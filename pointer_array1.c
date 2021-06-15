#include<stdio.h>
void method1()
{
    int array[2][2];
    array[0][1]=1;
    array[0][2]=2;
    array[1][2]=4;
    array[1][0]=9;
    printf("%d",*(*(array+1)+2));
}

int method2()
{
    int arr[3][4] = {
                        {11,22,33,44},
                        {55,66,77,88},
                        {11,66,77,44}
                    };

    int i, j;

    for(i = 0; i < 3; i++)
    {
        printf("Address of %d th array %u \n",i , *(arr + i));
        for(j = 0; j < 4; j++)
        {
             printf("arr[%d][%d]=%d\n", i, j, *( *(arr + i) + j) );
        }
        printf("\n\n");
    }

    // signal to operating system program ran fine
    return 0;
}


int main()
{
     char name[10][20];
     int i,n;

     printf("Enter the number of names (<10): ");
     scanf("%d",&n);

     // reading string from user
     printf("Enter %d names:\n",n);
     for(i=0; i<n; i++)
     scanf("%s[^\n]",name[i]);

     // Dispaying strings
     printf("\nEntered names are:\n");
     for(i=0;i<n;i++)
     puts(name[i]);

     return 0;
}
