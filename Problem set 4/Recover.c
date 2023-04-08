#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
 if(argc != 2)
 {
    printf("Usage: ./recover card.raw\n");
    return 1;
 }
 FILE *input_file = fopen(argv[1], "r");
 if(input_file == NULL){
        printf("Could not open file\n");
        return 2;
 }
 unsigned char me[512];

 int image_count=0;

 FILE *outputfile = NULL;
 char *filename = malloc(8 * sizeof(char));


while(fread(me, sizeof(char), 512, input_file) != 0)
{
    if(me[0] == 0xff && me[1] == 0xd8 && me[2] == 0xff && (me[3] & 0xf0) == 0xe0)
    {
        sprintf(filename,"%03i.jpg",image_count);
        outputfile = fopen(filename,"w");
        image_count++;
    }

if(outputfile != NULL)
{
   fwrite(me,sizeof(char),512,outputfile);
}
}

free(filename);
fclose(outputfile);
fclose(input_file);

return 0;
}