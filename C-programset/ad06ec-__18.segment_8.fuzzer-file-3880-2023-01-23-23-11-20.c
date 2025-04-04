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
  global = 1 + 42 - ((long)((((double)(global)) + ((double)(global))))) * ((int)((((int)(1)) << ((int)(1))))) * ((short)((((double)(1)) * ((double)(1))))) * ((long)((((double)(global)) - ((double)(1)))));
  xb->sub.a = 1;
  xa->a = 8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))) + 42 - ((int)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) << ((int)(xa->a))))) * ((short)((((int)(8 + 42 + ((short)((((double)(8)) + ((double)(xa->a))))))) ^ ((int)(8))))) + ((int)((((int)(((short)((((double)(8)) + ((double)(xa->a))))))) >> ((int)(8))))) * ((short)((((double)(8 + 42)) + ((double)(8 + 42))))) - ((long)((((int)(xa->a)) >> ((int)(8)))));
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
