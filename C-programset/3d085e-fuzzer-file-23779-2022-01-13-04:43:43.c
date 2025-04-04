/* corpus/struct-aliasing-1.c */
struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  *r = 0 + 42 -((int)((((int)(0)) |((int)(*r)))))+((short)((((int)(*r)) %((int)(*r)))))*((int)((((int)(*r)) &((int)(0))))) + 42 *((short)((((int)(0 + 42 -((int)((((int)(0)) |((int)(*r))))))) <<((int)(((short)((((int)(*r)) %((int)(*r))))))))))*((short)((((int)(((short)((((int)(*r)) %((int)(*r)))))*((int)((((int)(*r)) &((int)(0))))))) ^((int)(((int)((((int)(0)) |((int)(*r))))))))));
  return i + *q;
}
extern void abort (void);
int main()
{
  int i = 1;
  if (0)
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
