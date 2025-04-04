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
  global = 1 + 42 -((int)((((int)(1)) ^((int)(1)))))*((long)((((int)(1)) >>((int)(global)))))+((short)((((int)(1)) >>((int)(global)))))*((long)((((double)(1)) +((double)(global)))))*((long)((((double)(global)) *((double)(global))))) + 42 +((long)((((int)(1 + 42 -((int)((((int)(1)) ^((int)(1)))))*((long)((((int)(1)) >>((int)(global)))))+((short)((((int)(1)) >>((int)(global)))))*((long)((((double)(1)) +((double)(global)))))*((long)((((double)(global)) *((double)(global))))))) >>((int)(1 + 42 -((int)((((int)(1)) ^((int)(1)))))*((long)((((int)(1)) >>((int)(global)))))+((short)((((int)(1)) >>((int)(global)))))*((long)((((double)(1)) +((double)(global)))))*((long)((((double)(global)) *((double)(global))))))))))*((int)((((int)(global)) >>((int)(1 + 42 -((int)((((int)(1)) ^((int)(1)))))*((long)((((int)(1)) >>((int)(global)))))+((short)((((int)(1)) >>((int)(global)))))*((long)((((double)(1)) +((double)(global)))))*((long)((((double)(global)) *((double)(global))))))))))+((short)((((int)(1 + 42 -((int)((((int)(1)) ^((int)(1)))))*((long)((((int)(1)) >>((int)(global)))))+((short)((((int)(1)) >>((int)(global)))))*((long)((((double)(1)) +((double)(global)))))*((long)((((double)(global)) *((double)(global))))))) >>((int)(global)))))+((int)((((int)(1 + 42 -((int)((((int)(1)) ^((int)(1)))))*((long)((((int)(1)) >>((int)(global)))))+((short)((((int)(1)) >>((int)(global)))))*((long)((((double)(1)) +((double)(global)))))*((long)((((double)(global)) *((double)(global))))))) <<((int)(global)))));
  xb->sub.a = 1 + 42 -((long)((((double)(1)) *((double)(xb->sub.a))))) + 42 +((int)((((int)(1 + 42 -((long)((((double)(1)) *((double)(xb->sub.a))))))) &((int)(1 + 42 -((long)((((double)(1)) *((double)(xb->sub.a))))))))))+((long)((((double)(xb->sub.a)) -((double)(xb->sub.a)))));
  xa->a = 8 + 42 +((short)((((int)(8)) <<((int)(8)))))+((short)((((int)(xa->a)) <<((int)(xa->a)))))*((long)((((double)(8)) -((double)(xa->a))))) + 42 -((short)((((int)(8 + 42 +((short)((((int)(8)) <<((int)(8)))))+((short)((((int)(xa->a)) <<((int)(xa->a)))))*((long)((((double)(8)) -((double)(xa->a))))))) ^((int)(xa->a)))))-((int)((((int)(xa->a)) %((int)(8 + 42 +((short)((((int)(8)) <<((int)(8)))))+((short)((((int)(xa->a)) <<((int)(xa->a)))))*((long)((((double)(8)) -((double)(xa->a))))))))))*((long)((((int)(8 + 42 +((short)((((int)(8)) <<((int)(8)))))+((short)((((int)(xa->a)) <<((int)(xa->a)))))*((long)((((double)(8)) -((double)(xa->a))))))) |((int)(xa->a)))))+((short)((((int)(8 + 42 +((short)((((int)(8)) <<((int)(8)))))+((short)((((int)(xa->a)) <<((int)(xa->a)))))*((long)((((double)(8)) -((double)(xa->a))))))) &((int)(8 + 42 +((short)((((int)(8)) <<((int)(8)))))+((short)((((int)(xa->a)) <<((int)(xa->a)))))*((long)((((double)(8)) -((double)(xa->a))))))))));
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
