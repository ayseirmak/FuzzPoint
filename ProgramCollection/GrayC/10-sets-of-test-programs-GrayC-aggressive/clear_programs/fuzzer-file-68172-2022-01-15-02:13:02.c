/* corpus/991228-1.c */
__extension__ union { double d; int i[(2)]; } u = { d: -(10.7) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (-2);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(2)]; } u = { d: x };
  return u.i[MSW] < (0);
}

int main(void)
{
  if ((0x18F4))
    exit((65536));

  if ((33554432))
    { abort (); }

  exit((0));
}
/* ProgramSourceLLVM */
