/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  1.0;
  __imag__ x;
  foo (x);
  3.0f;
  4.0f + 42 - ((short)(((double)(__imag__ y)) + ((double)(__imag__ y)))) * ((short)(((double)(__imag__ y)) - ((double)(__imag__ y)))) * ((short)(((int)(__imag__ y)) ^ ((int)(4.0f)))) + ((long)(((int)(__imag__ y)) & ((int)(__imag__ y))));
  bar (y);
  5.0L + 42 + ((int)(((double)(5.0L)) * ((double)(__real__ z)))) - ((long)(((double)(5.0L)) + ((double)(5.0L)))) * ((int)(((double)(5.0L)) * ((double)(__real__ z)))) - ((int)(((int)(5.0L)) >> ((int)(__real__ z))));
  6.0L + 42 * ((int)(((double)(__imag__ z)) - ((double)(__imag__ z)))) * ((int)(((int)(6.0L)) ^ ((int)(6.0L)))) * ((short)(((double)(__imag__ z)) * ((double)(6.0L))));
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
