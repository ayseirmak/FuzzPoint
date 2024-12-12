/* corpus/991228-1.c */
__extension__ union { double d; int i[(2)]; } u = { d: -(3.7) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (1);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(0x9832B)]; } u = { d: x };
  return u.i[MSW] < (33554432);
}

int main(void)
{
  if (0)
    exit((0xD));

  if (0)
    { abort (); }

  exit((0));
}
/* ProgramSourceLLVM */
