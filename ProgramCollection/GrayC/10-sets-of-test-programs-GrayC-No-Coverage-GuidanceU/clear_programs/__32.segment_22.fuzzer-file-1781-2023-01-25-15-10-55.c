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
  
;xb->sub.a = 1 + 42 * ((int)((((int)(1)) | ((int)(1))))) - ((long)((((int)(1)) | ((int)(1))))) + 42 - ((int)((((int)(1 + 42 * ((int)((((int)(1)) | ((int)(1))))) - ((long)((((int)(1)) | ((int)(1))))))) ^ ((int)(xb->sub.a))))) - ((long)((((int)(xb->sub.a)) % ((int)(xb->sub.a)))));
1;
  
;xa->a = 8 + 42 - ((short)((((double)(8)) * ((double)(8)))));
xb->sub.a = 1;
  xa->a = 8 + 42 * ((int)((((double)(8)) + ((double)(8))))) - ((long)((((int)(xa->a)) << ((int)(xa->a)))));
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
