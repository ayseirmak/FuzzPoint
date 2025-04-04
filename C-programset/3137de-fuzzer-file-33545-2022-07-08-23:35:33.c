/* corpus/pr38969.c */
__complex__ float
__attribute__ ((noinline)) foo (__complex__ float x)
{
  return x;
}

__complex__ float
__attribute__ ((noinline)) bar (__complex__ float x)
{
  return foo (x);
}

int main()
{
  __complex__ float a, b;
  
;__imag__ a = 42 + 42 + ((short)(((double)(__imag__ a)) - ((double)(__imag__ a)))) + ((long)(((double)42) * ((double)(__imag__ a))));
9 + 42 - ((int)(((int)9) ^ ((int)(__real__ a)))) - ((short)(((double)9) * ((double)(__real__ a)))) + ((int)(((int)(__real__ a)) & ((int)9)));
  __imag__ a = 42;

  bar (a);

  if (0)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
