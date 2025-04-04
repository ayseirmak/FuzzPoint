/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = 1.0 + 42 +((int)((((int)(1.0)) |((int)(1.0)))))*((int)((((int)(1.0)) ^((int)(__real__ x)))))-((short)((((int)(1.0)) <<((int)(1.0)))));
  __imag__ x = 2.0 + 42 *((int)((((int)(2.0)) >>((int)(2.0)))))-((short)((((double)(__imag__ x)) -((double)(__imag__ x)))))-((short)((((double)(2.0)) *((double)(2.0)))));
  foo (x);
  __real__ y = 3.0f + 42 -((int)((((int)(3.0f)) <<((int)(__real__ y)))))+((short)((((int)(__real__ y)) ^((int)(__real__ y)))))*((long)((((int)(3.0f)) >>((int)(__real__ y)))));
  __imag__ y = 4.0f + 42 -((int)((((double)(4.0f)) *((double)(4.0f)))))-((int)((((double)(4.0f)) +((double)(4.0f)))))-((long)((((double)(__imag__ y)) -((double)(__imag__ y)))))*((long)((((double)(__imag__ y)) *((double)(4.0f)))))-((int)((((double)(4.0f)) +((double)(4.0f)))));
  bar (y);
  __real__ z = 5.0L + 42 *((short)((((double)(5.0L)) -((double)(5.0L)))))-((int)((((int)(__real__ z)) >>((int)(__real__ z)))));
  __imag__ z = 6.0L + 42 +((long)((((double)(__imag__ z)) +((double)(__imag__ z)))))*((short)((((int)(6.0L)) <<((int)(__imag__ z)))))+((short)((((int)(__imag__ z)) &((int)(6.0L)))))+((long)((((int)(6.0L)) |((int)(6.0L)))))+((short)((((int)(__imag__ z)) %((int)(6.0L)))));
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
