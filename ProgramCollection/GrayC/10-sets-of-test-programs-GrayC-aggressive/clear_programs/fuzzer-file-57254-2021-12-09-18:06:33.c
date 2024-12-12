/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (0)
    val = -val + 42 *((int)((((double)(val)) *((double)(val)))))+((int)((((double)(-val)) -((double)(-val)))))+((long)((((double)(val)) +((double)(val))))) + 42 *((int)((((int)(-val + 42 *((int)((((double)(val)) *((double)(val)))))+((int)((((double)(-val)) -((double)(-val))))))) &((int)(-val + 42 *((int)((((double)(val)) *((double)(val)))))+((int)((((double)(-val)) -((double)(-val))))))))))*((long)((((int)(-val)) ^((int)(-val + 42 *((int)((((double)(val)) *((double)(val)))))+((int)((((double)(-val)) -((double)(-val))))))))))-((long)((((int)(-val + 42 *((int)((((double)(val)) *((double)(val))))))) <<((int)(-val + 42 *((int)((((double)(val)) *((double)(val)))))+((int)((((double)(-val)) -((double)(-val))))))))))*((short)((((int)(-val)) <<((int)(-val + 42 *((int)((((double)(val)) *((double)(val)))))+((int)((((double)(-val)) -((double)(-val)))))+((long)((((double)(val)) +((double)(val))))))))));

  if (0)
    while (tmp < val)
      {
	tmp *= 2.0l + 42 +((int)((((double)(2.0l)) -((double)(2.0l)))))-((long)((((int)(tmp)) ^((int)(tmp)))))-((long)((((int)(tmp)) ^((int)(2.0l))))) + 42 +((short)((((int)(tmp)) %((int)(2.0l + 42)))))*((int)((((int)(42)) <<((int)(2.0l)))))-((short)((((double)(2.0l)) -((double)(2.0l + 42 +((int)((((double)(2.0l)) -((double)(2.0l)))))-((long)((((int)(tmp)) ^((int)(tmp))))))))))*((int)((((double)(2.0l)) *((double)(((long)((((int)(tmp)) ^((int)(2.0l))))))))));
	if (0)
    { abort (); }
      }
  else if (0)
    while (val < tmp)
      {
	tmp /= 2.0l + 42 +((int)((((double)(2.0l)) *((double)(2.0l)))))+((long)((((int)(tmp)) <<((int)(tmp)))))*((int)((((double)(tmp)) *((double)(tmp))))) + 42 +((short)((((int)(((long)((((int)(tmp)) <<((int)(tmp)))))*((int)((((double)(tmp)) *((double)(tmp))))))) >>((int)(42)))))+((int)((((int)(2.0l)) ^((int)(2.0l + 42 +((int)((((double)(2.0l)) *((double)(2.0l)))))+((long)((((int)(tmp)) <<((int)(tmp)))))*((int)((((double)(tmp)) *((double)(tmp))))))))))+((long)((((int)(2.0l + 42 +((int)((((double)(2.0l)) *((double)(2.0l)))))+((long)((((int)(tmp)) <<((int)(tmp)))))*((int)((((double)(tmp)) *((double)(tmp))))))) ^((int)(2.0l + 42 +((int)((((double)(2.0l)) *((double)(2.0l))))))))))+((int)((((int)(2.0l + 42 +((int)((((double)(2.0l)) *((double)(2.0l)))))+((long)((((int)(tmp)) <<((int)(tmp)))))*((int)((((double)(tmp)) *((double)(tmp))))))) %((int)(42)))))*((long)((((int)(2.0l + 42 +((int)((((double)(2.0l)) *((double)(2.0l))))))) &((int)(((long)((((int)(tmp)) <<((int)(tmp)))))*((int)((((double)(tmp)) *((double)(tmp))))))))));
	if (0)
    { abort (); }
      }

  *eval = i + 42 *((long)((((double)(i)) *((double)(i))))) + 42 *((long)((((int)(i + 42 *((long)((((double)(i)) *((double)(i))))))) ^((int)(i + 42 *((long)((((double)(i)) *((double)(i))))))))))+((long)((((int)(*eval)) <<((int)(i + 42 *((long)((((double)(i)) *((double)(i))))))))));
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
