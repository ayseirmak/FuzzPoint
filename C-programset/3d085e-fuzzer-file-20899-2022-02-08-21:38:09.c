/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = (2.2) + 42 +((short)((((int)(*q)) <<((int)(*q)))))*((long)((((int)(*q)) |((int)(*q)))))+((int)((((int)(*q)) <<((int)((2.2))))));
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (32);
  float f = (5.1);
  int **p;
  if (b)
    p = &i;
  else
    p = (int **)&f;
  bar (p);
  if (0)
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
