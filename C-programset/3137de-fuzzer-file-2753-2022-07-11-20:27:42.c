/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (0)
    val = -val + 42 - ((long)(((double)(val)) + ((double)(val))));

  if (0)
    while (tmp < val)
      {
	tmp *= 2.0l + 42 * ((long)(((int)(2.0l)) & ((int)(tmp))));
	if (((int)i++ >= 10 + 41 - ((int)(((double)10) - ((double)(i++)))) + ((short)(((int)10) ^ ((int)10))) + ((long)(((double)(i++)) - ((double)(i++)))) + ((long)(((int)10) >> ((int)(i++))))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 + ((short)(((double)(0.0l)) + ((double)(0.0l)))) * ((short)(((double)(0.0l)) * ((double)(val)))) * ((int)(((double)(0.0l)) - ((double)(0.0l)))) * ((int)(((int)(0.0l)) ^ ((int)(0.0l))))))
    while (val < tmp)
      {
	tmp /= 2.0l + 42 + ((long)(((double)(tmp)) + ((double)(2.0l)))) - ((int)(((double)(2.0l)) + ((double)(tmp))));
	if (0)
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
