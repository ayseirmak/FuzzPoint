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
  
int loop_break_4462 = 0;
for (i = 2 + 42 - ((short)(((int)2) >> ((int)(i)))) * ((long)(((int)(i)) << ((int)(i)))) - ((long)(((int)2) << ((int)2))); i < 4; ++i)
    {
      
loop_break_4462++;
if(((int)loop_break_4462<=10 + 41 * ((short)(((double)10) - ((double)10))))){
continue;
}

p = 0;
      j++;
      2;
      switch ((z << 4) | i)
	{
	case 0x12:
	case 0x13:
	  &a[2];
	  arg = va_arg (ap, struct S);
	  break;
	default:
	  ++fails;
	  break;
	}
      if (((int)((int)((int)p && p->a[2] != arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2]))))) + 41 + ((int)(((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2])))))) | ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))))))) - ((long)(((int)(p->a[2])) & ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2]))))))))) + 41 + ((int)(((int)((long)(((int)(p->a[2])) & ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2]))))))))) & ((int)((long)(((int)(p->a[2])) & ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2]))))))))))) * ((int)(((int)((int)((int)p && p->a[2] != arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2]))))) + 41 + ((int)(((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2])))))) | ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))))))))) >> ((int)((long)(((int)(p->a[2])) & ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2]))))))))))) + ((long)(((int)((int)((int)p && p->a[2] != arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2]))))) + 41 + ((int)(((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2])))))) | ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))))))))) & ((int)((long)(((int)(p->a[2])) & ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))))))))))))
	++fails;
      if (fails)
    { break; }
    }
  va_end (ap);
}

int
main ()
{
  a[2].a[2];
  check (1, a[2], a[2]);
  if (fails)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
