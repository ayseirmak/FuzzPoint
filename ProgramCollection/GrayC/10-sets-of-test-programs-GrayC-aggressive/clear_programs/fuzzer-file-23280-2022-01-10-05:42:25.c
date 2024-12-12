/* corpus/struct-aliasing-1.c */
struct S { float f; };
int __attribute__((noinline))
foo (int *r, struct S *p)
{
  int *q = (int *)&p->f;
  int i = *q;
  *r = (0xF13) + (34) +((long)((((int)((0x849))) |((int)(*r)))))+((int)((((int)(*r)) &((int)((8))))))+((short)((((int)((0x2D))) %((int)((0))))))+((short)((((int)(*r)) %((int)((0xFD6))))))-((long)((((int)(*r)) %((int)((0)))))) + (0x27784) +((short)((((int)((8192) + (0xD0FB15) +((long)((((int)((131072))) |((int)(*r)))))+((int)((((int)(*r)) &((int)((0xA8402))))))+((short)((((int)((512))) %((int)((18014398509481984))))))+((short)((((int)(*r)) %((int)((0))))))-((long)((((int)(*r)) %((int)((0)))))))) >>((int)((2) + (-43) +((long)((((int)((-1))) |((int)(*r)))))+((int)((((int)(*r)) &((int)((0))))))+((short)((((int)((1024))) %((int)((0))))))+((short)((((int)(*r)) %((int)((0x87))))))-((long)((((int)(*r)) %((int)((0)))))))))))-((short)((((int)((-1) + (106) +((long)((((int)((4))) |((int)(*r)))))+((int)((((int)(*r)) &((int)((0))))))+((short)((((int)((0x2F0))) %((int)((0x6679))))))+((short)((((int)(*r)) %((int)((0x4))))))-((long)((((int)(*r)) %((int)((1048576)))))))) %((int)(*r)))))+((long)((((int)((0x13FA3) + (-43) +((long)((((int)((262144))) |((int)(*r)))))+((int)((((int)(*r)) &((int)((524288))))))+((short)((((int)((-1))) %((int)((0))))))+((short)((((int)(*r)) %((int)((0))))))-((long)((((int)(*r)) %((int)((-1)))))))) <<((int)(*r)))))*((int)((((int)((0) + (42) +((long)((((int)((0))) |((int)(*r)))))+((int)((((int)(*r)) &((int)((2))))))+((short)((((int)((0))) %((int)((0xB84E))))))+((short)((((int)(*r)) %((int)((-1))))))-((long)((((int)(*r)) %((int)((0x62FB0)))))))) |((int)(*r)))))-((short)((((int)(*r)) >>((int)(*r)))));
  return i + *q;
}
extern void abort (void);
int main()
{
  int i = (-2);
  if (0)
    { abort (); }
  return ((34359738368));
}
/* ProgramSourceLLVM */
