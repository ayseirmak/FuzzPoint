/* corpus/pr36034-2.c */
double x[50] = { 10, 11, 12, 13, 14, 15, -1, -1, -1, -1,
                 21, 22, 23, 24, 25, 26, -1, -1, -1, -1,
                 32, 33, 34, 35, 36, 37, -1, -1, -1, -1,
                 43, 44, 45, 46, 47, 48, -1, -1, -1, -1,
                 54, 55, 56, 57, 58, 59, -1, -1, -1, -1 };
double tmp[30];

void __attribute__((noinline))
test (void)
{
  int i, j;
  for (i = 0; i < 5; ++i)
    {
      x[i*10];
      x[i*10+1];
      tmp[i*6+2] = x[i*10+2];
      x[i*10+3];
      tmp[i*6+4] = x[i*10+4];
      x[i*10+5];
    }
}
extern void abort (void);
int main()
{
  int i, j;
  test();
  for (i = 0; i < 5; ++i)
    for (j = 0; j < 6; ++j)
      if (tmp[i*6+j] == -1)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
