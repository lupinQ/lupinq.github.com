#include <stdio.h>
/*此函数用于判断输入年份是否为润年*/
int
main (void)
{
  int i;
  printf ("请输入需要判断的年份：");
  scanf ("%d", &i);
  printf ("%d\n", i);
  if (i <= 0)
    printf ("输入数值不合法，结束程序！");
  else if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0))
    printf ("\n%d是润年", i);
  else
    printf ("\n%d不是润年\n", i);
  return 0;
}
