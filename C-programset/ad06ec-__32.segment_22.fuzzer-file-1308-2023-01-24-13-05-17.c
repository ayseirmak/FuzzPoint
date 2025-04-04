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

  
int loop_break_1040 = 0;

int loop_break_1106 = 0;
for (i = 0; i < 16; ++i)
    {
      

loop_break_1106++;
if(loop_break_1106<=25){
continue;
}

loop_break_1040++;
if(loop_break_1040<=19){
continue;
}

s->a[i].x = 0;
      0;
      0;
    }
}

int main (void)
{
  struct S s;
  f (&s);
  return 0;
}
/* ProgramSourceLLVM */
