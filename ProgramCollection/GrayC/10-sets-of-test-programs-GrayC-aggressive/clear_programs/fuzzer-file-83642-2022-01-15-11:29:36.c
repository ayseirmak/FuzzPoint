/* corpus/struct-aliasing-1.c */
struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  *r = 0 + 42 *((short)((((int)(*r)) >>((int)(*r)))))*((long)((((int)(0)) |((int)(*r)))))*((long)((((int)(*r)) &((int)(0)))))-((short)((((double)(0)) -((double)(0)))))*((long)((((int)(0)) ^((int)(*r))))) + 42 +((int)((((int)(0 + 42 *((short)((((int)(*r)) >>((int)(*r)))))*((long)((((int)(0)) |((int)(*r)))))*((long)((((int)(*r)) &((int)(0)))))-((short)((((double)(0)) -((double)(0)))))*((long)((((int)(0)) ^((int)(*r))))))) <<((int)(0 + 42 *((short)((((int)(*r)) >>((int)(*r)))))*((long)((((int)(0)) |((int)(*r)))))*((long)((((int)(*r)) &((int)(0)))))-((short)((((double)(0)) -((double)(0)))))*((long)((((int)(0)) ^((int)(*r))))))))))-((short)((((int)(0 + 42 *((short)((((int)(*r)) >>((int)(*r)))))*((long)((((int)(0)) |((int)(*r)))))*((long)((((int)(*r)) &((int)(0)))))-((short)((((double)(0)) -((double)(0)))))*((long)((((int)(0)) ^((int)(*r))))))) >>((int)(*r)))))+((long)((((int)(*r)) %((int)(0 + 42 *((short)((((int)(*r)) >>((int)(*r)))))*((long)((((int)(0)) |((int)(*r)))))*((long)((((int)(*r)) &((int)(0)))))-((short)((((double)(0)) -((double)(0)))))*((long)((((int)(0)) ^((int)(*r))))))))));
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
