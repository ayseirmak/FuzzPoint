/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  


*q = (7.7) + 42 *((int)((((int)((7.7))) <<((int)(*q)))))-((int)((((int)((7.7))) ^((int)((7.7))))))-((int)((((int)(*q)) &((int)(*q)))))-((int)((((double)((7.7))) -((double)((7.7))))));
*q = (7.7) + 42 *((int)((((int)((7.7))) <<((int)(*q)))))-((int)((((int)((7.7))) ^((int)((7.7))))))-((int)((((int)(*q)) &((int)(*q)))))-((int)((((double)((7.7))) -((double)((7.7))))));
;
;
;
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0);
  float f = (2.6);
  int **p;
  if ((0x09))
    ;
  else
    

;
;
;


p = (int **)&f;
p = (int **)&f;
;

p = (int **)&f;
p = (int **)&f;
;
;
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
