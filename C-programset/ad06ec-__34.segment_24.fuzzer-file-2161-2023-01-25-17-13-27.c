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
  global = 1 + 42 - ((int)((((double)(global)) - ((double)(global))))) * ((short)((((double)(global)) + ((double)(1))))) + ((long)((((double)(global)) * ((double)(global))))) * ((long)((((double)(1)) * ((double)(1))))) + 42 + ((long)((((double)(global)) * ((double)(global))))) - ((int)((((double)(global)) * ((double)(global))))) * ((short)((((int)(global)) << ((int)(global)))));
  xb->sub.a = 1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a))))) + 42 * ((long)((((int)(xb->sub.a)) % ((int)(1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a)))))))))) + 42 - ((short)((((int)(1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a))))) + 42 * ((long)((((int)(xb->sub.a)) % ((int)(1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a)))))))))))) << ((int)(xb->sub.a))))) * ((long)((((int)(1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a))))) + 42 * ((long)((((int)(xb->sub.a)) % ((int)(1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a)))))))))))) % ((int)(xb->sub.a))))) + ((long)((((int)(1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a))))) + 42 * ((long)((((int)(xb->sub.a)) % ((int)(1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a)))))))))))) ^ ((int)(xb->sub.a))))) * ((short)((((double)(xb->sub.a)) - ((double)(xb->sub.a))))) - ((short)((((int)(xb->sub.a)) & ((int)(1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a))))) + 42 * ((long)((((int)(xb->sub.a)) % ((int)(1 + 42 - ((long)((((double)(xb->sub.a)) * ((double)(xb->sub.a)))))))))))))));
  xa->a = 8 + 42 * ((short)((((int)(xa->a)) & ((int)(8))))) + 42 * ((short)((((int)(8)) & ((int)(42)))));
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
