/* corpus/991228-1.c */
__extension__ union { double d; int i[(0)]; } u = { d: -(10.8) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (17);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(130)]; } u = { d: x };
  return u.i[MSW] < (-1);
}

int main(void)
{
  if (0)
    exit((-1));

  if (0)
    { abort (); }

  exit((134217728));
}
/* ProgramSourceLLVM */
