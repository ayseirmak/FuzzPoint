/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = 1.0 + 42 *((long)((((double)(1.0)) +((double)(1.0)))))*((short)((((double)(__real__ x)) *((double)(__real__ x)))))*((int)((((int)(__real__ x)) <<((int)(__real__ x)))))*((int)((((double)(__real__ x)) -((double)(__real__ x)))));
  __imag__ x = 2.0 + 42 +((short)((((int)(2.0)) |((int)(2.0)))));
  foo (x);
  __real__ y = 3.0f + 42 +((long)((((double)(__real__ y)) *((double)(3.0f)))));
  __imag__ y = 4.0f + 42 *((long)((((double)(__imag__ y)) -((double)(4.0f)))))+((int)((((double)(__imag__ y)) +((double)(4.0f)))));
  bar (y);
  __real__ z = 5.0L + 42 *((int)((((int)(5.0L)) ^((int)(__real__ z)))))-((long)((((double)(__real__ z)) -((double)(5.0L)))));
  __imag__ z = 6.0L + 42 -((short)((((double)(6.0L)) *((double)(__imag__ z)))))*((long)((((double)(__imag__ z)) +((double)(__imag__ z)))))*((short)((((int)(__imag__ z)) <<((int)(__imag__ z)))))+((long)((((double)(6.0L)) +((double)(__imag__ z)))));
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
