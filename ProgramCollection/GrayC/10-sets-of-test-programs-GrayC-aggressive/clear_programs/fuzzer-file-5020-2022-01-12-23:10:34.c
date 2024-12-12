/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (val < 0.0l)
    
val = -val;
val = -val;
;

  if (val >= tmp)
    while (tmp < val)
      {
	;
	if (0)
    { abort (); }
      }
  else if (0)
    while (val < tmp)
      {
	;
	if (0)
    { abort (); }
      }

  ;
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
