#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;

   // use appropriate location if you are using MacOS or Linux


    if ((fptr = fopen("D:/Files/C_Files/Filepractice.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

   fscanf(fptr,"%d",&num);
   printf("%d",num);
   fclose(fptr);

   return 0;
}
