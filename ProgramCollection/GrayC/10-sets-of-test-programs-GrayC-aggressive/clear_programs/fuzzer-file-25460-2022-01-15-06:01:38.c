/* corpus/991228-1.c */
__extension__ union { double d; int i[(10)]; } u = { d: -(10.9) };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = (65);
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[(6)]; } u = { d: x };
  return u.i[MSW] < (0);
}

int main(void)
{
  if (((int)(0xB)*sizeof(int) != sizeof(double) || u.i[MSW] >= (-1) + 42 *((long)((((int)(u.i[MSW] >= (-1))) &((int)(sizeof(int))))))-((long)((((double)((0xB))) +((double)(sizeof(int))))))-((int)((((int)((0xB))) |((int)(u.i[MSW] >= (-1))))))-((int)((((int)((-1))) ^((int)(u.i[MSW] >= (-1))))))+((long)((((int)((-1))) |((int)(u.i[MSW])))))))
    exit((0));

  if (!signbit(-(6.10)))
    { abort (); }

  exit((0));
}
/* ProgramSourceLLVM */
