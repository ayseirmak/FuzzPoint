/* corpus/20010605-2.c */
void foo (), bar (), baz ();
int main ()
{
  __complex__ double x;
  __complex__ float y;
  __complex__ long double z;
  
__real__ x = 1.0;
__real__ x = 1.0;
;
  ;
  foo (x);
  ;
  ;
  bar (y);
  
__real__ z = 5.0L;
__real__ z = 5.0L;
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
