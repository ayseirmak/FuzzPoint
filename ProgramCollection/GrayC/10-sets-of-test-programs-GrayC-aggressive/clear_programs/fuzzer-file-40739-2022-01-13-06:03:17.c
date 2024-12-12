/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (0)
    val = -val + 42 +((int)((((int)(val)) &((int)(-val)))))*((short)((((double)(-val)) +((double)(-val)))));

  if (((int)val >= tmp + 42 -((int)((((double)(val)) +((double)(val)))))-((int)((((int)(val)) |((int)(val)))))))
    while (tmp < val)
      {
	tmp *= 2.0l + 42 +((long)((((int)(tmp)) <<((int)(2.0l)))))*((int)((((double)(2.0l)) -((double)(tmp)))));
	if (((int)i++ >= 10 + 42 *((short)((((double)(i++)) +((double)(i++)))))*((int)((((double)(i++)) -((double)(i++)))))*((short)((((int)(10)) |((int)(i++)))))*((long)((((int)(i++)) |((int)(i++)))))*((long)((((int)(10)) %((int)(i++)))))+((long)((((double)(10)) +((double)(10)))))+((short)((((double)(i++)) +((double)(i++)))))-((short)((((int)(10)) |((int)(10)))))+((int)((((int)(i++)) |((int)(10)))))*((int)((((double)(i++)) *((double)(i++)))))))
    { abort (); }
      }
  else if (0)
    while (val < tmp)
      {
	tmp /= 2.0l + 42 *((short)((((double)(tmp)) -((double)(tmp)))));
	if (((int)i++ >= 10 + 42 -((long)((((double)(i++)) +((double)(i++)))))*((short)((((double)(10)) -((double)(10)))))+((long)((((double)(10)) +((double)(10)))))-((int)((((double)(10)) -((double)(10)))))-((long)((((double)(10)) *((double)(i++)))))*((int)((((double)(i++)) -((double)(i++)))))-((int)((((int)(10)) <<((int)(10)))))-((long)((((double)(i++)) *((double)(10)))))))
    { abort (); }
      }

  *eval = i + 42 -((long)((((int)(*eval)) |((int)(i)))));
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
