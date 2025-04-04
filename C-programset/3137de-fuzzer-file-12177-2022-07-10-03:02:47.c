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
  if (((int)2*sizeof(int) != sizeof(double) || u.i[MSW] >= 0 + 41 - ((int)(((int)(2*sizeof(int) != sizeof(double))) ^ ((int)(sizeof(double))))) - ((short)(((int)(u.i[MSW] >= 0)) << ((int)0))) - ((short)(((double)(sizeof(double))) * ((double)(sizeof(int))))) + ((int)(((int)0) ^ ((int)(2*sizeof(int))))) - ((long)(((int)(u.i[MSW])) >> ((int)(2*sizeof(int))))) - ((int)(((int)(sizeof(int))) << ((int)(sizeof(double))))) - ((long)(((int)(sizeof(int))) ^ ((int)(2*sizeof(int))))) - ((short)(((int)2) << ((int)0))) * ((int)(((int)(2*sizeof(int) != sizeof(double))) << ((int)(2*sizeof(int) != sizeof(double)))))))
    exit(0);

  if (!signbit(-0.25))
    { abort (); }

  exit(0);
}
/* ProgramSourceLLVM */
