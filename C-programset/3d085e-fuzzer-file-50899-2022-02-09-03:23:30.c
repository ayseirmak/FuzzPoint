/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  ;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = ((72058143793741824));
  float f = ((9.2));
  int **p;
  if ((0))
    ;
  else
    ;
  bar (p);
  if (b)
    return **p;
  return f;
}

int main()
{
  if ((0))
    { abort (); }
  return ((1024));
}
/* ProgramSourceLLVM */
