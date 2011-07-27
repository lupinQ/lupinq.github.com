#include <stdio.h>

int main()
{   
    int i,j=0;
    for(i=0;i<=200;i++)
       if(i%3==0)
       { j++;
       printf("%d",i);
       if(j%8==0)
       printf("\n");
       }
    return 0;
}
