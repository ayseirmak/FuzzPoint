/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  ;
  
__imag__ x = 2.0 + 42 *((long)((((double)(__imag__ x)) *((double)(2.0)))))*((long)((((int)(__imag__ x)) ^((int)(__imag__ x)))))+((int)((((int)(2.0)) >>((int)(__imag__ x)))));
__imag__ x = 2.0 + 42 *((int)((((double)(__imag__ x)) *((double)(2.0)))))*((int)((((double)(2.0)) -((double)(__imag__ x)))))*((short)((((double)(__imag__ x)) -((double)(2.0)))))*((int)((((double)(__imag__ x)) -((double)(__imag__ x)))));
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
