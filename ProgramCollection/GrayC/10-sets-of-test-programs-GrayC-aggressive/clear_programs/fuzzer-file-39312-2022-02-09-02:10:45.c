/* corpus/991228-1.c */
__extension__ union { double d; int i[(18)]; } u = { d: -(9.10) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (1);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(6)]; } u = { d: x };
  return u.i[MSW] < (0);
}

int main(void)
{
  if (((int)(10)*sizeof(int) != sizeof(double) || u.i[MSW] >= (0) + 42 *((short)((((int)((10)*sizeof(int) != sizeof(double))) %((int)(u.i[MSW])))))*((long)((((int)(u.i[MSW] >= (0))) %((int)((10)*sizeof(int) != sizeof(double))))))-((int)((((int)(sizeof(double))) <<((int)(sizeof(int))))))-((short)((((int)(u.i[MSW] >= (0))) ^((int)(sizeof(int))))))))
    exit((0));

  if (0)
    { abort (); }

  exit((1024));
}
/* ProgramSourceLLVM */
