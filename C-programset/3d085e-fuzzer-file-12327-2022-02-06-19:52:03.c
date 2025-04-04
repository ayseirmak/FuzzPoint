/* corpus/struct-aliasing-1.c */
struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  

*r = (-1) + (-43) +((int)((((int)(*r)) |((int)(*r)))))*((int)((((int)((0x7))) |((int)(*r))))) + (0x3AD6F) +((int)((((int)((0) + (106))) %((int)((-1) + (48) +((int)((((int)(*r)) |((int)(*r)))))*((int)((((int)((0x92F30))) |((int)(*r))))))))))*((short)((((int)((-43))) %((int)(*r)))))*((int)((((int)(((int)((((int)(*r)) |((int)(*r)))))*((int)((((int)((-1))) |((int)(*r))))))) |((int)(*r)))))-((long)((((int)((64) + (42) +((int)((((int)(*r)) |((int)(*r)))))*((int)((((int)((64))) |((int)(*r))))))) |((int)((-43))))))-((short)((((int)(*r)) >>((int)((16384))))));
*r = (-1) + (-43) +((int)((((int)(*r)) |((int)(*r)))))*((int)((((int)((0x7))) |((int)(*r))))) + (0x3AD6F) +((int)((((int)((0) + (106))) %((int)((-1) + (48) +((int)((((int)(*r)) |((int)(*r)))))*((int)((((int)((0x92F30))) |((int)(*r))))))))))*((short)((((int)((-43))) %((int)(*r)))))*((int)((((int)(((int)((((int)(*r)) |((int)(*r)))))*((int)((((int)((-1))) |((int)(*r))))))) |((int)(*r)))))-((long)((((int)((64) + (42) +((int)((((int)(*r)) |((int)(*r)))))*((int)((((int)((64))) |((int)(*r))))))) |((int)((-43))))))-((short)((((int)(*r)) >>((int)((16384))))));
;
;
;
  return i + *q;
}
extern void abort (void);
int main()
{
  int i = (0xCD7);
  if (0)
    { abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
