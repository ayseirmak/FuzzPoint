/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = (10.1) + (-43) +((long)((((int)(*q)) |((int)((3.6))))))-((short)((((double)((10.7))) -((double)((7.5))))))-((long)((((double)((10.10))) +((double)((1.5))))));
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (8);
  float f = (5.2);
  int **p;
  if (0)
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
  if (0)
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
