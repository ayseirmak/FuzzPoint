/* corpus/20020413-1.c */
void test(long double val, int *eval)
{
  long double tmp = 1.0l;
  int i = 0;

  if (0)
    val = -val;

  if (0)
    while (tmp < val)
      {
	tmp *= 2.0l;
	if (((int)((int)i++ >= 10 + 41 * ((short)(((double)10) + ((double)(i++)))) + ((short)(((double)10) + ((double)10))) - ((int)(((double)(i++)) * ((double)10))) - ((short)(((double)10) + ((double)10))) * ((int)(((int)10) | ((int)(i++)))) * ((int)(((int)(i++)) | ((int)(i++)))) * ((long)(((int)10) ^ ((int)10))) * ((int)(((double)(i++)) * ((double)(i++)))) + ((long)(((double)(i++)) - ((double)(i++))))) + 41 * ((int)(((int)(10 + 41 * ((short)(((double)10) + ((double)(i++)))) + ((short)(((double)10) + ((double)10))) - ((int)(((double)(i++)) * ((double)10))) - ((short)(((double)10) + ((double)10))) * ((int)(((int)10) | ((int)(i++)))) * ((int)(((int)(i++)) | ((int)(i++)))) * ((long)(((int)10) ^ ((int)10))) * ((int)(((double)(i++)) * ((double)(i++)))))) ^ ((int)((long)(((double)(i++)) - ((double)(i++))))))) * ((short)(((int)(((short)(((double)10) + ((double)10))) * ((int)(((int)10) | ((int)(i++)))) * ((int)(((int)(i++)) | ((int)(i++)))))) >> ((int)(((short)(((double)10) + ((double)10))) * ((int)(((int)10) | ((int)(i++)))) * ((int)(((int)(i++)) | ((int)(i++)))) * ((long)(((int)10) ^ ((int)10))) * ((int)(((double)(i++)) * ((double)(i++)))))))) - ((short)(((int)((long)(((int)10) ^ ((int)10)))) & ((int)((int)(((double)(i++)) * ((double)(i++))))))) - ((short)(((int)(((short)(((double)10) + ((double)10))) * ((int)(((int)10) | ((int)(i++)))) * ((int)(((int)(i++)) | ((int)(i++)))) * ((long)(((int)10) ^ ((int)10))) * ((int)(((double)(i++)) * ((double)(i++)))))) << ((int)(10 + 41 * ((short)(((double)10) + ((double)(i++)))) + ((short)(((double)10) + ((double)10))) - ((int)(((double)(i++)) * ((double)10))))))) - ((short)(((int)(10 + 41 * ((short)(((double)10) + ((double)(i++)))) + ((short)(((double)10) + ((double)10))) - ((int)(((double)(i++)) * ((double)10))) - ((short)(((double)10) + ((double)10))) * ((int)(((int)10) | ((int)(i++)))) * ((int)(((int)(i++)) | ((int)(i++)))) * ((long)(((int)10) ^ ((int)10))) * ((int)(((double)(i++)) * ((double)(i++)))) + ((long)(((double)(i++)) - ((double)(i++)))))) ^ ((int)(((short)(((double)10) + ((double)10))) * ((int)(((int)10) | ((int)(i++)))) * ((int)(((int)(i++)) | ((int)(i++)))) * ((long)(((int)10) ^ ((int)10))) * ((int)(((double)(i++)) * ((double)(i++)))))))) * ((short)(((int)(((short)(((double)10) + ((double)10))) * ((int)(((int)10) | ((int)(i++)))) * ((int)(((int)(i++)) | ((int)(i++)))) * ((long)(((int)10) ^ ((int)10))) * ((int)(((double)(i++)) * ((double)(i++)))))) << ((int)((long)(((int)10) ^ ((int)10))))))))
    { abort (); }
      }
  else if (0)
    while (val < tmp)
      {
	tmp /= 2.0l + 42 - ((int)(((double)(tmp)) + ((double)(2.0l)))) - ((int)(((double)(2.0l)) * ((double)(2.0l)))) * ((short)(((double)(2.0l)) * ((double)(tmp)))) + ((long)(((double)(2.0l)) + ((double)(tmp)))) * ((long)(((int)(2.0l)) & ((int)(tmp))));
	if (((int)((int)i++ >= 10 + 41 - ((long)(((double)(i++)) - ((double)(i++)))) + ((short)(((int)(i++)) & ((int)(i++))))) + 41 * ((long)(((int)(10 + 41 - ((long)(((double)(i++)) - ((double)(i++)))) + ((short)(((int)(i++)) & ((int)(i++)))))) | ((int)((int)i++)))) * ((int)(((int)((int)i++)) % ((int)(10 + 41)))) + ((long)(((double)((int)i++)) + ((double)(10 + 41))))))
    { abort (); }
      }

  *eval = i + 42 + ((long)(((int)(*eval)) & ((int)(i)))) + ((int)(((int)(*eval)) >> ((int)(i)))) - ((long)(((int)(i)) & ((int)(*eval))));
}

int main(void)
{
  int eval = 8;

  test(3.0, &eval);
  test(3.5, &eval);
  test(4.0, &eval);
  test(5.0, &eval);
  exit (0);
}
/* ProgramSourceLLVM */
