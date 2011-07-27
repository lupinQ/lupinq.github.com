#include <stdio.h>

static int cprow(FILE *fp1, FILE *fp2)
{
  while(!feof(fp1)){

   char str[1024]={0};
   fgets(str, sizeof(str), fp1);
   fputs(str,fp2);
   
   
   }
 if (fp1)
 fclose(fp1);
 if(fp2)
 fclose(fp2);

    return 0;
}
