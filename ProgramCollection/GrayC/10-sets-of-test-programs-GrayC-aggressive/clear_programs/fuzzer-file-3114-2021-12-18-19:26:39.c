/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = 1.0 + 42 *((long)((((int)(1.0)) &((int)(__real__ x)))))-((short)((((int)(1.0)) &((int)(__real__ x)))))+((short)((((double)(1.0)) -((double)(1.0)))));
  __imag__ x = 2.0 + 42 *((long)((((int)(__imag__ x)) ^((int)(2.0)))))*((short)((((double)(2.0)) +((double)(2.0)))))-((int)((((double)(__imag__ x)) +((double)(2.0)))))*((int)((((int)(__imag__ x)) &((int)(__imag__ x)))));
  foo (x);
  __real__ y = 3.0f + 42 *((long)((((int)(__real__ y)) %((int)(3.0f)))));
  __imag__ y = 4.0f + 42 +((short)((((int)(4.0f)) &((int)(__imag__ y)))))*((int)((((int)(4.0f)) <<((int)(4.0f)))));
  bar (y);
  __real__ z = 5.0L + 42 *((short)((((double)(__real__ z)) +((double)(__real__ z)))))+((int)((((int)(5.0L)) >>((int)(5.0L)))))*((short)((((int)(5.0L)) |((int)(5.0L)))))*((short)((((int)(5.0L)) &((int)(5.0L)))))+((long)((((int)(5.0L)) &((int)(5.0L)))));
  __imag__ z = 6.0L + 42 +((long)((((double)(__imag__ z)) *((double)(6.0L)))))-((int)((((int)(6.0L)) &((int)(__imag__ z)))))+((int)((((int)(__imag__ z)) >>((int)(6.0L)))))+((int)((((double)(__imag__ z)) *((double)(__imag__ z)))));
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
