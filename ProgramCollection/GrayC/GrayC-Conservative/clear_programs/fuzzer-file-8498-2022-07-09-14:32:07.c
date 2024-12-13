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
  __real__ a = 9 + 42 - ((short)(((double)(__real__ a)) + ((double)9))) + ((short)(((int)9) >> ((int)9))) * ((int)(((int)(__real__ a)) & ((int)9))) - ((short)(((int)9) << ((int)9)));
  
;b = bar (a) + 42 * ((long)(((int)bar (a)) | ((int)(b))));
__imag__ a;

  b = bar (a);

  if (0)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
