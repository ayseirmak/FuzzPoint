/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  
__real__ x = 1.0 + 42 +((int)((((int)(1.0)) >>((int)(1.0)))))*((int)((((double)(1.0)) *((double)(__real__ x)))))+((int)((((double)(__real__ x)) *((double)(__real__ x)))));
__real__ x = 1.0 + 42 -((short)((((double)(1.0)) -((double)(__real__ x)))));
;
  
__imag__ x = 2.0 + 42 +((long)((((int)(__imag__ x)) |((int)(__imag__ x)))))*((int)((((int)(2.0)) |((int)(__imag__ x)))));
__imag__ x = 2.0 + 42 +((int)((((double)(__imag__ x)) *((double)(2.0)))))-((long)((((int)(2.0)) |((int)(2.0)))))*((long)((((double)(__imag__ x)) +((double)(__imag__ x)))))-((long)((((double)(__imag__ x)) -((double)(2.0)))))*((short)((((int)(2.0)) &((int)(2.0)))));
;
  foo (x);
  ;
  ;
  bar (y);
  ;
  ;
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
