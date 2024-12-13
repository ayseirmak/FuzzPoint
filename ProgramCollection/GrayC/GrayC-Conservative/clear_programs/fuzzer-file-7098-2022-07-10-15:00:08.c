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
  global = 1 + 42 - ((int)(((double)(global)) * ((double)1))) + ((int)(((int)(global)) % ((int)(global))));
  xb->sub.a = 1;
  xa->a = 8 + 42 + ((short)(((int)(xa->a)) & ((int)(xa->a)))) - ((int)(((double)8) * ((double)8))) + ((short)(((int)(xa->a)) << ((int)(xa->a))));
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
