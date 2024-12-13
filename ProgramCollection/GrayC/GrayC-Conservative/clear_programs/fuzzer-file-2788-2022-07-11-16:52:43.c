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
  1;
  8 + 42 - ((short)(((double)8) + ((double)8))) - ((int)(((int)8) % ((int)8))) * ((int)(((double)(xa->a)) - ((double)8))) - ((int)(((double)8) + ((double)(xa->a)))) + ((int)(((int)(xa->a)) << ((int)(xa->a))));
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
