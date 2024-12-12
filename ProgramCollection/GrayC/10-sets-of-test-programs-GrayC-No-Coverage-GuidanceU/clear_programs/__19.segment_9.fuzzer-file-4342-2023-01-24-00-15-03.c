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
  1;
  
;xa->a = 8;
1;
  xa->a = 8;
  return xb->sub.a;
}

int main(void)
{
  struct test2 pom;

  if (bla (&pom.sub, &pom) != 8)
    { abort (); }

  return 0;
}
/* ProgramSourceLLVM */
