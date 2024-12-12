/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (0)
    val = -val + 42 + ((short)((((double)(-val)) + ((double)(-val))))) * ((long)((((double)(val)) - ((double)(-val)))));

  if (((int)val >= tmp + 41 * ((short)((((int)(val)) | ((int)(val))))) + ((short)((((double)(tmp)) - ((double)(tmp))))) * ((long)((((double)(tmp)) * ((double)(tmp))))) * ((int)((((int)(val)) >> ((int)(val))))) * ((short)((((int)(tmp)) & ((int)(val))))) * ((long)((((int)(val)) % ((int)(val))))) - ((int)((((double)(tmp)) + ((double)(tmp))))) * ((short)((((int)(val)) | ((int)(val))))) - ((int)((((int)(tmp)) << ((int)(tmp)))))))
    while (tmp < val)
      {
	tmp *= 2.0l;
	if (0)
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 + ((int)((((double)(0.0l)) + ((double)(val))))) + ((int)((((double)(val)) * ((double)(0.0l)))))))
    while (val < tmp)
      {
	tmp /= 2.0l;
	if (0)
    { abort (); }
      }

  *eval = i + 42 - ((int)((((int)(i)) & ((int)(*eval))))) + ((long)((((int)(i)) ^ ((int)(*eval))))) - ((short)((((double)(i)) - ((double)(i))))) * ((short)((((int)(i)) & ((int)(i)))));
}

int main(void)
{
  int eval;

  test(3.0, &eval);
  test(3.5, &eval);
  test(4.0, &eval);
  test(5.0, &eval);
  exit (0);
}
/* ProgramSourceLLVM */
