/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  

*q = (3.6);
*q = (3.6);
;

*q = (3.6);
*q = (3.6);
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0);
  float f = (4.6);
  int **p;
  if (0)
    ;
  else
    

p = (int **)&f;
p = (int **)&f;
;
;
;
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
