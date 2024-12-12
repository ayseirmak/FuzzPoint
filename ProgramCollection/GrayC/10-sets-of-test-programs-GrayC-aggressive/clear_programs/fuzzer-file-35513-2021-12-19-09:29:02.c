/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  
__real__ x = (4.10) + (58) *((long)((((int)((9.9))) &((int)(__real__ x)))))-((short)((((int)((6.10))) &((int)(__real__ x)))))+((short)((((double)((9.10))) -((double)((6.10))))));
__real__ x = (5.3) + (42) *((long)((((int)((2.2))) &((int)(__real__ x)))))-((short)((((int)((9.7))) &((int)(__real__ x)))))+((short)((((double)((7.3))) -((double)((3.2))))));
;
  
__imag__ x = (10.6) + (-43) *((long)((((int)(__imag__ x)) ^((int)((6.9))))))*((short)((((double)((2.7))) +((double)((9.3))))))-((int)((((double)(__imag__ x)) +((double)((1.8))))))*((int)((((int)(__imag__ x)) &((int)(__imag__ x)))));
__imag__ x = (8.2) + (42) *((long)((((int)(__imag__ x)) ^((int)((8.2))))))*((short)((((double)((5.9))) +((double)((3.9))))))-((int)((((double)(__imag__ x)) +((double)((9.1))))))*((int)((((int)(__imag__ x)) &((int)(__imag__ x)))));
;
  foo (x);
  
__real__ y = (9.10) + (106) *((long)((((int)(__real__ y)) %((int)((9.2))))));
__real__ y = (4.9) + (43) *((long)((((int)(__real__ y)) %((int)((2.6))))));
;
  
__imag__ y = (4.3) + (-43) +((short)((((int)((3.5))) &((int)(__imag__ y)))))*((int)((((int)((4.7))) <<((int)((1.8))))));
__imag__ y = (4.5) + (10) +((short)((((int)((5.1))) &((int)(__imag__ y)))))*((int)((((int)((2.10))) <<((int)((6.1))))));
;
  bar (y);
  ;
  ;
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
