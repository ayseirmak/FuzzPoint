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
  global = 1 + 42 -((int)((((double)(global)) +((double)(1)))))+((int)((((double)(1)) *((double)(1)))));
  xb->sub.a = 1 + 42 +((long)((((double)(xb->sub.a)) *((double)(xb->sub.a)))))*((int)((((int)(1)) ^((int)(xb->sub.a)))))+((long)((((int)(1)) ^((int)(xb->sub.a)))))-((short)((((double)(xb->sub.a)) -((double)(1)))));
  xa->a = 8 + 42 +((long)((((int)(xa->a)) &((int)(xa->a)))))-((long)((((int)(xa->a)) &((int)(8)))))+((int)((((int)(xa->a)) ^((int)(xa->a)))))-((int)((((double)(8)) +((double)(8)))));
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
