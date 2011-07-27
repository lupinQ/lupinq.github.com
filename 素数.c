#include <stdio.h>

int main()
{
    int i;
    for(i=2;i<=100;i++)
    {
        for(j=2,k=0;j<=i/2;j++)
        if(i%j==0)
        k++;
        if(k=0)
        printf("%d\t",i);
    }
    return 0;
}
