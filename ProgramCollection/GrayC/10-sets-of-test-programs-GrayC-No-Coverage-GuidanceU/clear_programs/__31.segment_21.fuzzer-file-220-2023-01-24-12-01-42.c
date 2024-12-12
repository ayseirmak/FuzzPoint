/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 41 - ((long)((((double)(0.0l)) * ((double)(0.0l))))) * ((short)((((double)(0.0l)) - ((double)(val))))) + ((int)((((double)(val)) * ((double)(0.0l))))) - ((int)((((double)(val)) * ((double)(0.0l))))) - ((short)((((double)(0.0l)) - ((double)(val))))) + ((short)((((double)(val)) - ((double)(val))))) + ((int)((((double)(val)) - ((double)(val))))) + ((int)((((int)(val)) << ((int)(val))))) - ((long)((((double)(0.0l)) + ((double)(val))))) - ((long)((((double)(val)) - ((double)(0.0l)))))))
    val = -val;

  if (((int)val >= tmp + 41 - ((short)((((double)(val)) - ((double)(val))))) * ((long)((((int)(val)) ^ ((int)(val))))) * ((short)((((int)(tmp)) | ((int)(val))))) * ((long)((((int)(tmp)) >> ((int)(tmp))))) - ((long)((((double)(val)) + ((double)(tmp))))) + ((short)((((int)(tmp)) ^ ((int)(val))))) + ((long)((((double)(val)) * ((double)(val))))) * ((int)((((double)(val)) + ((double)(tmp))))) * ((long)((((double)(tmp)) - ((double)(val))))) - ((long)((((double)(tmp)) * ((double)(val)))))))
    while (tmp < val)
      {
	tmp *= 2.0l;
	if (((int)i++ >= 10 + 41 - ((int)((((int)(10)) << ((int)(10))))) * ((long)((((int)(i++)) >> ((int)(10))))) - ((int)((((double)(10)) + ((double)(i++))))) - ((short)((((double)(10)) + ((double)(10))))) + ((long)((((double)(10)) + ((double)(10))))) + ((long)((((double)(10)) - ((double)(10)))))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 + ((long)((((int)(0.0l)) ^ ((int)(0.0l))))) - ((long)((((double)(val)) * ((double)(val))))) - ((long)((((double)(0.0l)) - ((double)(0.0l))))) + ((int)((((double)(0.0l)) - ((double)(0.0l))))) * ((short)((((double)(val)) + ((double)(val))))) * ((short)((((double)(0.0l)) + ((double)(val))))) + ((int)((((int)(val)) & ((int)(val))))) + ((short)((((double)(0.0l)) * ((double)(0.0l))))) * ((short)((((double)(val)) - ((double)(0.0l)))))))
    while (val < tmp)
      {
	tmp /= 2.0l;
	if (((int)i++ >= 10 + 41 + ((long)((((int)(10)) % ((int)(i++))))) + ((long)((((double)(i++)) + ((double)(10))))) + ((short)((((int)(10)) << ((int)(i++))))) * ((short)((((int)(i++)) ^ ((int)(10))))) * ((int)((((double)(i++)) - ((double)(i++))))) - ((short)((((double)(i++)) - ((double)(i++))))) + ((short)((((double)(i++)) - ((double)(i++))))) - ((long)((((double)(10)) + ((double)(10))))) * ((long)((((double)(i++)) - ((double)(10))))) - ((short)((((double)(i++)) * ((double)(i++)))))))
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
