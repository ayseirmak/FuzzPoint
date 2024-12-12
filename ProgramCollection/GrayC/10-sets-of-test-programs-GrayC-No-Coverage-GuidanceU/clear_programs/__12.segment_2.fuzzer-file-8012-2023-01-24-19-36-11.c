/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 41 * ((short)((((double)(val)) * ((double)(0.0l))))) * ((long)((((double)(val)) * ((double)(val))))) * ((long)((((double)(val)) + ((double)(val))))) + ((short)((((double)(val)) * ((double)(0.0l))))) - ((short)((((int)(val)) % ((int)(val))))) + ((int)((((int)(0.0l)) >> ((int)(0.0l))))) * ((int)((((double)(0.0l)) + ((double)(val))))) * ((long)((((double)(0.0l)) * ((double)(0.0l))))) + ((short)((((double)(0.0l)) + ((double)(0.0l)))))))
    val = -val + 42 * ((int)((((int)(val)) ^ ((int)(-val))))) + ((long)((((int)(-val)) << ((int)(-val))))) * ((long)((((double)(-val)) - ((double)(val))))) * ((short)((((int)(val)) | ((int)(val))))) + ((long)((((int)(-val)) & ((int)(val)))));

  if (((int)val >= tmp + 41 - ((long)((((double)(tmp)) - ((double)(tmp))))) + ((short)((((int)(tmp)) | ((int)(val))))) + ((long)((((double)(val)) * ((double)(tmp))))) * ((short)((((double)(val)) - ((double)(val))))) - ((short)((((double)(val)) + ((double)(val))))) - ((long)((((double)(tmp)) + ((double)(val))))) - ((short)((((double)(tmp)) - ((double)(tmp))))) * ((int)((((int)(tmp)) % ((int)(val)))))))
    while (tmp < val)
      {
	tmp *= 2.0l + 42 - ((short)((((int)(tmp)) & ((int)(tmp)))));
	if (((int)i++ >= 10 + 41 + ((short)((((double)(10)) + ((double)(10))))) * ((short)((((double)(10)) * ((double)(i++))))) + ((long)((((double)(i++)) + ((double)(10)))))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 + ((long)((((double)(val)) + ((double)(0.0l))))) - ((short)((((int)(0.0l)) & ((int)(0.0l)))))))
    while (val < tmp)
      {
	tmp /= 2.0l;
	if (((int)i++ >= 10 + 41 + ((long)((((int)(i++)) | ((int)(i++))))) * ((int)((((double)(10)) + ((double)(i++))))) + ((short)((((double)(10)) + ((double)(10))))) - ((int)((((double)(10)) - ((double)(i++))))) + ((long)((((double)(10)) - ((double)(10)))))))
    { abort (); }
      }

  *eval = i;
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
