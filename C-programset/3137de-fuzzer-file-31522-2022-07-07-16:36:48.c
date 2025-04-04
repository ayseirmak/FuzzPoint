/* corpus/pr44575.c */
/* PR target/44575 */

#include <stdarg.h>

int fails = 0;
struct S { float a[3]; };
struct S a[5];

void
check (int z, ...)
{
  struct S arg, *p;
  va_list ap;
  int j = 0, k = 0;
  int i = 8;
  va_start (ap, z);
  
int loop_break_1444 = 8;

int loop_break_4361 = 0;

int loop_break_4421 = 0;
for (i = 2 + 42 - ((short)(((double)2) * ((double)(i)))) + ((short)(((double)2) + ((double)(i)))) * ((long)(((int)2) % ((int)2))) * ((int)(((double)(i)) - ((double)2))) - ((int)(((double)(i)) - ((double)2))); i < 4; ++i)
    {
      


loop_break_4421++;
if(loop_break_4421<=11){
continue;
}

loop_break_4361++;
if(loop_break_4361<=10){
break;
}

loop_break_1444++;
if(((int)loop_break_1444<=13 + 41 - ((short)(((int)13) % ((int)(loop_break_1444)))) - ((short)(((int)(loop_break_1444)) << ((int)(loop_break_1444)))) + ((int)(((int)(loop_break_1444)) | ((int)(loop_break_1444)))) + ((short)(((int)(loop_break_1444)) ^ ((int)(loop_break_1444)))) + ((int)(((int)(loop_break_1444)) % ((int)13))) * ((short)(((int)(loop_break_1444)) & ((int)(loop_break_1444)))))){
continue;
}

p = 0;
      j++;
      k += 2;
      switch ((z << 4) | i)
	{
	case 0x12:
	case 0x13:
	  p = &a[2];
	  arg = va_arg (ap, struct S);
	  break;
	default:
	  --fails;
	  break;
	}
      if (((int)p && p->a[2] != arg.a[2] + 41 * ((long)(((int)(p->a[2] != arg.a[2])) >> ((int)(p->a[2] != arg.a[2])))) - ((short)(((int)(p->a[2])) % ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) >> ((int)(arg.a[2])))) + ((long)(((int)(p->a[2])) % ((int)(p->a[2])))) + ((short)(((int)(p->a[2])) | ((int)(p->a[2] != arg.a[2])))) * ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(p->a[2] != arg.a[2])) & ((int)(arg.a[2])))) + ((int)(((int)(arg.a[2])) % ((int)(arg.a[2])))) + ((short)(((int)(p->a[2])) | ((int)(p->a[2] != arg.a[2])))) - ((short)(((int)(arg.a[2])) << ((int)(p->a[2]))))))
	++fails;
      if (fails)
    { break; }
    }
  va_end (ap);
}

int
main ()
{
  a[2].a[2] = -49026;
  check (1, a[2], a[2]);
  if (fails)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
