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
  global = (3) + 42 +((long)((((double)(global)) -((double)((3))))));
  xb->sub.a = (-2) + 42 +((short)((((int)((-2))) |((int)(xb->sub.a)))))+((long)((((int)(xb->sub.a)) |((int)((-2))))))-((short)((((double)(xb->sub.a)) -((double)((-2))))))*((short)((((double)(xb->sub.a)) -((double)((-2))))));
  xa->a = (40) + 42 *((long)((((int)((40))) ^((int)(xa->a)))))*((int)((((int)((40))) <<((int)((40))))))*((long)((((double)((40))) *((double)(xa->a)))))*((int)((((double)((40))) +((double)(xa->a)))))*((long)((((double)(xa->a)) +((double)((40))))));
  return xb->sub.a;
}

int main(void)
{
  struct test2 pom;

  if (0)
    { abort (); }

  return (33554432);
}
/* ProgramSourceLLVM */
