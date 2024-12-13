/* corpus/pr38969.c */
__complex__ float
__attribute__ ((noinline)) foo (__complex__ float x)
{
  return x;
}

__complex__ float
__attribute__ ((noinline)) bar (__complex__ float x)
{
  return foo (x);
}

int main()
{
  __complex__ float a, b;
  __real__ a;
  
;b = bar (a);
42;

  bar (a);

  if (0)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
