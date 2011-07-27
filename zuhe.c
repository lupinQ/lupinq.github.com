nclude < stdio.h > int
main (int argc, const char *argv[])
{
  int i, j, k, b[100], a[4] = { 1, 2, 3, 4 };
  int m = 0;
  for (i = 0; i <= 3; i++)
    for (j = 0; j <= 3; j++)
      for (k = 0; k <= 3; k++)
	if (i != j && j != k && i != k)
	  printf ("%5d", b[m++] = a[i] * 100 + a[j] * 10 + a[k]);

  return 0;
}
