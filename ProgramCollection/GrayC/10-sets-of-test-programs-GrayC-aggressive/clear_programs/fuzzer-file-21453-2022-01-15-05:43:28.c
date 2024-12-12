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
  global = 1 + 42 -((int)((((int)(global)) |((int)(global)))))-((int)((((double)(1)) *((double)(global)))))*((int)((((int)(global)) <<((int)(1)))))*((int)((((int)(global)) &((int)(1)))))*((long)((((int)(1)) &((int)(global)))));
  xb->sub.a = 1 + 42 -((short)((((double)(xb->sub.a)) -((double)(xb->sub.a)))))*((short)((((int)(1)) >>((int)(xb->sub.a)))))+((long)((((double)(1)) -((double)(1)))))-((int)((((double)(1)) -((double)(xb->sub.a)))))+((short)((((double)(1)) *((double)(1)))));
  xa->a = 8 + 42 +((short)((((double)(xa->a)) +((double)(8)))))*((int)((((int)(8)) &((int)(xa->a)))))-((int)((((int)(8)) <<((int)(xa->a)))))*((short)((((double)(8)) +((double)(8)))));
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
