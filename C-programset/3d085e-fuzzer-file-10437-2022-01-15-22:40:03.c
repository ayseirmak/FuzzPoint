/* corpus/991228-1.c */
__extension__ union { double d; int i[(0xE3)]; } u = { d: -(9.10) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (1);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(2)]; } u = { d: x };
  return u.i[MSW] < (4096);
}

int main(void)
{
  if (((int)(-3)*sizeof(int) != sizeof(double) || u.i[MSW] >= (0) + (42) +((long)((((int)((-3)*sizeof(int))) <<((int)((130))))))*((int)((((int)(u.i[MSW] >= (0))) &((int)(u.i[MSW] >= (-1))))))))
    exit((0));

  if (!signbit(-(1.7)))
    { abort (); }

  exit((0));
}
/* ProgramSourceLLVM */
