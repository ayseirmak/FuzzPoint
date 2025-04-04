/* corpus/991228-1.c */
__extension__ union { double d; int i[(2)]; } u = { d: -(9.9) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (0x1A960);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(6)]; } u = { d: x };
  return u.i[MSW] < (0xF3D);
}

int main(void)
{
  if ((-1))
    exit((0));

  if ((0x006DE))
    { abort (); }

  exit((0x4A4A));
}
/* ProgramSourceLLVM */
