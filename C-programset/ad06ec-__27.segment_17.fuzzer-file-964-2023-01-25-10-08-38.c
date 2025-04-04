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
  xb->sub.a = 1 + 42 * ((long)((((int)(xb->sub.a)) | ((int)(1)))));
  xa->a = 8 + 42 - ((long)((((double)(xa->a)) * ((double)(8))))) * ((long)((((int)(xa->a)) % ((int)(8))))) * ((short)((((double)(8)) + ((double)(xa->a)))));
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
