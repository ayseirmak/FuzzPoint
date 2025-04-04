/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = 1.0 + 42 +((long)((((double)(1.0)) +((double)(1.0)))))-((long)((((double)(__real__ x)) -((double)(1.0)))))-((int)((((int)(__real__ x)) ^((int)(__real__ x)))))+((long)((((double)(__real__ x)) *((double)(1.0)))));
  __imag__ x = 2.0 + 42 *((long)((((double)(__imag__ x)) +((double)(2.0)))))*((short)((((double)(__imag__ x)) *((double)(__imag__ x)))))-((int)((((int)(__imag__ x)) <<((int)(__imag__ x)))))-((short)((((int)(__imag__ x)) &((int)(2.0)))))*((int)((((double)(__imag__ x)) -((double)(__imag__ x)))));
  foo (x);
  __real__ y = 3.0f + 42 -((short)((((double)(__real__ y)) -((double)(3.0f)))))*((int)((((int)(3.0f)) |((int)(3.0f)))));
  __imag__ y = 4.0f + 42 *((short)((((int)(__imag__ y)) >>((int)(__imag__ y)))))+((long)((((int)(4.0f)) <<((int)(__imag__ y)))))*((int)((((double)(__imag__ y)) -((double)(4.0f)))));
  bar (y);
  __real__ z = 5.0L + 42 *((long)((((double)(__real__ z)) -((double)(__real__ z)))))-((short)((((int)(5.0L)) |((int)(__real__ z)))))+((int)((((int)(5.0L)) ^((int)(__real__ z)))));
  __imag__ z = 6.0L + 42 -((int)((((int)(__imag__ z)) %((int)(6.0L)))));
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
