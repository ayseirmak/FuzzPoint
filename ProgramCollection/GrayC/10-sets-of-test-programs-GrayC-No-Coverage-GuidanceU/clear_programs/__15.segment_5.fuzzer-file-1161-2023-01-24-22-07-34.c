/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (0)
    val = -val + 42 + ((int)((((double)(val)) + ((double)(-val))))) - ((int)((((double)(val)) + ((double)(val))))) * ((int)((((double)(-val)) * ((double)(-val))))) * ((int)((((int)(-val)) ^ ((int)(val))))) + 42 - ((int)((((int)(-val + 42)) ^ ((int)(42))))) - ((short)((((int)(-val + 42)) | ((int)(-val)))));

  if (0)
    while (tmp < val)
      {
	tmp *= 2.0l + 42 + ((long)((((double)(tmp)) - ((double)(tmp))))) * ((long)((((double)(2.0l)) * ((double)(tmp)))));
	if (0)
    { abort (); }
      }
  else if (((int)((int)val != 0.0l + 41 + ((short)((((int)(0.0l)) >> ((int)(val)))))) + 41 - ((int)((((double)(0.0l + 41 + ((short)((((int)(0.0l)) >> ((int)(val))))))) - ((double)(0.0l))))) * ((int)((((double)(((short)((((int)(0.0l)) >> ((int)(val))))))) - ((double)(0.0l + 41)))))))
    while (val < tmp)
      {
	tmp /= 2.0l + 42 * ((long)((((double)(tmp)) * ((double)(tmp))))) - ((long)((((int)(tmp)) | ((int)(tmp))))) + ((short)((((int)(2.0l)) << ((int)(tmp))))) - ((short)((((double)(tmp)) + ((double)(2.0l)))));
	if (((int)i++ >= 10 + 41 - ((int)((((double)(i++)) * ((double)(10))))) + ((int)((((int)(10)) % ((int)(i++))))) - ((long)((((double)(10)) - ((double)(10))))) + ((int)((((int)(i++)) % ((int)(i++))))) * ((int)((((int)(i++)) ^ ((int)(i++)))))))
    { abort (); }
      }

  *eval = i;
}

int main(void)
{
  int eval = 8;

  test(3.0, &eval);
  test(3.5, &eval);
  test(4.0, &eval);
  test(5.0, &eval);
  exit (0);
}
/* ProgramSourceLLVM */
