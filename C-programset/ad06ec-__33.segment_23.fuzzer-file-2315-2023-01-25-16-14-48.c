/* corpus/pr29156.c */
extern void abort(void);
struct test1
{
  int a;
  int b;
};
struct test2
{
  float d;
  struct test1 sub;
};

int global;

int bla(struct test1 *xa, struct test2 *xb)
{
  global = 1;
  xb->sub.a = 1 + 42 * ((int)((((int)(1)) & ((int)(1))))) + ((short)((((int)(xb->sub.a)) << ((int)(1))))) - ((int)((((double)(1)) + ((double)(1))))) + ((long)((((int)(xb->sub.a)) & ((int)(1))))) - ((long)((((double)(1)) * ((double)(1)))));
  xa->a = 8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8))))) + 42 - ((long)((((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8))))))) >> ((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8)))))))))) + ((int)((((int)(xa->a)) | ((int)(xa->a))))) + ((int)((((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8))))))) ^ ((int)(xa->a))))) + 42 * ((short)((((int)(xa->a)) & ((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8))))) + 42 - ((long)((((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8))))))) >> ((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8)))))))))) + ((int)((((int)(xa->a)) | ((int)(xa->a))))) + ((int)((((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8))))))) ^ ((int)(xa->a)))))))))) + ((short)((((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8))))) + 42 - ((long)((((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8))))))) >> ((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8)))))))))) + ((int)((((int)(xa->a)) | ((int)(xa->a))))) + ((int)((((int)(8 + 42 * ((short)((((int)(8)) ^ ((int)(8))))) + ((long)((((int)(xa->a)) << ((int)(xa->a))))) - ((int)((((int)(8)) >> ((int)(8))))) * ((short)((((int)(xa->a)) % ((int)(8))))) - ((short)((((double)(8)) + ((double)(8))))))) ^ ((int)(xa->a))))))) >> ((int)(xa->a))))) * ((long)((((int)(xa->a)) ^ ((int)(xa->a)))));
  return xb->sub.a;
}

int main(void)
{
  struct test2 pom;

  if (0)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
