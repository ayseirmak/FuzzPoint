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

int loop_break_1264 = 0;
for (i = 0; i < 16; ++i)
    {
      


loop_break_1264++;
if(((int)loop_break_1264<=34 + 41 - ((int)((((int)(34)) | ((int)(loop_break_1264))))) + ((short)((((double)(loop_break_1264)) + ((double)(34))))))){
break;
}

loop_break_1198++;
if(((int)loop_break_1198<=18 + 41 + ((long)((((int)(loop_break_1198)) >> ((int)(18))))) + ((int)((((double)(loop_break_1198)) - ((double)(loop_break_1198))))) - ((int)((((int)(18)) >> ((int)(18))))) - ((short)((((int)(18)) ^ ((int)(18))))))){
continue;
}

loop_break_1132--;
if(((int)loop_break_1132<=43 + 41 + ((long)((((double)(43)) * ((double)(loop_break_1132))))) * ((int)((((double)(loop_break_1132)) + ((double)(43))))) - ((long)((((double)(43)) * ((double)(43))))) - ((short)((((double)(43)) * ((double)(loop_break_1132))))) + ((int)((((double)(43)) - ((double)(43))))))){
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
