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
  a.a2 = bar (a.a1) + 42 *((int)((((int)(a.a2)) <<((int)(a.a2)))))-((int)((((int)(a.a2)) ^((int)(bar (a.a1))))));
  a.a2 = a.a2 < b - (0x84860) ? a.a2 : b - (-2) + 42 +((int)((((double)(a.a2 < b - (0x84860) ? a.a2 : b - (-2))) +((double)(a.a2 < b - (0x84860) ? a.a2 : b - (-2))))))*((int)((((int)(a.a2)) ^((int)(a.a2 < b - (0x84860) ? a.a2 : b - (-2))))));
  if ((0))
    { abort (); }
}

int bar (float x)
{
  return (0xD251F);
}

int main()
{
  a.a1 = (4.7) + 42 -((long)((((int)((4.7))) &((int)(a.a1)))))+((short)((((double)(a.a1)) +((double)(a.a1)))))*((long)((((double)((4.7))) *((double)(a.a1)))));
  b = (3384) + 42 -((long)((((int)((3384))) &((int)((3384))))));
  foo ();
  return (0);
}
/* ProgramSourceLLVM */
