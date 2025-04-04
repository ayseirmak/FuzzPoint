/* corpus/991228-1.c */
__extension__ union { double d; int i[2]; } u = { d: -0.25 };

/* This assumes the endianness of words in a long long is the same as
   that for doubles, which doesn't hold for a few platforms, but we
   can probably special case them here, as appropriate.  */
long long endianness_test = 1;
#define MSW (*(int*)&endianness_test)

int
signbit(double x)
{
  __extension__ union { double d; int i[2]; } u = { d: x };
  return u.i[MSW] < 0;
}

int main(void)
{
  if (((int)2*sizeof(int) != sizeof(double) || u.i[MSW] >= 0 + 41 * ((long)((((double)(0)) + ((double)(2))))) * ((int)((((int)(2)) % ((int)(2*sizeof(int)))))) * ((short)((((int)(0)) % ((int)(2*sizeof(int)))))) + ((int)((((int)(sizeof(double))) ^ ((int)(sizeof(int)))))) * ((short)((((int)(u.i[MSW])) & ((int)(u.i[MSW])))))))
    exit(0);

  if (!signbit(-0.25))
    { abort (); }

  exit(0);
}
/* ProgramSourceLLVM */
