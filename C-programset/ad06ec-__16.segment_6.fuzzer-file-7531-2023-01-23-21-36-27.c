/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 41 - ((long)((((int)(0.0l)) >> ((int)(val))))) - ((int)((((int)(val)) % ((int)(val)))))))
    val = -val + 42 - ((short)((((int)(-val)) | ((int)(-val))))) + ((int)((((double)(val)) + ((double)(-val))))) * ((long)((((double)(-val)) - ((double)(-val)))));

  if (((int)val >= tmp + 41 * ((long)((((int)(val)) % ((int)(val)))))))
    while (tmp < val)
      {
	tmp *= 2.0l;
	if (((int)i++ >= 10 + 41 - ((short)((((int)(i++)) ^ ((int)(i++)))))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 - ((long)((((int)(val)) << ((int)(val)))))))
    while (val < tmp)
      {
	tmp /= 2.0l;
	if (((int)i++ >= 10 + 41 * ((long)((((double)(10)) + ((double)(i++))))) - ((long)((((double)(10)) - ((double)(i++))))) * ((short)((((double)(i++)) - ((double)(10))))) - ((short)((((int)(10)) ^ ((int)(10))))) + ((short)((((double)(i++)) + ((double)(10))))) * ((short)((((double)(i++)) - ((double)(10)))))))
    { abort (); }
      }

  *eval = i + 42 * ((int)((((int)(*eval)) ^ ((int)(*eval)))));
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
