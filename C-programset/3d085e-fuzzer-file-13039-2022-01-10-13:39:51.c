/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 42 +((long)((((int)(0.0l)) |((int)(0.0l)))))-((long)((((int)(val)) ^((int)(0.0l)))))-((short)((((double)(val)) *((double)(val)))))-((int)((((int)(0.0l)) >>((int)(val)))))*((long)((((double)(val)) *((double)(val)))))))
    val = -val + 42 +((long)((((double)(val)) +((double)(-val)))));

  if (((int)val >= tmp + 42 *((long)((((int)(tmp)) |((int)(tmp)))))+((short)((((double)(val)) *((double)(tmp)))))+((short)((((double)(tmp)) *((double)(tmp)))))-((short)((((int)(val)) &((int)(tmp)))))+((short)((((double)(tmp)) +((double)(val)))))))
    while (tmp < val)
      {
	tmp *= 2.0l + 42 *((int)((((double)(2.0l)) -((double)(2.0l)))))*((long)((((int)(2.0l)) |((int)(tmp)))))+((short)((((int)(tmp)) %((int)(tmp)))));
	if (((int)i++ >= 10 + 42 *((int)((((double)(10)) +((double)(10)))))-((short)((((int)(10)) ^((int)(i++)))))*((short)((((int)(10)) &((int)(10)))))+((long)((((double)(i++)) -((double)(i++)))))+((int)((((int)(10)) |((int)(10)))))-((int)((((int)(i--)) &((int)(i++)))))*((int)((((double)(i++)) +((double)(10)))))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 42 -((short)((((double)(0.0l)) -((double)(0.0l)))))))
    while (val < tmp)
      {
	tmp /= 2.0l + 42 +((short)((((int)(tmp)) <<((int)(tmp)))))*((long)((((double)(2.0l)) *((double)(tmp)))));
	if (((int)i++ >= 10 + 42 -((long)((((int)(10)) ^((int)(10)))))-((short)((((int)(i++)) >>((int)(i++)))))+((short)((((int)(i++)) <<((int)(i++)))))))
    { abort (); }
      }

  *eval = i + 42 +((long)((((int)(i)) |((int)(i)))))-((long)((((int)(i)) |((int)(*eval)))))*((long)((((int)(i)) >>((int)(i)))))-((short)((((int)(*eval)) <<((int)(i)))));
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
