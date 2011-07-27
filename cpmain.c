#include <stdio.h>
#include "cpchar.h"
#include "cprecord.h"
#include "cprow.h"
int main(int argc, const char *argv[])
{
    int k;
    printf("Please select:\n1.cp by char\n2.cp by record\n3.cp by row\nYour choice:");
    scanf("%d",&k);
    FILE *fp1=fopen(argv,"r");
          if (!fp1) {
          printf("文件不存在！");
          return 0;         
          }
    FILE *fp2=fopen(argv+1,"w");

    switch(k){
    case 1:cpchar(fp1,fp2);break;
    case 2:cprecord(fp1,fp2);break;
    case 3:cprow(fp1,fp2);break;
    
    }
    return 0;
}
