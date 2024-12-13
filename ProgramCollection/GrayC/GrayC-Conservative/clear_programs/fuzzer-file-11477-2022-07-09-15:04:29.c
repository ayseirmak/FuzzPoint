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
  9 + 42 * ((long)(((int)9) | ((int)(__real__ a)))) - ((long)(((double)9) * ((double)(__real__ a)))) * ((long)(((double)9) + ((double)(__real__ a))));
  
;
;bar (a) + 42 * ((long)(((double)(b)) - ((double)(b))));
bar (a);
__imag__ a;

  bar (a) + 42 + ((long)(((int)bar (a)) | ((int)(b)))) + ((long)(((double)(b)) + ((double)(b)))) + ((short)(((double)bar (a)) + ((double)bar (a)))) * ((short)(((int)(b)) ^ ((int)bar (a)))) + ((long)(((double)(b)) - ((double)(b))));

  if (0)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
