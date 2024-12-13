/* corpus/struct-aliasing-1.c */
struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = 8;
  0;
  return i + *q;
}
extern void abort (void);
int main()
{
  int i = 8;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
