/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 41 - ((short)(((double)(0.0l)) * ((double)(val)))) - ((int)(((int)(val)) << ((int)(val)))) - ((long)(((int)(val)) ^ ((int)(val)))) + ((short)(((int)(0.0l)) & ((int)(val)))) + ((short)(((int)(0.0l)) | ((int)(val)))) - ((long)(((double)(val)) + ((double)(0.0l)))) * ((int)(((double)(val)) - ((double)(val))))))
    val = -val;

  if (((int)val >= tmp + 41 + ((long)(((double)(val)) + ((double)(val)))) * ((long)(((int)(tmp)) | ((int)(val))))))
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
	if (0)
    { abort (); }
      }

  *eval = i + 42 + ((long)(((int)(*eval)) & ((int)(i)))) + ((int)(((int)(*eval)) >> ((int)(i)))) - ((long)(((int)(i)) & ((int)(*eval))));
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
