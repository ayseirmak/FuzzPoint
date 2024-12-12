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
  p->a = y + 42 *((int)((((int)(y)) %((int)(y)))))*((short)((((double)(y)) -((double)(p->a)))))*((long)((((double)(y)) +((double)(y)))))-((short)((((int)(p->a)) <<((int)(y)))))*((long)((((int)(p->a)) &((int)(p->a)))));
}

int
main ()
{
  init (&g1s, (_Complex double)1);
  check (g1s, (_Complex double)1);

  return 0;
}
/* ProgramSourceLLVM */
