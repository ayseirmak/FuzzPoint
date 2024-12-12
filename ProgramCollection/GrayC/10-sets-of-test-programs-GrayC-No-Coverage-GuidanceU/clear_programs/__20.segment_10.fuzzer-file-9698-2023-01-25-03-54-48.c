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
for (i = 0; i < 16; ++i)
    {
      
loop_break_1132++;
if(loop_break_1132<=34){
break;
}

s->a[i].x = 0;
      s->a[i].y = 0;
      s->a[i].z = 0;
    }
}

int main (void)
{
  struct S s;
  f (&s);
  return 0;
}
/* ProgramSourceLLVM */
