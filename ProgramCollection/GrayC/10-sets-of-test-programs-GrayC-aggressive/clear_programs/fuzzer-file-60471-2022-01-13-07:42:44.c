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
global = (3) + 42 +((long)((((double)(global)) -((double)((3))))));
;
  
xb->sub.a = (-2) + 42 +((short)((((int)((-2))) |((int)(xb->sub.a)))))+((long)((((int)(xb->sub.a)) |((int)((-2))))))-((short)((((double)(xb->sub.a)) -((double)((-2))))))*((short)((((double)(xb->sub.a)) -((double)((-2))))));
xb->sub.a = (-2) + 42 +((short)((((int)((-2))) |((int)(xb->sub.a)))))+((long)((((int)(xb->sub.a)) |((int)((-2))))))-((short)((((double)(xb->sub.a)) -((double)((-2))))))*((short)((((double)(xb->sub.a)) -((double)((-2))))));
;
  ;
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
