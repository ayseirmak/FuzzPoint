/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = 1.0 + 42 -((int)((((int)(1.0)) >>((int)(1.0)))))-((long)((((int)(__real__ x)) |((int)(1.0)))))-((int)((((double)(__real__ x)) +((double)(1.0)))))+((long)((((int)(__real__ x)) <<((int)(__real__ x)))))*((long)((((int)(__real__ x)) ^((int)(1.0)))));
  __imag__ x = 2.0 + 42 *((int)((((int)(__imag__ x)) <<((int)(2.0)))))*((long)((((int)(__imag__ x)) |((int)(__imag__ x)))))-((short)((((int)(2.0)) &((int)(2.0)))))-((short)((((int)(__imag__ x)) |((int)(2.0)))));
  foo (x);
  __real__ y = 3.0f + 42 *((long)((((double)(3.0f)) +((double)(__real__ y)))))-((long)((((int)(3.0f)) ^((int)(3.0f)))));
  __imag__ y = 4.0f + 42 *((int)((((double)(__imag__ y)) -((double)(__imag__ y)))))-((long)((((double)(4.0f)) *((double)(4.0f)))));
  bar (y);
  __real__ z = 5.0L + 42 +((short)((((int)(5.0L)) |((int)(__real__ z)))))+((int)((((int)(5.0L)) >>((int)(__real__ z)))))*((long)((((double)(5.0L)) +((double)(__real__ z)))))-((long)((((int)(__real__ z)) <<((int)(5.0L)))));
  __imag__ z = 6.0L + 42 *((long)((((int)(__imag__ z)) |((int)(__imag__ z)))));
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
