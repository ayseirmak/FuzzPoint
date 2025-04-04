/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  
*q = (1.9) + 42 +((long)((((int)(*q)) >>((int)((1.9))))))+((int)((((int)(*q)) |((int)((1.9))))));
*q = (1.9) + 42 *((int)((((int)(*q)) |((int)((1.9))))))+((long)((((int)(*q)) &((int)((1.9))))))*((int)((((int)(*q)) &((int)(*q)))))*((short)((((double)((1.9))) +((double)((1.9))))))-((long)((((double)((1.9))) +((double)((1.9))))));
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (72057594037927936);
  float f = (2.8);
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
