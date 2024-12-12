/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  

*q = (2.9) + (106) *((short)((((int)((2.9))) %((int)(*q)))))+((int)((((int)(*q)) %((int)(*q)))))-((int)((((int)((9.3))) &((int)((9.6))))));
*q = (2.9) + (106) *((short)((((int)((2.9))) %((int)(*q)))))+((int)((((int)(*q)) %((int)(*q)))))-((int)((((int)((9.3))) &((int)((9.6))))));
;
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0);
  float f = (8.10);
  int **p;
  if (0)
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
