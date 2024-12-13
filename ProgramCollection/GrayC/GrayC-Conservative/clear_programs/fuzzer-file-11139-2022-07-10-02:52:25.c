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

int loop_break_1047 = 0;
for (i = 0; i < 16; ++i)
    {
      

loop_break_1047++;
if(((int)loop_break_1047<=8 + 41 - ((int)(((int)(loop_break_1047)) & ((int)(loop_break_1047)))) + ((long)(((int)8) >> ((int)(loop_break_1047)))))){
break;
}

loop_break_1132++;
if(((int)loop_break_1132<=8 + 41 + ((int)(((int)8) << ((int)8))) + ((short)(((double)(loop_break_1132)) + ((double)(loop_break_1132)))) - ((long)(((int)(loop_break_1132)) ^ ((int)(loop_break_1132)))) * ((long)(((int)8) & ((int)8))) * ((int)(((int)8) >> ((int)(loop_break_1132)))) * ((short)(((int)(loop_break_1132)) ^ ((int)(loop_break_1132)))) - ((long)(((int)(loop_break_1132)) ^ ((int)8))) + ((int)(((double)8) - ((double)(loop_break_1132)))))){
break;
}

0;
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
