/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = 1.0 + 42 -((int)((((int)(1.0)) <<((int)(1.0)))))*((short)((((double)(__real__ x)) +((double)(__real__ x)))))-((long)((((double)(__real__ x)) +((double)(__real__ x)))));
  __imag__ x = 2.0 + 42 -((int)((((int)(2.0)) ^((int)(__imag__ x)))));
  foo (x);
  __real__ y = 3.0f + 42 -((short)((((double)(__real__ y)) *((double)(__real__ y)))))*((long)((((double)(3.0f)) +((double)(3.0f)))))-((long)((((double)(3.0f)) +((double)(3.0f)))));
  __imag__ y = 4.0f + 42 *((long)((((double)(__imag__ y)) -((double)(4.0f)))))*((int)((((double)(__imag__ y)) -((double)(4.0f)))))*((long)((((int)(4.0f)) &((int)(4.0f)))))*((short)((((int)(__imag__ y)) ^((int)(4.0f)))));
  bar (y);
  __real__ z = 5.0L + 42 *((int)((((double)(__real__ z)) *((double)(__real__ z)))))+((long)((((double)(5.0L)) *((double)(5.0L)))))-((short)((((double)(__real__ z)) +((double)(5.0L)))))+((long)((((int)(5.0L)) %((int)(5.0L)))))+((short)((((double)(5.0L)) -((double)(__real__ z)))));
  __imag__ z = 6.0L + 42 *((short)((((double)(6.0L)) *((double)(__imag__ z)))))-((short)((((double)(__imag__ z)) +((double)(6.0L)))))*((int)((((double)(6.0L)) *((double)(__imag__ z)))))+((long)((((double)(__imag__ z)) +((double)(6.0L)))))*((short)((((int)(__imag__ z)) <<((int)(6.0L)))));
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
