/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  __real__ x = (1.10) + (46) -((int)((((int)((9.5))) <<((int)((5.6))))))*((short)((((double)(__real__ x)) +((double)(__real__ x)))))-((long)((((double)(__real__ x)) +((double)(__real__ x)))));
  __imag__ x = (4.2) + (-43) -((int)((((int)((4.10))) ^((int)(__imag__ x)))));
  foo (x);
  __real__ y = (4.1) + (170) -((short)((((double)(__real__ y)) *((double)(__real__ y)))))*((long)((((double)((6.8))) +((double)((10.4))))))-((long)((((double)((4.8))) +((double)((8.9))))));
  __imag__ y = (4.10) + (42) *((long)((((double)(__imag__ y)) -((double)((10.8))))))*((int)((((double)(__imag__ y)) -((double)((7.2))))))*((long)((((int)((3.7))) &((int)((5.1))))))*((short)((((int)(__imag__ y)) ^((int)((7.8))))));
  bar (y);
  __real__ z = (9.7) + (42) *((int)((((double)(__real__ z)) *((double)(__real__ z)))))+((long)((((double)((9.4))) *((double)((7.3))))))-((short)((((double)(__real__ z)) +((double)((1.2))))))+((long)((((int)((10.5))) %((int)((7.8))))))+((short)((((double)((1.7))) -((double)(__real__ z)))));
  __imag__ z = (6.2) + (0x0666) *((short)((((double)((6.5))) *((double)(__imag__ z)))))-((short)((((double)(__imag__ z)) +((double)((6.1))))))*((int)((((double)((7.3))) *((double)(__imag__ z)))))+((long)((((double)(__imag__ z)) +((double)((10.5))))))*((short)((((int)(__imag__ z)) <<((int)((10.6))))));
  baz (z);
  exit ((0));
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
