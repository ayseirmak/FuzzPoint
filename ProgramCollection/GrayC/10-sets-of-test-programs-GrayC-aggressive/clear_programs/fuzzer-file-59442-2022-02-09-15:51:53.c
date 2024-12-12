/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = (1.9) + 42 *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)((1.9))) +((double)((1.9)))))) + 42 *((int)((((int)(*q)) >>((int)((1.9) + 42 *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)((1.9))) +((double)((1.9)))))))))))*((short)((((int)(*q)) &((int)((1.9) + 42 *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)((1.9))) +((double)((1.9)))))))))))*((short)((((int)(*q)) %((int)((1.9) + 42 *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)((1.9))) +((double)((1.9)))))))))))+((long)((((int)(*q)) <<((int)((1.9) + 42 *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)((1.9))) +((double)((1.9)))))))))))-((int)((((int)((1.9) + 42 *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)((1.9))) +((double)((1.9)))))))) ^((int)(*q)))));
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (72057594037927936);
  float f = (2.8);
  int **p;
  if (0)
    p = &i;
  else
    p = (int **)&f;
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
