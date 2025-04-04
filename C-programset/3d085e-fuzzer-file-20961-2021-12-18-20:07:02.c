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
  a.a2 = bar (a.a1) + 42 -((long)((((int)(bar (a.a1))) <<((int)(a.a2)))))+((int)((((double)(bar (a.a1))) -((double)(a.a2)))))+((long)((((int)(a.a2)) |((int)(bar (a.a1))))))+((long)((((int)(a.a2)) %((int)(bar (a.a1))))))-((int)((((int)(a.a2)) |((int)(a.a2)))));
  a.a2 = a.a2 < b - (9) ? a.a2 : b - (3) + 42 *((int)((((double)(a.a2 < b - (9) ? a.a2 : b - (3))) -((double)(a.a2 < b - (9) ? a.a2 : b - (3))))))*((short)((((int)(a.a2)) %((int)(a.a2 < b - (9) ? a.a2 : b - (3))))))*((long)((((double)(a.a2 < b - (9) ? a.a2 : b - (3))) +((double)(a.a2 < b - (9) ? a.a2 : b - (3))))))*((long)((((int)(a.a2 < b - (9) ? a.a2 : b - (3))) &((int)(a.a2)))));
  if (0)
    { abort (); }
}

int bar (float x)
{
  return (3265);
}

int main()
{
  a.a1 = (3.8) + 42 +((int)((((int)((3.8))) <<((int)(a.a1)))));
  b = (-3385) + 42 *((long)((((int)(b)) |((int)(b)))))+((int)((((int)(b)) &((int)(b)))))+((short)((((double)((-3385))) -((double)(b)))))-((short)((((double)((-3385))) *((double)(b)))))+((long)((((double)(b)) +((double)((-3385))))));
  foo ();
  return (1152921504606846976);
}
/* ProgramSourceLLVM */
