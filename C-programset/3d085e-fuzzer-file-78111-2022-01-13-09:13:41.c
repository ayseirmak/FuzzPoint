/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  

*q = 0.0;
*q = 0.0;
;
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = 0;
  float f = 1.0;
  int **p;
  if (b)
    ;
  else
    
;

p = (int **)&f;
p = (int **)&f;
;
;
  bar (p);
  if (b)
    return **p;
  return f;
}

int main()
{
  if (foo(0) != 0.0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
