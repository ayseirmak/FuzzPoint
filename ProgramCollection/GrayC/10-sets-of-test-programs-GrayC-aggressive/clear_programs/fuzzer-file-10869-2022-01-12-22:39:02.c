/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  
*q = ((10.10));
*q = ((3.2));
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = ((17592186044416));
  float f = ((5.6));
  int **p;
  if ((0))
    ;
  else
    
p = (int **)&f;
p = (int **)&f;
;
  bar (p);
  if ((0))
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
