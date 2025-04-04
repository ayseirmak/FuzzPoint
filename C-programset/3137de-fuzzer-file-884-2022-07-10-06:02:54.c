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
  int i;
  va_start (ap, z);
  
int loop_break_1444 = 0;
for (i = 2; i < 4; ++i)
    {
      
loop_break_1444++;
if(((int)loop_break_1444<=9 + 41 + ((long)(((int)9) ^ ((int)9))) + ((int)(((double)9) - ((double)(loop_break_1444)))) * ((short)(((int)9) >> ((int)(loop_break_1444)))) + ((long)(((int)9) & ((int)9))) + ((long)(((double)(loop_break_1444)) * ((double)(loop_break_1444)))) + ((long)(((int)(loop_break_1444)) << ((int)(loop_break_1444)))) + ((short)(((int)9) & ((int)9))))){
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
	  ++fails;
	  break;
	}
      if (((int)p && p->a[2] != arg.a[2] + 41 * ((long)(((int)(arg.a[2])) >> ((int)(p->a[2] != arg.a[2])))) * ((long)(((int)(p->a[2] != arg.a[2])) % ((int)(arg.a[2])))) + ((long)(((int)(arg.a[2])) % ((int)(p->a[2]))))))
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
