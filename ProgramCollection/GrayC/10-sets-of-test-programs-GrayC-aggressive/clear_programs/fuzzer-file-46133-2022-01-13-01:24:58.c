/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  

*q = ((8.1)) + (10) *((int)((((int)(((2.4)))) <<((int)(*q)))))-((int)((((int)(((6.8)))) ^((int)(((9.2)))))))-((int)((((int)(*q)) &((int)(*q)))))-((int)((((double)(((5.9)))) -((double)(((3.8)))))));
*q = ((8.8)) + (34) *((int)((((int)(((6.9)))) <<((int)(*q)))))-((int)((((int)(((9.5)))) ^((int)(((5.8)))))))-((int)((((int)(*q)) &((int)(*q)))))-((int)((((double)(((10.3)))) -((double)(((10.10)))))));
;
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = ((-1));
  float f = ((2.7));
  int **p;
  if ((0x09))
    ;
  else
    

p = (int **)&f;
p = (int **)&f;
;

p = (int **)&f;
p = (int **)&f;
;
;
  bar (p);
  if ((16777216))
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
