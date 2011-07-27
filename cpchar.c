
#include <stdio.h>

static int cpchar(FILE *fp1, FILE *fp2)
{
  while(!feof(fp1)){

   char str;
   str=fgetc(fp1);
   fputc(str,fp2);
   
   
   }
 if (fp1)
 fclose(fp1);
 if(fp2)
 fclose(fp2);

    return 0;
}
