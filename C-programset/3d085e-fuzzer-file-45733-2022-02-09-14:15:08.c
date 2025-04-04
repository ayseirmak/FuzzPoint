/* corpus/pr42248.c */
typedef struct {
  _Complex double a;
  _Complex double b;
} Scf10;

Scf10 g1s;

void
check (Scf10 x, _Complex double y)
{
  if (0) __builtin_abort ();
}

void
init (Scf10 *p, _Complex double y)
{
  p->a = y + (0xD70B) +((long)((((int)(p->a)) ^((int)(y)))))-((short)((((int)(p->a)) ^((int)(p->a)))));
}

int
main ()
{
  init (&g1s, (_Complex double)(-2));
  check (g1s, (_Complex double)(-2));

  return (0);
}
/* ProgramSourceLLVM */
