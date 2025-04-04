/* corpus/struct-aliasing-1.c */
struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  *r = 0 + 42 *((long)((((double)(0)) *((double)(0)))))-((long)((((int)(*r)) |((int)(*r)))))+((long)((((double)(0)) -((double)(0)))))-((long)((((int)(*r)) %((int)(*r)))))+((short)((((int)(*r)) ^((int)(0)))));
  return i + *q;
}
extern void abort (void);
int main()
{
  int i = 1;
  if (((int)foo (&i, (struct S *)&i) != 1 + 42 *((short)((((int)(1)) ^((int)(1)))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
