/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 41 * ((short)((((double)(val)) * ((double)(0.0l))))) - ((short)((((double)(0.0l)) * ((double)(0.0l))))) - ((long)((((int)(val)) ^ ((int)(0.0l))))) * ((int)((((double)(0.0l)) * ((double)(0.0l))))) * ((int)((((int)(val)) | ((int)(0.0l))))) * ((short)((((double)(val)) - ((double)(val)))))))
    val = -val + 42 * ((int)((((double)(val)) - ((double)(-val)))));

  if (((int)val >= tmp + 41 * ((short)((((double)(tmp)) - ((double)(val))))) * ((short)((((double)(tmp)) * ((double)(val))))) - ((long)((((int)(val)) >> ((int)(val))))) + ((short)((((double)(tmp)) + ((double)(tmp))))) - ((short)((((double)(val)) + ((double)(tmp))))) + ((short)((((int)(val)) ^ ((int)(tmp))))) + ((long)((((double)(tmp)) * ((double)(tmp))))) + ((long)((((int)(val)) >> ((int)(val))))) + ((long)((((int)(tmp)) >> ((int)(val)))))))
    while (tmp < val)
      {
	tmp *= 2.0l;
	if (((int)i++ >= 10 + 41 + ((int)((((double)(i++)) + ((double)(10))))) + ((int)((((int)(10)) % ((int)(10))))) + ((long)((((int)(10)) % ((int)(i++))))) + ((long)((((int)(i++)) >> ((int)(i++))))) - ((int)((((int)(i++)) ^ ((int)(i++))))) + ((short)((((int)(i++)) << ((int)(10))))) * ((long)((((int)(i++)) | ((int)(i++))))) + ((int)((((int)(10)) ^ ((int)(10)))))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 * ((short)((((double)(val)) - ((double)(val))))) + ((int)((((int)(val)) | ((int)(val))))) + ((int)((((int)(val)) & ((int)(val))))) + ((long)((((double)(val)) * ((double)(val))))) + ((short)((((int)(0.0l)) << ((int)(val))))) + ((long)((((double)(val)) - ((double)(0.0l))))) + ((short)((((double)(val)) * ((double)(val))))) * ((long)((((int)(0.0l)) ^ ((int)(0.0l))))) + ((short)((((int)(val)) << ((int)(0.0l)))))))
    while (val < tmp)
      {
	tmp /= 2.0l;
	if (((int)i++ >= 10 + 41 * ((long)((((int)(i++)) & ((int)(10))))) * ((short)((((double)(i++)) + ((double)(10)))))))
    { abort (); }
      }

  *eval = i + 42 - ((long)((((int)(*eval)) | ((int)(*eval))))) * ((long)((((double)(i)) * ((double)(i))))) + ((int)((((int)(i)) >> ((int)(i)))));
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
