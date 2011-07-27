#include <stdio.h>

static int cprecord(FILE *fp1, FILE *fp2)
{
/*   FILE *fp1=fopen(argv,"r");
      if (!fp1) {
      printf("文件不存在！");
       return 0;
       }
  FILE *fp2=fopen(argv+1,"w");
*/
  while(!feof(fp1)){

   char str[1024]={0};
   fread(str,1,sizeof(str),fp1);
   fwrite(str,1,sizeof(1024),fp2);
   }
 if (fp1)
 fclose(fp1);
 if(fp2)
 fclose(fp2);

    return 0;
}
