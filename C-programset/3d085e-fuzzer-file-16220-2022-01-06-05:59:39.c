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
  ;
}

int
main ()
{
  init (&g1s, (_Complex double)(-2));
  check (g1s, (_Complex double)(0x26DB));

  return (0);
}
/* ProgramSourceLLVM */
