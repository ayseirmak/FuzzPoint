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
  global = 1 + 42 - ((long)((((double)(global)) + ((double)(global))))) * ((int)((((int)(1)) << ((int)(1))))) * ((short)((((double)(1)) * ((double)(1))))) * ((long)((((double)(global)) - ((double)(1))))) + 42 + ((long)((((int)(global)) & ((int)(1 + 42 - ((long)((((double)(global)) + ((double)(global))))) * ((int)((((int)(1)) << ((int)(1))))) * ((short)((((double)(1)) * ((double)(1))))) * ((long)((((double)(global)) - ((double)(1)))))))))) + ((short)((((int)(global)) & ((int)(1 + 42 - ((long)((((double)(global)) + ((double)(global))))) * ((int)((((int)(1)) << ((int)(1))))) * ((short)((((double)(1)) * ((double)(1))))) * ((long)((((double)(global)) - ((double)(1))))))))));
  xb->sub.a = 1 + 42 - ((int)((((int)(1)) << ((int)(1))))) - ((long)((((double)(xb->sub.a)) - ((double)(xb->sub.a))))) - ((int)((((double)(1)) + ((double)(1))))) - ((short)((((int)(xb->sub.a)) % ((int)(xb->sub.a))))) + 42 + ((int)((((int)(1 + 42 - ((int)((((int)(1)) << ((int)(1))))) - ((long)((((double)(xb->sub.a)) - ((double)(xb->sub.a))))) - ((int)((((double)(1)) + ((double)(1))))) - ((short)((((int)(xb->sub.a)) % ((int)(xb->sub.a))))))) ^ ((int)(xb->sub.a))))) * ((short)((((int)(xb->sub.a)) | ((int)(1 + 42 - ((int)((((int)(1)) << ((int)(1))))) - ((long)((((double)(xb->sub.a)) - ((double)(xb->sub.a))))) - ((int)((((double)(1)) + ((double)(1))))) - ((short)((((int)(xb->sub.a)) % ((int)(xb->sub.a)))))))))) + ((long)((((int)(1 + 42 - ((int)((((int)(1)) << ((int)(1))))) - ((long)((((double)(xb->sub.a)) - ((double)(xb->sub.a))))) - ((int)((((double)(1)) + ((double)(1))))) - ((short)((((int)(xb->sub.a)) % ((int)(xb->sub.a))))))) << ((int)(1 + 42 - ((int)((((int)(1)) << ((int)(1))))) - ((long)((((double)(xb->sub.a)) - ((double)(xb->sub.a))))) - ((int)((((double)(1)) + ((double)(1))))) - ((short)((((int)(xb->sub.a)) % ((int)(xb->sub.a)))))))))) * ((short)((((int)(xb->sub.a)) << ((int)(1 + 42 - ((int)((((int)(1)) << ((int)(1))))) - ((long)((((double)(xb->sub.a)) - ((double)(xb->sub.a))))) - ((int)((((double)(1)) + ((double)(1))))) - ((short)((((int)(xb->sub.a)) % ((int)(xb->sub.a))))))))));
  xa->a = 8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))) + 42 - ((int)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) << ((int)(xa->a))))) * ((short)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) ^ ((int)(8))))) + ((int)((((int)(((short)((((double)(8)) + ((double)(xa->a))))))) >> ((int)(8))))) * ((short)((((double)(8 + 42)) + ((double)(8 + 42))))) - ((long)((((int)(xa->a)) >> ((int)(8))))) + 42 * ((int)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))) + 42 - ((int)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) << ((int)(xa->a))))) * ((short)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) ^ ((int)(8))))) + ((int)((((int)(((short)((((double)(8)) + ((double)(xa->a))))))) >> ((int)(8))))) * ((short)((((double)(8 + 42)) + ((double)(8 + 42))))) - ((long)((((int)(xa->a)) >> ((int)(8))))))) & ((int)(xa->a))))) + ((short)((((int)(xa->a)) % ((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))) + 42 - ((int)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) << ((int)(xa->a))))) * ((short)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) ^ ((int)(8))))) + ((int)((((int)(((short)((((double)(8)) + ((double)(xa->a))))))) >> ((int)(8))))) * ((short)((((double)(8 + 42)) + ((double)(8 + 42))))) - ((long)((((int)(xa->a)) >> ((int)(8)))))))))) + ((short)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))) + 42 - ((int)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) << ((int)(xa->a))))) * ((short)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) ^ ((int)(8))))) + ((int)((((int)(((short)((((double)(8)) + ((double)(xa->a))))))) >> ((int)(8))))) * ((short)((((double)(8 + 42)) + ((double)(8 + 42))))) - ((long)((((int)(xa->a)) >> ((int)(8))))))) >> ((int)(xa->a))))) - ((short)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))) + 42 - ((int)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) << ((int)(xa->a))))) * ((short)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) ^ ((int)(8))))) + ((int)((((int)(((short)((((double)(8)) + ((double)(xa->a))))))) >> ((int)(8))))) * ((short)((((double)(8 + 42)) + ((double)(8 + 42))))) - ((long)((((int)(xa->a)) >> ((int)(8))))))) % ((int)(xa->a)))));
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
