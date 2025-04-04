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
  for (i = 2 + 42 - ((int)(((double)(i)) * ((double)2))) * ((long)(((double)2) - ((double)2))); i < 4; ++i)
    {
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
      if (((int)((int)p && p->a[2] != arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2]))))) + 41 - ((int)(((int)(p->a[2] != arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2])))))) & ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2])))))))) + ((int)(((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))))) % ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))))))) - ((short)(((int)((int)(((int)(p->a[2])) & ((int)(arg.a[2]))))) >> ((int)((int)(((int)(arg.a[2])) & ((int)(p->a[2]))))))) + ((short)(((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))))) | ((int)((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2]))))))) + ((short)(((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))))) % ((int)((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2]))))))) + ((short)(((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))))) >> ((int)((int)(((int)(arg.a[2])) & ((int)(p->a[2]))))))) - ((int)(((int)((int)(((int)(arg.a[2])) & ((int)(p->a[2]))))) | ((int)((int)p)))) + ((int)(((int)(p->a[2])) ^ ((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2])))))))) - ((short)(((int)((int)(((int)(p->a[2])) & ((int)(arg.a[2]))))) % ((int)((int)(((int)(arg.a[2])) & ((int)(p->a[2]))))))) - ((int)(((int)(arg.a[2] + 41 + ((short)(((int)(arg.a[2])) << ((int)(p->a[2])))) + ((int)(((int)(p->a[2] != arg.a[2])) << ((int)(p->a[2])))) + ((long)(((int)(p->a[2] != arg.a[2])) & ((int)(p->a[2])))) - ((int)(((int)(p->a[2])) & ((int)(arg.a[2])))) - ((int)(((int)(arg.a[2])) & ((int)(p->a[2])))))) ^ ((int)((short)(((int)(arg.a[2])) << ((int)(p->a[2])))))))))
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
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
