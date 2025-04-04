/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = (1.8) + 42 *((int)((((double)(__real__ x)) *((double)(__real__ x)))))+((short)((((double)(__real__ x)) -((double)(__real__ x)))))-((long)((((double)((1.8))) +((double)(__real__ x)))))*((short)((((double)((1.8))) -((double)(__real__ x)))));
  __imag__ x = (2.10) + 42 +((long)((((int)((2.10))) ^((int)((2.10))))))*((short)((((double)((2.10))) -((double)((2.10))))))*((int)((((int)((2.10))) ^((int)((2.10))))))*((int)((((double)(__imag__ x)) -((double)((2.10))))))-((short)((((double)((2.10))) *((double)(__imag__ x)))));
  foo (x);
  __real__ y = (1.9) + 42 +((int)((((double)(__real__ y)) -((double)(__real__ y)))))-((long)((((int)((1.9))) &((int)(__real__ y)))));
  __imag__ y = (9.1) + 42 -((int)((((double)(__imag__ y)) -((double)(__imag__ y)))))+((long)((((double)(__imag__ y)) -((double)((9.1))))))-((short)((((int)((9.1))) ^((int)(__imag__ y)))))*((long)((((int)(__imag__ y)) |((int)((9.1))))));
  bar (y);
  __real__ z = (10.3) + 42 *((int)((((double)((10.3))) *((double)((10.3))))));
  __imag__ z = (9.10) + 42 -((int)((((int)(__imag__ z)) ^((int)(__imag__ z)))))-((int)((((int)(__imag__ z)) %((int)((9.10))))))*((short)((((int)(__imag__ z)) >>((int)(__imag__ z)))))+((short)((((int)(__imag__ z)) |((int)((9.10))))));
  baz (z);
  exit ((0));
}

void foo (__complex__ double x)
{
  if ((0))
    { abort (); }
}

void bar (__complex__ float x)
{
  if ((0))
    { abort (); }
}

void baz (__complex__ long double x)
{
  if (0)
    { abort (); }
}
/* ProgramSourceLLVM */
