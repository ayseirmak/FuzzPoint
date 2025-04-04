/* corpus/struct-aliasing-1.c */
struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  *r = 0 + 42 +((int)((((int)(*r)) |((int)(*r)))))*((long)((((int)(*r)) %((int)(0)))))*((short)((((int)(*r)) %((int)(0)))));
  return i + *q;
}
extern void abort (void);
int main()
{
  int i = 8;
  if (0)
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
