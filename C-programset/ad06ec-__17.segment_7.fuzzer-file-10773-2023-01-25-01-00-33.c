/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 8;

  if (((int)val < 0.0l + 41 * ((long)((((int)(0.0l)) % ((int)(val))))) - ((int)((((double)(val)) + ((double)(0.0l))))) + ((short)((((double)(0.0l)) + ((double)(val))))) - ((int)((((int)(0.0l)) % ((int)(val))))) * ((long)((((double)(val)) * ((double)(val)))))))
    val = -val;

  if (0)
    while (tmp < val)
      {
	tmp *= 2.0l + 42 + ((short)((((int)(tmp)) & ((int)(tmp))))) * ((short)((((int)(tmp)) ^ ((int)(tmp))))) - ((long)((((double)(tmp)) - ((double)(2.0l))))) + ((long)((((double)(2.0l)) * ((double)(tmp)))));
	if (0)
    { abort (); }
      }
  else if (0)
    while (val < tmp)
      {
	tmp /= 2.0l + 42 * ((long)((((double)(tmp)) - ((double)(tmp))))) - ((long)((((double)(tmp)) + ((double)(tmp))))) - ((short)((((double)(2.0l)) - ((double)(2.0l)))));
	if (((int)i++ >= 10 + 41 - ((int)((((int)(i++)) % ((int)(i++))))) + ((short)((((double)(i++)) + ((double)(i++))))) - ((short)((((double)(10)) * ((double)(i++))))) + ((int)((((double)(i++)) - ((double)(10))))) - ((short)((((int)(i++)) & ((int)(10))))) + ((short)((((double)(i++)) - ((double)(10))))) - ((int)((((double)(10)) + ((double)(i++))))) - ((int)((((double)(i++)) + ((double)(10))))) + ((long)((((double)(i++)) + ((double)(i++))))) + ((short)((((int)(10)) >> ((int)(i++)))))))
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
