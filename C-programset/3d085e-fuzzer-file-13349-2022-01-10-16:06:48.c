/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = ((10.4)) + (-(0x4AA)) -((long)((((int)(((9.9)))) <<((int)(((8.2)))))))+((int)((((int)(*q)) <<((int)(*q)))))+((long)((((int)(((10.8)))) <<((int)(*q)))))+((short)((((int)(((10.1)))) &((int)(*q)))));
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0xDF1);
  float f = ((4.5));
  int **p;
  if (0)
    p = &i;
  else
    p = (int **)&f;
  bar (p);
  if (((0)))
    return **p;
  return f;
}

int main()
{
  if (0)
    { abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
