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
  xb->sub.a = 1 + 42 + ((long)(((double)1) + ((double)1))) + ((short)(((int)1) >> ((int)(xb->sub.a)))) * ((int)(((double)(xb->sub.a)) + ((double)(xb->sub.a)))) + ((long)(((int)(xb->sub.a)) & ((int)1))) - ((int)(((double)1) + ((double)(xb->sub.a))));
  xa->a = 8 + 42 + ((short)(((int)(xa->a)) << ((int)8))) + ((long)(((int)8) & ((int)8))) + 42 + ((short)(((int)(8 + 42 + ((short)(((int)(xa->a)) << ((int)8))) + ((long)(((int)8) & ((int)8))))) >> ((int)(8 + 42 + ((short)(((int)(xa->a)) << ((int)8))) + ((long)(((int)8) & ((int)8))))))) + ((short)(((int)(8 + 42 + ((short)(((int)(xa->a)) << ((int)8))) + ((long)(((int)8) & ((int)8))))) % ((int)(xa->a)))) - ((short)(((double)(8 + 42 + ((short)(((int)(xa->a)) << ((int)8))) + ((long)(((int)8) & ((int)8))))) + ((double)(xa->a)))) * ((int)(((int)(8 + 42 + ((short)(((int)(xa->a)) << ((int)8))) + ((long)(((int)8) & ((int)8))))) ^ ((int)(8 + 42 + ((short)(((int)(xa->a)) << ((int)8))) + ((long)(((int)8) & ((int)8))))))) * ((short)(((int)(xa->a)) >> ((int)(8 + 42 + ((short)(((int)(xa->a)) << ((int)8))) + ((long)(((int)8) & ((int)8)))))));
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
