/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  
;
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0);
  float f = (6.7);
  int **p;
  if (b)
    ;
  else
    ;
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
