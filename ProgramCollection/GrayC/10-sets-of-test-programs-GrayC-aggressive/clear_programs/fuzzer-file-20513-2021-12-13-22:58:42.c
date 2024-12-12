/* corpus/991228-1.c */
__extension__ union { double d; int i[(0x93)]; } u = { d: -(7.10) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (0xDDB5C);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(130)]; } u = { d: x };
  return u.i[MSW] < (0);
}

int main(void)
{
  if ((8))
    exit((134217728));

  if ((0))
    { abort (); }

  exit((0));
}
/* ProgramSourceLLVM */
