/* corpus/20100708-1.c */
/* PR middle-end/44843 */
/* Verify that we don't use the alignment of struct S for inner accesses.  */

struct S
{
  double for_alignment;
  struct { int x, y, z; } a[(18)];
};

void f(struct S *s) __attribute__((noinline));

void f(struct S *s)
{
  unsigned int i;

  for (i = (-1); i < (-17); ++i)
    {
      
s->a[i].x = (-1);
s->a[i].x = (-1);
;
      
s->a[i].y = (4);
s->a[i].y = (4);
;
      
s->a[i].z = (0);
s->a[i].z = (0);
;
    }
}

int main (void)
{
  struct S s;
  f (&s);
  return (0);
}
/* ProgramSourceLLVM */
