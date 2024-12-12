/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = 0.0 + 42 - ((short)((((int)(0.0)) << ((int)(*q))))) * ((short)((((int)(0.0)) >> ((int)(*q)))));
}

float __attribute__((noinline))
foo (int b)
{
  int *i = 0;
  float f = 1.0;
  int **p;
  if (0)
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
  return 0;
}
/* ProgramSourceLLVM */
