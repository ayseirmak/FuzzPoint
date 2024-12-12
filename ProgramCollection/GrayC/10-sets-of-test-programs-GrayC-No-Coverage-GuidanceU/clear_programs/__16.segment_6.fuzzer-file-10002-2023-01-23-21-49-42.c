/* corpus/20020225-2.c */
static int
test(int x)
{
  union
    {
      int i;
      double d;
  } a;
  a.d = 0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))) + 42 - ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) << ((int)(a.d))))) * ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) >> ((int)(a.d))))) + 42 - ((long)((((double)(a.d)) + ((double)(a.d))))) * ((int)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))) + 42 - ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) << ((int)(a.d))))) * ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) >> ((int)(a.d))))))) << ((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))) + 42 - ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) << ((int)(a.d))))) * ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) >> ((int)(a.d)))))))))) * ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))) + 42 - ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) << ((int)(a.d))))) * ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) >> ((int)(a.d))))))) & ((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))) + 42 - ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) << ((int)(a.d))))) * ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) >> ((int)(a.d)))))))))) * ((long)((((int)(a.d)) % ((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))) + 42 - ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) << ((int)(a.d))))) * ((short)((((int)(0 + 42 - ((long)((((int)(a.d)) % ((int)(a.d))))) * ((long)((((int)(a.d)) | ((int)(0))))))) >> ((int)(a.d))))))))));
  a.i = 1 + 42 + ((short)((((int)(1)) | ((int)(1))))) - ((long)((((double)(1)) * ((double)(a.i)))));
  return x >> a.i;
}

int main(void)
{
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
