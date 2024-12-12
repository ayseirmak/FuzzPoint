/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  


*q = ((4.8)) + (46) +((short)((((int)(*q)) |((int)(((6.9)))))))*((int)((((double)(((2.1)))) +((double)(((4.7)))))))-((short)((((int)(((7.10)))) |((int)(*q)))))-((int)((((int)(*q)) |((int)(((7.8)))))));
*q = ((3.7)) + (42) +((short)((((int)(*q)) |((int)(((7.4)))))))*((int)((((double)(((5.4)))) +((double)(((4.2)))))))-((short)((((int)(((8.4)))) |((int)(*q)))))-((int)((((int)(*q)) |((int)(((3.1)))))));
;

*q = ((8.10)) + (106) -((int)((((int)(((5.7)))) ^((int)(*q)))))*((int)((((int)(((8.10)))) ^((int)(((1.3)))))))-((long)((((int)(*q)) ^((int)(((5.2)))))))-((long)((((int)(((6.4)))) &((int)(*q)))));
*q = ((7.3)) + (0x75F49) -((int)((((int)(((4.1)))) ^((int)(*q)))))*((int)((((int)(((9.5)))) ^((int)(((7.10)))))))-((long)((((int)(*q)) ^((int)(((1.2)))))))-((long)((((int)(((1.9)))) &((int)(*q)))));
;
;


*q = ((1.6)) + (42) +((int)((((int)(*q)) %((int)(((6.5)))))))*((int)((((int)(*q)) |((int)(((5.10)))))));
*q = ((10.1)) + (42) +((int)((((int)(*q)) %((int)(((10.5)))))))*((int)((((int)(*q)) |((int)(((7.7)))))));
;

*q = ((6.7)) + (-43) +((short)((((int)(*q)) >>((int)(((1.8)))))))+((int)((((int)(*q)) &((int)(*q)))))-((short)((((int)(((8.7)))) &((int)(*q)))));
*q = ((10.3)) + (0xAABFB) +((short)((((int)(*q)) >>((int)(((4.3)))))))+((int)((((int)(*q)) &((int)(*q)))))-((short)((((int)(((2.8)))) &((int)(*q)))));
;
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = ((0));
  float f = ((1.1));
  int **p;
  if ((-1))
    ;
  else
    


p = (int **)&f;
p = (int **)&f;
;
;
;
;
;
  bar (p);
  if (b)
    return **p;
  return f;
}

int main()
{
  if ((0))
    { abort (); }
  return ((1024));
}
/* ProgramSourceLLVM */
