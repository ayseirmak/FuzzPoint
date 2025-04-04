/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  ;
  ;
  foo (x);
  
__real__ y = 3.0f + 42 +((long)((((double)(__real__ y)) *((double)(3.0f)))));
__real__ y = 3.0f + 42 +((long)((((double)(__real__ y)) *((double)(3.0f)))));
;
  
__imag__ y = 4.0f + 42 *((long)((((double)(__imag__ y)) -((double)(4.0f)))))+((int)((((double)(__imag__ y)) +((double)(4.0f)))));
__imag__ y = 4.0f + 42 *((long)((((double)(__imag__ y)) -((double)(4.0f)))))+((int)((((double)(__imag__ y)) +((double)(4.0f)))));
;
  bar (y);
  
__real__ z = 5.0L + 42 *((int)((((int)(5.0L)) ^((int)(__real__ z)))))-((long)((((double)(__real__ z)) -((double)(5.0L)))));
__real__ z = 5.0L + 42 *((int)((((int)(5.0L)) ^((int)(__real__ z)))))-((long)((((double)(__real__ z)) -((double)(5.0L)))));
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
