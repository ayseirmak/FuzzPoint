/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 8;

  if (0)
    ;

  if (0)
    while (tmp < val)
      {
	
tmp *= 2.0l + 42 +((long)((((double)(tmp)) *((double)(2.0l)))))*((long)((((int)(tmp)) &((int)(2.0l)))))*((short)((((int)(2.0l)) <<((int)(tmp)))))-((int)((((int)(tmp)) <<((int)(2.0l)))))+((long)((((double)(tmp)) -((double)(2.0l)))));
tmp *= 2.0l + 42 +((int)((((double)(2.0l)) +((double)(tmp)))))*((int)((((int)(2.0l)) &((int)(2.0l)))))+((short)((((double)(tmp)) -((double)(2.0l)))))*((int)((((double)(tmp)) -((double)(tmp)))))+((short)((((int)(tmp)) %((int)(tmp)))));
;
	if (0)
    { abort (); }
      }
  else if (0)
    while (val < tmp)
      {
	
tmp /= 2.0l + 42 -((long)((((int)(tmp)) %((int)(2.0l)))))*((int)((((int)(tmp)) ^((int)(2.0l)))));
tmp /= 2.0l + 42 -((short)((((int)(2.0l)) >>((int)(tmp)))));
;
	if (0)
    { abort (); }
      }

  
*eval = i + 42 *((short)((((int)(i)) &((int)(*eval)))));
*eval = i + 42 *((int)((((int)(*eval)) &((int)(i)))))*((long)((((int)(i)) &((int)(*eval)))));
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
