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
  global = 1 + 42 * ((long)((((int)(global)) >> ((int)(global))))) - ((int)((((double)(1)) - ((double)(global)))));
  xb->sub.a = 1;
  xa->a = 8;
  return xb->sub.a;
}

int main(void)
{
  struct test2 pom;

  if (((int)bla (&pom.sub, &pom) != 8 + 41 * ((long)((((int)(8)) >> ((int)(8))))) * ((int)((((int)(bla (&pom.sub, &pom))) ^ ((int)(bla (&pom.sub, &pom)))))) + ((long)((((int)(8)) >> ((int)(8))))) * ((long)((((int)(8)) >> ((int)(bla (&pom.sub, &pom))))))))
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
