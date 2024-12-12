/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 41 * ((long)((((int)(val)) & ((int)(0.0l))))) + ((short)((((double)(0.0l)) * ((double)(0.0l))))) * ((long)((((double)(0.0l)) * ((double)(0.0l))))) * ((short)((((double)(0.0l)) + ((double)(0.0l)))))))
    val = -val;

  if (0)
    while (tmp < val)
      {
	tmp *= 2.0l + 42 + ((int)((((double)(tmp)) + ((double)(2.0l))))) + ((short)((((double)(tmp)) + ((double)(tmp))))) + ((int)((((double)(tmp)) * ((double)(2.0l))))) + ((short)((((int)(2.0l)) << ((int)(2.0l)))));
	if (0)
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 * ((short)((((double)(val)) + ((double)(0.0l))))) + ((long)((((double)(0.0l)) - ((double)(0.0l))))) * ((long)((((int)(0.0l)) >> ((int)(val))))) * ((long)((((int)(val)) & ((int)(0.0l))))) + ((short)((((int)(val)) & ((int)(0.0l)))))))
    while (val < tmp)
      {
	tmp /= 2.0l;
	if (0)
    { abort (); }
      }

  *eval = i + 42 + ((int)((((int)(*eval)) << ((int)(i)))));
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
