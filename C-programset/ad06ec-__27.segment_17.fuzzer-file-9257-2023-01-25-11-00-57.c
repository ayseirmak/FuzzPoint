/* corpus/struct-aliasing-1.c */
struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  *r = 0;
  return i + *q;
}
extern void abort (void);
int main()
{
  int i = 1;
  if (((int)foo (&i, (struct S *)&i) != 1 + 41 * ((short)((((int)(1)) & ((int)(1))))) * ((int)((((int)(foo (&i, (struct S *)&i))) | ((int)(foo (&i, (struct S *)&i)))))) * ((short)((((int)(1)) << ((int)(1)))))))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
