/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = ((1.2)) + (42) *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)(((9.8)))) +((double)(((5.9))))))) + 42 *((int)((((int)(((1.2)) + (42) *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)(((9.8)))) +((double)(((5.9))))))))) |((int)(((1.2)) + (42) *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)(((9.8)))) +((double)(((5.9))))))))))))+((short)((((int)(*q)) ^((int)(*q)))))*((long)((((int)(*q)) |((int)(((1.2)) + (42) *((long)((((int)(*q)) ^((int)(*q)))))-((long)((((int)(*q)) <<((int)(*q)))))+((long)((((double)(((9.8)))) +((double)(((5.9))))))))))));
}

float __attribute__((noinline))
foo (int b)
{
  int *i = ((72057594037927436));
  float f = ((2.4));
  int **p;
  if ((0))
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
  if ((0))
    { abort (); }
  return ((67108864));
}
/* ProgramSourceLLVM */
