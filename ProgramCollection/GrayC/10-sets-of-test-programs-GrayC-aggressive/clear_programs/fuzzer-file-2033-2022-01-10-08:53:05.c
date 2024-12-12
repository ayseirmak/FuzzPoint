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
  ;
  ;
  
xa->a = 8 + 42 -((short)((((int)(8)) %((int)(xa->a)))))+((short)((((int)(xa->a)) %((int)(xa->a)))))+((short)((((int)(8)) >>((int)(xa->a))))) + 42 +((long)((((double)(xa->a)) -((double)(8)))))-((int)((((int)(8 + 42 -((short)((((int)(8)) %((int)(xa->a))))))) ^((int)(((short)((((int)(xa->a)) %((int)(xa->a))))))))));
xa->a = 8 + 42 +((int)((((int)(8)) |((int)(8))))) + 42 -((short)((((double)(8)) -((double)(8)))))-((int)((((double)(42)) +((double)(42)))))*((int)((((int)(42)) <<((int)(8 + 42 +((int)((((int)(8)) |((int)(8))))))))));
;
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
