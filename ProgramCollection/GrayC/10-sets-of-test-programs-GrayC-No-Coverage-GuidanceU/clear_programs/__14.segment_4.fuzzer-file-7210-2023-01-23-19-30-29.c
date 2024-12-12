/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = 1.0 + 42 - ((short)((((int)(__real__ x)) << ((int)(1.0))))) - ((int)((((int)(__real__ x)) | ((int)(__real__ x))))) - ((short)((((int)(1.0)) << ((int)(__real__ x))))) * ((long)((((int)(1.0)) >> ((int)(1.0)))));
  2.0 + 42 - ((int)((((double)(__imag__ x)) - ((double)(2.0))))) + ((long)((((int)(__imag__ x)) << ((int)(2.0)))));
  foo (x);
  
;__imag__ y = 4.0f;
3.0f;
  __imag__ y = 4.0f;
  bar (y);
  
;__imag__ z = 6.0L;
5.0L;
  __imag__ z = 6.0L;
  baz (z);
  exit (0);
}

void foo (__complex__ double x)
{
  if (0)
    { abort (); }
}

void bar (__complex__ float x)
{
  if (0)
    { abort (); }
}

void baz (__complex__ long double x)
{
  if (0)
    { abort (); }
}
/* ProgramSourceLLVM */
