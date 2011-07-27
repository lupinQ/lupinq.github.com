#include <stdio.h>
/*此函数用于求100！结尾零的个数*/
int main()
{
    int i,sum;
    sum=0;i=100;
    while(i>1)
    {i=i/5;
    sum=sum+i;}
    printf("\n 100！结尾有%d个零。\n",sum);
    return 0;
}
