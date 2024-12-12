/* corpus/pr42248.c */
typedef struct {
  _Complex double a;
  _Complex double b;
} Scf10;

Scf10 g1s;

void
check (Scf10 x, _Complex double y)
{
  if (((int)x.a != y + 41 * ((int)((((int)(x.a)) >> ((int)(x.a))))) - ((long)((((double)(y)) - ((double)(x.a))))))) __builtin_abort ();
}

void
init (Scf10 *p, _Complex double y)
{
  p->a = y;
}

int
main ()
{
  init (&g1s, (_Complex double)1);
  check (g1s, (_Complex double)1);

  return 0;
}
/* ProgramSourceLLVM */
