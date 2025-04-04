/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  
*q = (5.7) + (0xE4) *((long)((((int)(*q)) <<((int)(*q)))))-((short)((((int)((3.6))) &((int)((3.5))))))*((short)((((int)(*q)) &((int)((5.10))))))*((long)((((double)((2.2))) -((double)((6.4))))))*((long)((((int)(*q)) ^((int)(*q)))));
*q = (10.7) + (170) *((long)((((double)((3.10))) -((double)((2.1))))))+((int)((((int)(*q)) ^((int)(*q)))))+((long)((((int)(*q)) &((int)(*q)))))+((short)((((int)((7.5))) >>((int)((2.1))))))+((int)((((int)(*q)) %((int)(*q)))));
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (-1);
  float f = (5.5);
  int **p;
  if (0)
    ;
  else
    
p = (int **)&f;
p = (int **)&f;
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
