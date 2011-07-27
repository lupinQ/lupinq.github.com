#include <stdio.h>
/*此函数用于求1到输入上线数据的奇数和*/
int main()
{
    int i,j,sum;
    printf("请输入上限整数值：");
    scanf("%d",&j);
    printf("%d\n",j);
    for(i=1,sum=0;i<=j;i+=2)
    sum=i+sum;
    printf("\n1到%d的奇数求和结果为:%d\n",j,sum);
    return 0;
}
