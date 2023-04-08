#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main(void)
{
   int letter=0;
   int word=1;
   int sentence=0;

   string text= get_string("text: ");

   int texlenght= strlen(text);

   for(int i=0;i<texlenght;i++)
   {
       if(isalpha(text[i]))
       {
          letter++;
       }
   }

   for(int i=0;i<texlenght;i++)
   {
    if(isspace(text[i]))
    {
        word++;
    }
   }

   for(int i=0;i<texlenght;i++)
   {
    if(text[i]=='.' || text[i]=='?' || text[i]=='!')
    {
        sentence++;
    }
   }

   float calc = (0.0588 * letter / word * 100) - (0.296 * sentence / word * 100) - 15.8;

   int x = round(calc);

   if(x < 1)
   {
    printf("Before Grade 1\n");
   }

   else if(x > 16)
   {
    printf("Grade 16+\n");
   }

   else
   {
    printf("Grade %i",x);
    printf("\n");
   }