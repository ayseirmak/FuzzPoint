/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  ;
  
__imag__ x = 2.0 + 42 -((short)((((double)(__imag__ x)) *((double)(__imag__ x)))));
__imag__ x = 2.0 + 42 -((short)((((double)(__imag__ x)) *((double)(__imag__ x)))));
;
  foo (x);
  ;
  
__imag__ y = 4.0f + 42 *((short)((((double)(__imag__ y)) -((double)(4.0f)))))*((int)((((double)(4.0f)) *((double)(__imag__ y)))))+((short)((((double)(__imag__ y)) +((double)(4.0f)))))*((int)((((double)(__imag__ y)) -((double)(4.0f)))));
__imag__ y = 4.0f + 42 *((short)((((double)(__imag__ y)) -((double)(4.0f)))))*((int)((((double)(4.0f)) *((double)(__imag__ y)))))+((short)((((double)(__imag__ y)) +((double)(4.0f)))))*((int)((((double)(__imag__ y)) -((double)(4.0f)))));
;
  bar (y);
  
__real__ z = 5.0L + 42 +((int)((((int)(__real__ z)) <<((int)(5.0L)))))+((short)((((int)(5.0L)) &((int)(__real__ z)))))-((int)((((int)(5.0L)) &((int)(5.0L)))))-((int)((((double)(__real__ z)) -((double)(__real__ z)))))*((short)((((int)(__real__ z)) |((int)(__real__ z)))));
__real__ z = 5.0L + 42 +((int)((((int)(__real__ z)) <<((int)(5.0L)))))+((short)((((int)(5.0L)) &((int)(__real__ z)))))-((int)((((int)(5.0L)) &((int)(5.0L)))))-((int)((((double)(__real__ z)) -((double)(__real__ z)))))*((short)((((int)(__real__ z)) |((int)(__real__ z)))));
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
