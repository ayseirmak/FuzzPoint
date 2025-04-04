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

  
int loop_break_1132 = 0;

int loop_break_3713 = 0;
for (i = 0 + 42 -((int)((((int)(0)) >>((int)(0)))))*((short)((((int)(i)) |((int)(i))))); i < 16; ++i)
    {
      

loop_break_3713++;
if(0){
break;
}

loop_break_1132++;
if(0){
break;
}

s->a[i].x = 0 + 42 *((short)((((int)(s->a[i].x)) %((int)(s->a[i].x)))));
      s->a[i].y = 0 + 42 +((short)((((int)(s->a[i].y)) >>((int)(s->a[i].y)))))*((long)((((int)(0)) %((int)(s->a[i].y)))))+((int)((((int)(0)) >>((int)(s->a[i].y)))))*((short)((((int)(0)) &((int)(0)))))-((long)((((double)(0)) *((double)(0)))));
      s->a[i].z = 0 + 42 +((long)((((int)(s->a[i].z)) <<((int)(s->a[i].z)))))*((int)((((int)(0)) ^((int)(s->a[i].z)))));
    }
}

int main (void)
{
  struct S s;
  f (&s);
  return 0;
}
/* ProgramSourceLLVM */
