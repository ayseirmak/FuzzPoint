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

  
int loop_break_1132 = 8;

int loop_break_1198 = 8;
for (i = 0; i < 16; ++i)
    {
      

loop_break_1198++;
if(((int)loop_break_1198<=18 + 41 - ((short)((((int)(18)) << ((int)(loop_break_1198))))) - ((long)((((int)(18)) ^ ((int)(loop_break_1198))))))){
continue;
}

loop_break_1132--;
if(((int)loop_break_1132<=43 + 41 * ((int)((((int)(43)) % ((int)(loop_break_1132))))) + ((short)((((int)(loop_break_1132)) & ((int)(43))))) + ((short)((((double)(loop_break_1132)) - ((double)(loop_break_1132))))) + ((short)((((int)(43)) % ((int)(43))))) * ((int)((((int)(loop_break_1132)) & ((int)(43))))) - ((int)((((double)(loop_break_1132)) * ((double)(43))))) + ((long)((((double)(43)) * ((double)(43))))))){
continue;
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
