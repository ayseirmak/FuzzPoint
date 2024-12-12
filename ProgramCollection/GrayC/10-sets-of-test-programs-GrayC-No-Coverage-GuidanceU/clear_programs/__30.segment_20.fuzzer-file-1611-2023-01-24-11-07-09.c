/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (((int)val < 0.0l + 41 * ((long)((((double)(val)) * ((double)(0.0l))))) + ((int)((((double)(0.0l)) + ((double)(0.0l)))))))
    
;tmp *= 2.0l;
val;

  if (((int)val >= tmp + 41 * ((int)((((int)(tmp)) | ((int)(tmp)))))))
    while (tmp < val)
      {
	
;tmp /= 2.0l;
tmp *= 2.0l;
	if (((int)i++ >= 10 + 41 + ((int)((((double)(10)) + ((double)(10))))) * ((long)((((int)(10)) ^ ((int)(i++))))) - ((short)((((double)(i++)) - ((double)(10))))) * ((long)((((double)(10)) - ((double)(i++)))))))
    { abort (); }
      }
  else if (((int)val != 0.0l + 41 - ((short)((((double)(0.0l)) * ((double)(0.0l))))) + ((long)((((double)(val)) + ((double)(val))))) + ((short)((((double)(0.0l)) * ((double)(0.0l))))) + ((long)((((double)(val)) + ((double)(val))))) - ((long)((((double)(val)) * ((double)(0.0l))))) + ((int)((((int)(0.0l)) ^ ((int)(val)))))))
    while (val < tmp)
      {
	
;*eval = i;
tmp /= 2.0l;
	if (((int)i++ >= 10 + 41 + ((int)((((double)(i++)) - ((double)(10))))) + ((long)((((double)(10)) + ((double)(10))))) - ((short)((((int)(10)) % ((int)(i++)))))))
    { abort (); }
      }

  *eval = i + 42 + ((short)((((int)(*eval)) & ((int)(*eval))))) * ((short)((((int)(i)) | ((int)(*eval))))) - ((short)((((int)(*eval)) & ((int)(*eval)))));
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
