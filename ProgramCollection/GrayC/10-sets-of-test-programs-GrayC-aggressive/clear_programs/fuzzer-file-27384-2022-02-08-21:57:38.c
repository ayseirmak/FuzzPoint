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
;
  ;
  if (0)
    { abort (); }
}

int bar (float x)
{
  return (0x39915);
}

int main()
{
  ;
  

b = (-3385);
b = (-3385);
;

b = (0x52D624B);
b = (0x52D624B);
;
;
  foo ();
  return (0);
}
/* ProgramSourceLLVM */
