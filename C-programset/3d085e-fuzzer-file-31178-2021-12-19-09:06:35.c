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
  ;
  ;
  if (0)
    { abort (); }
}

int bar (float x)
{
  return (3265);
}

int main()
{
  
a.a1 = (3.8) + 42 *((long)((((double)((3.8))) -((double)(a.a1)))))+((long)((((int)((3.8))) &((int)(a.a1)))))*((int)((((double)(a.a1)) +((double)(a.a1)))))+((int)((((double)((3.8))) *((double)((3.8))))));
a.a1 = (3.8) + 42 *((long)((((double)((3.8))) -((double)(a.a1)))))+((long)((((int)((3.8))) &((int)(a.a1)))))*((int)((((double)(a.a1)) +((double)(a.a1)))))+((int)((((double)((3.8))) *((double)((3.8))))));
;
  ;
  foo ();
  return (1152921504606846976);
}
/* ProgramSourceLLVM */
