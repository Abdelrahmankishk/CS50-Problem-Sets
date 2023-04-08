#include<cs50.h>
#include<stdio.h>


int main(void)
{
    int height;

    do
    {
        height = get_int("height: ");
    }
    while(height < 1 || height >= 9);

    for(int i = 0;i<height;i++)
    {
         for(int z = height - i - 1;z>0;z--)
         {

            printf(" ");

         }

         for(int b = 0;b<i+1;b++)
         {

            printf("#");

         }

        printf("\n");

    }

}