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
  global = (3) + 42 *((int)((((int)(global)) |((int)(global)))))-((short)((((int)((3))) |((int)(global)))))-((short)((((int)(global)) &((int)((3)))))) + 42 -((short)((((int)((3) + 42 *((int)((((int)(global)) |((int)(global)))))-((short)((((int)((3))) |((int)(global)))))-((short)((((int)(global)) &((int)((3)))))))) |((int)(42)))))-((short)((((double)(((short)((((int)((3))) |((int)(global))))))) -((double)(global)))))+((int)((((int)(((short)((((int)(global)) &((int)((3)))))))) ^((int)(42)))))*((short)((((int)(42 *((int)((((int)(global)) |((int)(global))))))) %((int)((3) + 42 *((int)((((int)(global)) |((int)(global))))))))))-((int)((((int)(global)) |((int)((3) + 42 *((int)((((int)(global)) |((int)(global))))))))));
  xb->sub.a = (-2) + 42 *((int)((((int)((-2))) ^((int)((-2))))))*((long)((((int)((-2))) %((int)(xb->sub.a)))))-((int)((((int)(xb->sub.a)) &((int)(xb->sub.a))))) + 42 -((int)((((int)((-2) + 42 *((int)((((int)((-2))) ^((int)((-2))))))*((long)((((int)((-2))) %((int)(xb->sub.a)))))-((int)((((int)(xb->sub.a)) &((int)(xb->sub.a))))))) <<((int)((-2) + 42 *((int)((((int)((-2))) ^((int)((-2))))))*((long)((((int)((-2))) %((int)(xb->sub.a)))))-((int)((((int)(xb->sub.a)) &((int)(xb->sub.a))))))))))-((int)((((double)(xb->sub.a)) +((double)(xb->sub.a)))))-((int)((((int)((-2) + 42 *((int)((((int)((-2))) ^((int)((-2))))))*((long)((((int)((-2))) %((int)(xb->sub.a)))))-((int)((((int)(xb->sub.a)) &((int)(xb->sub.a))))))) %((int)((-2) + 42 *((int)((((int)((-2))) ^((int)((-2))))))*((long)((((int)((-2))) %((int)(xb->sub.a)))))-((int)((((int)(xb->sub.a)) &((int)(xb->sub.a))))))))));
  xa->a = (40) + 42 -((long)((((double)((40))) *((double)(xa->a))))) + 42 *((int)((((int)((40) + 42 -((long)((((double)((40))) *((double)(xa->a))))))) >>((int)(xa->a)))));
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
