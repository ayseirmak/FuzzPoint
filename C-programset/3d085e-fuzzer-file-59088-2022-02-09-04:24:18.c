/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = (5.2) + (-43) +((short)((((int)(*q)) >>((int)((10.3))))))+((short)((((int)(*q)) |((int)(*q)))));
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0x5);
  float f = (2.10);
  int **p;
  if ((2048))
    p = &i;
  else
    p = (int **)&f;
  bar (p);
  if ((0xCD2D2))
    return **p;
  return f;
}

int main()
{
  if ((0))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
