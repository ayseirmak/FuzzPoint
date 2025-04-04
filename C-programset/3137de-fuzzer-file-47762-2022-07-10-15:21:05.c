/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 41 * ((long)(((int)(val)) & ((int)(0.0l)))) + ((int)(((double)(0.0l)) + ((double)(val)))) * ((int)(((int)(val)) ^ ((int)(val)))) + ((int)(((double)(val)) * ((double)(val)))) * ((long)(((int)(0.0l)) >> ((int)(0.0l)))) - ((long)(((int)(val)) % ((int)(val))))))
    val = -val + 42 - ((long)(((double)(val)) * ((double)(-val)))) * ((short)(((double)(-val)) + ((double)(val)))) * ((long)(((int)(val)) & ((int)(val)))) - ((short)(((int)(val)) | ((int)(-val))));

  if (((int)val >= tmp + 41 * ((int)(((double)(tmp)) + ((double)(val))))))
    while (tmp < val)
      {
	tmp *= 2.0l;
	if (((int)i++ >= 10 + 41 * ((short)(((int)(i++)) >> ((int)(i++)))) * ((long)(((double)10) - ((double)10))) - ((long)(((double)(i++)) + ((double)(i++)))) + ((long)(((int)(i++)) >> ((int)10))) * ((short)(((double)(i++)) - ((double)(i++)))) * ((long)(((double)10) - ((double)(i++)))) + ((int)(((int)(i++)) << ((int)(i++))))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 + ((long)(((double)(0.0l)) + ((double)(0.0l)))) + ((int)(((double)(0.0l)) + ((double)(0.0l)))) * ((long)(((int)(val)) | ((int)(0.0l)))) * ((long)(((double)(0.0l)) * ((double)(val))))))
    while (val < tmp)
      {
	tmp /= 2.0l;
	if (((int)i++ >= 10 + 41 + ((int)(((int)10) % ((int)10))) * ((int)(((int)10) % ((int)10))) - ((long)(((int)(i++)) ^ ((int)(i++)))) - ((short)(((int)(i++)) ^ ((int)10))) + ((int)(((int)10) & ((int)10))) - ((long)(((double)10) + ((double)(i++)))) - ((short)(((int)10) & ((int)10)))))
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
