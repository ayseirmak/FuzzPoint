/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  
;

*q = (3.6) + 42 -((short)((((int)(*q)) &((int)(*q)))))*((short)((((int)(*q)) <<((int)(*q)))))-((short)((((int)(*q)) &((int)((3.6))))))-((short)((((int)(*q)) &((int)((3.6))))));
*q = (3.6) + 42 -((int)((((int)((3.6))) <<((int)((3.6))))))*((long)((((int)((3.6))) ^((int)(*q)))))-((int)((((int)((3.6))) &((int)((3.6))))))*((int)((((int)((3.6))) &((int)((3.6))))))+((long)((((int)(*q)) |((int)((3.6))))));
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
