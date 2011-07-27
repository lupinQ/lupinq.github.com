#include <stdio.h>
 int year(int  );
int main()
{   int i,n;
    printf("请输入需要判断的年份：");
label:  scanf("%d",&i);
    printf("%d\n",i);
    n=year(i);
    switch(n)
    {   case -1: printf("请输入合法年份：");
                 goto label;
                 break;
        case  0: printf("%d不是润年。\n",i);break;
        case  1: printf("%d是润年。\n",i);break;
    }
    
    return 0;
}

int year(int i)
{ if(i<0)
  return -1;
  else if ((i%4==0)&&(i%100!=0)||(i%400==0))
  return 1;
  else
  return 0;
}
