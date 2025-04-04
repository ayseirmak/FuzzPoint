/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 8;

  if (0)
    val = -val;

  if (0)
    while (tmp < val)
      {
	tmp *= 2.0l;
	if (((int)i++ >= 10 + 41 * ((short)(((double)10) * ((double)10))) + ((short)(((int)(i++)) & ((int)10))) + ((int)(((double)(i++)) + ((double)10))) * ((long)(((double)10) - ((double)10))) * ((int)(((int)(i++)) % ((int)(i++)))) * ((long)(((double)10) + ((double)10))) - ((long)(((int)(i++)) & ((int)10)))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 * ((short)(((int)(0.0l)) & ((int)(val)))) - ((short)(((int)(0.0l)) ^ ((int)(val)))) * ((int)(((double)(0.0l)) - ((double)(val)))) * ((long)(((int)(0.0l)) & ((int)(val)))) - ((short)(((int)(0.0l)) >> ((int)(val)))) + ((long)(((double)(val)) - ((double)(0.0l)))) - ((int)(((double)(val)) + ((double)(0.0l)))) + ((int)(((double)(0.0l)) * ((double)(val)))) + ((short)(((double)(0.0l)) - ((double)(0.0l))))))
    while (val < tmp)
      {
	tmp /= 2.0l + 42 * ((short)(((int)(2.0l)) % ((int)(tmp))));
	if (0)
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
