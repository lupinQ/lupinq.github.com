#include <stdio.h>

int cprecord(FILE *fp1, FILE *fp2)
{

  while(!feof(fp1)){

   char str[1024]={0};
   fread(str,1,sizeof(str),fp1);
   fwrite(str,1,sizeof(str),fp2);
   }

    return 0;
}

int analy(char str[],char *buf){
  char *buf1,*buf2,*p = NULL,*q = NULL;
   strncpy(buf1,str,1024);  
while(){
p = strchr(buf1,"\"");
q = strstr(buf1,"/*");
if(p>=q){
flag++;
}
else{     
buf2=strsep(&buf1,"/*");
strcat(buf,buf2);
strsep(buf1,"*/");
buf1=buf1+2;
}
}
}

int main(int argc, const char *argv[])
{
      FILE *fp = fopen (argv[1], "r");
      FILE *fpcp = fopen (argv[2],"w+");
  if (!fp)
    {
      printf ("文件不存在！");
      return 0;
    }
  while (!feof (fp))
    {

      char str[1024] = { 0 },buf[1024] = {0};
      fgets (str, sizeof (str), fp);
      analy(str,buf);
      fputs(str,fpcp);
    }
  if (!fp)
    fclose (fp);

    *fpcp = fopen (argv[2], "r");
    *fp = fopen (argv[1],"w+");
   cprecord(fpcp,fp);

}

  return 0;
}


