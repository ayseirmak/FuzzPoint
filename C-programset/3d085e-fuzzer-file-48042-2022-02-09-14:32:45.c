/* corpus/20020213-1.c */
/* PR c/5681
   This testcase failed on IA-32 at -O0, because safe_from_p
   incorrectly assumed it is safe to first write into a.a2 b-1
   and then read the original value from it.  */

int bar (float);

struct A {
  float a1;
  int a2;
} a;

int b;

void foo (void)
{
  a.a2 = bar (a.a1) + (-43) *((int)((((int)(a.a2)) %((int)(bar (a.a1))))))+((long)((((int)(bar (a.a1))) |((int)(bar (a.a1))))))-((int)((((double)(a.a2)) -((double)(a.a2)))))+((short)((((double)(bar (a.a1))) -((double)(a.a2)))))*((short)((((double)(a.a2)) -((double)(bar (a.a1))))));
  a.a2 = a.a2 < b - (1) ? a.a2 : b - (-2) + (-43) +((short)((((double)(a.a2 < b - (0x412B8) ? a.a2 : b - (1))) -((double)(a.a2)))))-((short)((((double)(a.a2 < b - (65) ? a.a2 : b - (0x8EDD2))) +((double)(a.a2 < b - (1) ? a.a2 : b - (33))))));
  if ((0))
    { abort (); }
}

int bar (float x)
{
  return (2257);
}

int main()
{
  a.a1 = (5.7) + (0x7CC3FF) +((long)((((double)((10.6))) -((double)((7.10))))))+((int)((((double)((8.8))) +((double)((10.8))))))*((short)((((int)((2.9))) |((int)(a.a1)))))*((int)((((double)((4.9))) +((double)((8.3))))));
  b = (3448) + (42) -((int)((((double)((3388))) -((double)((3376))))))-((long)((((double)(b)) *((double)(b)))));
  foo ();
  return (0);
}
/* ProgramSourceLLVM */
