/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 42 *((short)((((int)(val)) <<((int)(val)))))-((int)((((int)(val)) >>((int)(val)))))-((short)((((double)(val)) +((double)(0.0l)))))*((int)((((int)(0.0l)) ^((int)(val)))))))
    ;

  if (((int)val >= tmp + 42 -((int)((((double)(val)) -((double)(val)))))-((short)((((int)(tmp)) ^((int)(tmp)))))))
    while (tmp < val)
      {
	;
	if (((int)i++ >= 10 + 42 -((short)((((int)(10)) ^((int)(10)))))*((short)((((double)(10)) +((double)(i++)))))*((short)((((int)(i++)) &((int)(10)))))-((short)((((double)(i++)) *((double)(10)))))*((int)((((double)(10)) -((double)(10)))))*((short)((((int)(i++)) |((int)(10)))))+((long)((((double)(10)) -((double)(i++)))))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 42 *((short)((((double)(0.0l)) +((double)(0.0l)))))-((int)((((double)(val)) +((double)(val)))))-((short)((((double)(val)) *((double)(0.0l)))))-((int)((((int)(0.0l)) >>((int)(val)))))*((short)((((int)(0.0l)) &((int)(val)))))-((long)((((double)(val)) +((double)(0.0l)))))))
    while (val < tmp)
      {
	
tmp /= 2.0l + 42 -((short)((((int)(2.0l)) >>((int)(2.0l)))))*((long)((((double)(tmp)) +((double)(2.0l)))));
tmp /= 2.0l + 42 *((int)((((int)(tmp)) &((int)(tmp)))))+((short)((((int)(tmp)) >>((int)(2.0l)))));
;
	if (((int)i++ >= 10 + 42 +((int)((((int)(i++)) >>((int)(10)))))-((short)((((int)(10)) ^((int)(10)))))))
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
