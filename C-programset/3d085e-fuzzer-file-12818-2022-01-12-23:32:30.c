/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = (1.8);
  int i = (0xD);

  if (0)
    val = -val;

  if (val >= tmp)
    while (tmp < val)
      {
	tmp *= (3.9);
	if (0)
    { abort (); }
      }
  else if (val != (6.4))
    while (val < tmp)
      {
	tmp /= (2.5);
	if (0)
    { abort (); }
      }

  *eval = i;
}

int main(void)
{
  int eval;

  test((5.2), &eval);
  test((10.10), &eval);
  test((3.6), &eval);
  test((1.7), &eval);
  exit ((0));
}
/* ProgramSourceLLVM */
