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
  __real__ a = 9;
  __imag__ a = 42 + 42 + ((int)(((int)(__imag__ a)) | ((int)42))) * ((short)(((double)(__imag__ a)) * ((double)42))) - ((long)(((int)42) >> ((int)(__imag__ a)))) * ((long)(((int)(__imag__ a)) & ((int)(__imag__ a)))) * ((int)(((int)(__imag__ a)) % ((int)42)));

  b = bar (a);

  if (0)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
