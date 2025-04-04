/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  *q = (5.4) + (-43) *((short)((((double)((8.1))) *((double)((8.1))))))+((short)((((double)((8.9))) -((double)((9.2))))))-((long)((((int)(*q)) |((int)(*q))))) + 42 -((short)((((int)((5.4) + (-43) *((short)((((double)((8.1))) *((double)((8.1))))))+((short)((((double)((8.9))) -((double)((9.2))))))-((long)((((int)(*q)) |((int)(*q))))))) %((int)((5.4) + (-43) *((short)((((double)((8.1))) *((double)((8.1))))))+((short)((((double)((8.9))) -((double)((9.2))))))-((long)((((int)(*q)) |((int)(*q))))))))))-((int)((((int)((5.4) + (-43) *((short)((((double)((8.1))) *((double)((8.1))))))+((short)((((double)((8.9))) -((double)((9.2))))))-((long)((((int)(*q)) |((int)(*q))))))) ^((int)((5.4) + (-43) *((short)((((double)((8.1))) *((double)((8.1))))))+((short)((((double)((8.9))) -((double)((9.2))))))-((long)((((int)(*q)) |((int)(*q))))))))))+((int)((((int)((5.4) + (-43) *((short)((((double)((8.1))) *((double)((8.1))))))+((short)((((double)((8.9))) -((double)((9.2))))))-((long)((((int)(*q)) |((int)(*q))))))) |((int)(*q)))))*((long)((((int)((5.4) + (-43) *((short)((((double)((8.1))) *((double)((8.1))))))+((short)((((double)((8.9))) -((double)((9.2))))))-((long)((((int)(*q)) |((int)(*q))))))) ^((int)(*q)))))*((short)((((int)(*q)) >>((int)(*q)))));
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0xB);
  float f = (4.7);
  int **p;
  if (b)
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
