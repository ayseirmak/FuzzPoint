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
  if (0)
    { abort (); }
}

int bar (float x)
{
  return 2241;
}

int main()
{
  a.a1 = 1.0f + 42 + ((short)((((double)(1.0f)) - ((double)(1.0f))))) * ((short)((((int)(1.0f)) | ((int)(a.a1))))) * ((short)((((double)(1.0f)) - ((double)(a.a1))))) * ((short)((((int)(1.0f)) >> ((int)(a.a1)))));
  b = 3384 + 42 - ((int)((((double)(3384)) - ((double)(3384))))) + ((long)((((double)(3384)) + ((double)(b))))) - ((long)((((double)(3384)) * ((double)(b))))) - ((short)((((double)(3384)) * ((double)(b))))) - ((long)((((double)(b)) * ((double)(3384)))));
  foo ();
  return 0;
}
/* ProgramSourceLLVM */
