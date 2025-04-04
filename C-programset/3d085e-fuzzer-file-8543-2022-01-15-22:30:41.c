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
  
__real__ y = 3.0f + 42 +((int)((((double)(__real__ y)) *((double)(__real__ y)))))*((int)((((int)(__real__ y)) ^((int)(3.0f)))));
__real__ y = 3.0f + 42 +((short)((((int)(__real__ y)) >>((int)(3.0f)))));
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
