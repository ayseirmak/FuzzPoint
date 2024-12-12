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
  int *i = ((0x6BB));
  float f = ((8.4));
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
  return ((0));
}
/* ProgramSourceLLVM */
