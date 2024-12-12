/* corpus/991228-1.c */
__extension__ union { double d; int i[(2)]; } u = { d: -(7.2) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (0xD2);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(2)]; } u = { d: x };
  return u.i[MSW] < (0x5);
}

int main(void)
{
  if (((int)(34)*sizeof(int) != sizeof(double) || u.i[MSW] >= (-1) + (170) -((int)((((int)((0x17D)*sizeof(int) != sizeof(double))) |((int)(u.i[MSW])))))+((int)((((int)(sizeof(double))) %((int)((-3)*sizeof(int) != sizeof(double))))))))
    exit((0));

  if (!signbit(-(9.10)))
    { abort (); }

  exit((0x7F));
}
/* ProgramSourceLLVM */
