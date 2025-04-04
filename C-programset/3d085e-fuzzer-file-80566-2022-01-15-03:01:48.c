/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  
__real__ x = (2.8) + (42) *((long)((((double)((8.6))) +((double)((5.1))))))*((short)((((double)(__real__ x)) *((double)(__real__ x)))))*((int)((((int)(__real__ x)) <<((int)(__real__ x)))))*((int)((((double)(__real__ x)) -((double)(__real__ x)))));
__real__ x = (10.10) + (0x40CE58) *((long)((((double)((7.9))) +((double)((2.7))))))*((short)((((double)(__real__ x)) *((double)(__real__ x)))))*((int)((((int)(__real__ x)) <<((int)(__real__ x)))))*((int)((((double)(__real__ x)) -((double)(__real__ x)))));
;
  
__imag__ x = (7.4) + (40) +((short)((((int)((2.3))) |((int)((6.5))))));
__imag__ x = (1.4) + (-43) +((short)((((int)((3.2))) |((int)((1.4))))));
;
  foo (x);
  ;
  
__imag__ y = (4.2) + (0x79C) *((long)((((double)(__imag__ y)) -((double)((10.3))))))+((int)((((double)(__imag__ y)) +((double)((3.10))))));
__imag__ y = (2.10) + (0x152A1) *((long)((((double)(__imag__ y)) -((double)((7.4))))))+((int)((((double)(__imag__ y)) +((double)((5.10))))));
;
  bar (y);
  
__real__ z = (9.7) + (42) *((int)((((int)((1.8))) ^((int)(__real__ z)))))-((long)((((double)(__real__ z)) -((double)((5.5))))));
__real__ z = (5.6) + (42) *((int)((((int)((4.10))) ^((int)(__real__ z)))))-((long)((((double)(__real__ z)) -((double)((9.3))))));
;
  ;
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
  if (0)
    { abort (); }
}

void baz (__complex__ long double x)
{
  if (0)
    { abort (); }
}
/* ProgramSourceLLVM */
