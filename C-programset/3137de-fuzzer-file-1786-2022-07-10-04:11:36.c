/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (0)
    val = -val;

  if (((int)val >= tmp + 41 * ((short)(((int)(val)) ^ ((int)(val)))) - ((int)(((double)(val)) - ((double)(tmp)))) + ((int)(((double)(tmp)) - ((double)(val)))) + ((int)(((int)(tmp)) | ((int)(tmp)))) - ((long)(((double)(tmp)) - ((double)(val)))) + ((int)(((int)(tmp)) >> ((int)(val)))) + ((short)(((int)(val)) << ((int)(val)))) * ((int)(((double)(val)) * ((double)(val)))) - ((short)(((int)(val)) & ((int)(val))))))
    while (tmp < val)
      {
	tmp *= 2.0l;
	if (0)
    { abort (); }
      }
  else if (0)
    while (val < tmp)
      {
	tmp /= 2.0l;
	if (((int)i++ >= 10 + 41 + ((short)(((double)(i++)) * ((double)10))) * ((short)(((int)(i++)) & ((int)10))) - ((short)(((double)(i++)) + ((double)(i++)))) - ((int)(((int)(i++)) << ((int)(i++)))) - ((int)(((double)(i++)) * ((double)(i++)))) - ((long)(((double)(i++)) * ((double)10)))))
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
