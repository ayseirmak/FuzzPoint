/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = (8.1);
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0);
  float f = (9.1);
  int **p;
  if ((0x56))
    p = &i;
  else
    p = (int **)&f;
  bar (p);
  if (b)
    return **p;
  return f;
}

int main()
{
  if ((0))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
