/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  ;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = 0;
  float f = 1.0;
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
  if (((int)((int)foo(0) != 0.0 + 42 *((int)((((double)(foo(0))) *((double)(foo(0))))))) + 42 +((int)((((int)(0.0 + 42 *((int)((((double)(foo(0))) *((double)(foo(0)))))))) ^((int)(42 *((int)((((double)(foo(0))) *((double)(foo(0)))))))))))+((int)((((int)(0.0 + 42 *((int)((((double)(foo(0))) *((double)(foo(0)))))))) &((int)(42 *((int)((((double)(foo(0))) *((double)(foo(0)))))))))))-((long)((((int)((int)foo(0))) ^((int)(42 *((int)((((double)(foo(0))) *((double)(foo(0)))))))))))-((int)((((int)(0.0 + 42 *((int)((((double)(foo(0))) *((double)(foo(0)))))))) %((int)(42 *((int)((((double)(foo(0))) *((double)(foo(0)))))))))))-((int)((((int)(0.0 + 42 *((int)((((double)(foo(0))) *((double)(foo(0)))))))) |((int)(0.0 + 42 *((int)((((double)(foo(0))) *((double)(foo(0)))))))))))*((long)((((int)(0.0)) |((int)((int)foo(0))))))))
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
