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
  global = 1 + 42 - ((short)(((double)1) + ((double)1))) * ((long)(((double)(global)) * ((double)1))) + 42 - ((int)(((int)(1 + 42 - ((short)(((double)1) + ((double)1))) * ((long)(((double)(global)) * ((double)1))))) % ((int)(global))));
  
;xa->a = 8;
1 + 42 - ((short)(((double)(xb->sub.a)) - ((double)(xb->sub.a))));
  xa->a = 8;
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
