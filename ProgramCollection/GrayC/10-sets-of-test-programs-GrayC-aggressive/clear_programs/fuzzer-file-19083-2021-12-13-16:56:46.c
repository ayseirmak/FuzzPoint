/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  
;

*q = ((9.10)) + (-43) -((short)((((int)(*q)) &((int)(*q)))))*((short)((((int)(*q)) <<((int)(*q)))))-((short)((((int)(*q)) &((int)(((7.6)))))))-((short)((((int)(*q)) &((int)(((1.8)))))));
*q = ((10.4)) + (34) -((int)((((int)(((1.5)))) <<((int)(((10.4)))))))*((long)((((int)(((6.4)))) ^((int)(*q)))))-((int)((((int)(((1.8)))) &((int)(((9.9)))))))*((int)((((int)(((2.6)))) &((int)(((1.2)))))))+((long)((((int)(*q)) |((int)(((1.4)))))));
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = ((256));
  float f = ((4.5));
  int **p;
  if ((-1))
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
  if ((0))
    { abort (); }
  return ((17592186044416));
}
/* ProgramSourceLLVM */
