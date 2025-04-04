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
  __real__ a = 9 + 42 + ((long)(((int)9) | ((int)(__real__ a)))) * ((int)(((double)9) - ((double)(__real__ a)))) - ((int)(((int)9) & ((int)9))) - ((int)(((int)(__real__ a)) & ((int)9)));
  __imag__ a = 42 + 42 * ((short)(((double)42) - ((double)(__imag__ a)))) - ((long)(((double)42) + ((double)42))) + ((int)(((double)42) - ((double)42))) + ((int)(((int)42) % ((int)42))) + 42 + ((short)(((double)(__imag__ a)) - ((double)(__imag__ a)))) - ((short)(((int)(42 + 42 * ((short)(((double)42) - ((double)(__imag__ a)))) - ((long)(((double)42) + ((double)42))) + ((int)(((double)42) - ((double)42))) + ((int)(((int)42) % ((int)42))))) & ((int)(42 + 42 * ((short)(((double)42) - ((double)(__imag__ a)))) - ((long)(((double)42) + ((double)42))) + ((int)(((double)42) - ((double)42))) + ((int)(((int)42) % ((int)42))))))) * ((short)(((int)(42 + 42 * ((short)(((double)42) - ((double)(__imag__ a)))) - ((long)(((double)42) + ((double)42))) + ((int)(((double)42) - ((double)42))) + ((int)(((int)42) % ((int)42))))) << ((int)(__imag__ a)))) + ((short)(((int)(42 + 42 * ((short)(((double)42) - ((double)(__imag__ a)))) - ((long)(((double)42) + ((double)42))) + ((int)(((double)42) - ((double)42))) + ((int)(((int)42) % ((int)42))))) & ((int)(42 + 42 * ((short)(((double)42) - ((double)(__imag__ a)))) - ((long)(((double)42) + ((double)42))) + ((int)(((double)42) - ((double)42))) + ((int)(((int)42) % ((int)42))))))) - ((long)(((int)(42 + 42 * ((short)(((double)42) - ((double)(__imag__ a)))) - ((long)(((double)42) + ((double)42))) + ((int)(((double)42) - ((double)42))) + ((int)(((int)42) % ((int)42))))) ^ ((int)(42 + 42 * ((short)(((double)42) - ((double)(__imag__ a)))) - ((long)(((double)42) + ((double)42))) + ((int)(((double)42) - ((double)42))) + ((int)(((int)42) % ((int)42)))))));

  b = bar (a) + 42 + ((int)(((int)(b)) << ((int)(b))));

  if (0)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
