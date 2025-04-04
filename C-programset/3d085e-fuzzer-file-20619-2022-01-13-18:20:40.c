/* corpus/991228-1.c */
__extension__ union { double d; int i[(0)]; } u = { d: -(2.10) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (0xD0D21);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(66)]; } u = { d: x };
  return u.i[MSW] < (0x7E6D);
}

int main(void)
{
  if ((10)*sizeof(int) != sizeof(double) || u.i[MSW] >= (0))
    exit((36028797018963968));

  if (!signbit(-(8.2)))
    { abort (); }

  exit((0));
}
/* ProgramSourceLLVM */
