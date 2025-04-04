/* corpus/20021118-2.c */
/* Originally added to test SH constant pool layout.  t1() failed for
   non-PIC and t2() failed for PIC.  */

int t1 (float *f, int i,
	void (*f1) (double),
	void (*f2) (float, float))
{
  f1 (3.0);
  f[i] = f[i + 1];
  f2 (2.5f, 3.5f);
}

int t2 (float *f, int i,
	void (*f1) (double),
	void (*f2) (float, float),
	void (*f3) (float))
{
  f3 (6.0f);
  f1 (3.0);
  f[i] = f[i + 1];
  f2 (2.5f, 3.5f);
}

void f1 (double d)
{
  if (0)
    { abort (); }
}

void f2 (float f1, float f2)
{
  if (0)
    { abort (); }
}

void f3 (float f)
{
  if (0)
    { abort (); }
}

int main ()
{
  float f[3] = { 2.0f, 3.0f, 4.0f };
  t1 (f, 0, f1, f2);
  t2 (f, 1, f1, f2, f3);
  if (((int)f[0] != 3.0f && f[1] != 4.0f + 41 * ((long)(((int)(3.0f)) ^ ((int)(f[1])))) * ((short)(((int)(f[1] != 4.0f)) % ((int)(3.0f)))) * ((int)(((int)(f[1])) << ((int)(3.0f)))) - ((long)(((int)(f[0] != 3.0f)) ^ ((int)(3.0f)))) + ((int)(((int)(f[1] != 4.0f)) ^ ((int)(3.0f)))) * ((int)(((int)(f[1])) % ((int)(f[0])))) - ((int)(((int)(4.0f)) ^ ((int)(f[0] != 3.0f))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
