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
  a.a2 = a.a2 < b - 1 ? a.a2 : b - 1;
  if (((int)a.a2 >= b - 1 + 41 - ((long)((((double)(b)) - ((double)(b))))) + ((int)((((int)(b - 1)) & ((int)(b))))) * ((long)((((double)(b)) - ((double)(a.a2))))) - ((long)((((int)(b - 1)) | ((int)(b)))))))
    { abort (); }
}

int bar (float x)
{
  return 2241;
}

int main()
{
  a.a1 = 1.0f + 42 * ((long)((((int)(1.0f)) | ((int)(a.a1))))) - ((short)((((double)(a.a1)) - ((double)(a.a1))))) * ((short)((((int)(a.a1)) >> ((int)(a.a1))))) - ((short)((((double)(a.a1)) * ((double)(1.0f))))) + ((short)((((int)(a.a1)) >> ((int)(a.a1)))));
  b = 3384;
  foo ();
  return 0;
}
/* ProgramSourceLLVM */
