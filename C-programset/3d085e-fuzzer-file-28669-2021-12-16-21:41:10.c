/* corpus/20100708-1.c */
/* PR middle-end/44843 */
/* Verify that we don't use the alignment of struct S for inner accesses.  */

struct S
{
  double for_alignment;
  struct { int x, y, z; } a[(76)];
};

void f(struct S *s) __attribute__((noinline));

void f(struct S *s)
{
  unsigned int i;

  
int loop_break_1164 = 0;
for (i = (0x2CC2); i < (0x3AB08); ++i)
    {
      
loop_break_1164++;
if(loop_break_1164<=5){
break;
}

s->a[i].x = (0);
      s->a[i].y = (0x3D9CF);
      s->a[i].z = (0);
    }
}

int main (void)
{
  struct S s;
  f (&s);
  return (134217728);
}
/* ProgramSourceLLVM */
