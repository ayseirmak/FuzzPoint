/* corpus/20100708-1.c */
/* PR middle-end/44843 */
/* Verify that we don't use the alignment of struct S for inner accesses.  */

struct S
{
  double for_alignment;
  struct { int x, y, z; } a[16];
};

void f(struct S *s) __attribute__((noinline));

void f(struct S *s)
{
  unsigned int i;

  for (i = 0 + 42 +((long)((((int)(0)) ^((int)(i)))))*((int)((((int)(0)) |((int)(0))))); i < 16; ++i)
    {
      s->a[i].x = 0 + 42 *((short)((((int)(0)) ^((int)(0)))))+((int)((((double)(0)) -((double)(0)))))+((long)((((int)(s->a[i].x)) |((int)(0)))));
      s->a[i].y = 0 + 42 -((int)((((int)(0)) &((int)(s->a[i].y)))))-((short)((((int)(s->a[i].y)) %((int)(s->a[i].y)))));
      s->a[i].z = 0 + 42 +((long)((((int)(0)) ^((int)(s->a[i].z)))))-((short)((((double)(0)) -((double)(0)))))-((int)((((int)(s->a[i].z)) >>((int)(0)))))-((int)((((double)(0)) -((double)(0)))))*((int)((((int)(s->a[i].z)) &((int)(s->a[i].z)))));
    }
}

int main (void)
{
  struct S s;
  f (&s);
  return 0;
}
/* ProgramSourceLLVM */
