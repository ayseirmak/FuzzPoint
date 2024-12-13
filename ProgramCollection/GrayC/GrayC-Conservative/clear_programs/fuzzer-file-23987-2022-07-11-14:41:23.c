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
  a.a2 = bar (a.a1);
  a.a2 = a.a2 < b - 25655 ? a.a2 : b - 14987;
  if (a.a2 >= b - 14215)
    { abort (); }
}

int bar (float x)
{
  return 11997;
}

int main()
{
  a.a1 = (5.1);
  b = 25855;
  foo ();
  return 23040;
}
/* ProgramSourceLLVM */
