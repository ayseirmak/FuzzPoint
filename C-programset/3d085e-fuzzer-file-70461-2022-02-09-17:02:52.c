/* corpus/pr42248.c */
typedef struct {
  _Complex double a;
  _Complex double b;
} Scf10;

Scf10 g1s;

void
check (Scf10 x, _Complex double y)
{
  if ((0)) __builtin_abort ();
}

void
init (Scf10 *p, _Complex double y)
{
  p->a = y + (42) -((short)((((double)(p->a)) -((double)(p->a))))) + 42 -((int)((((int)(p->a)) |((int)(y)))))*((int)((((int)(((short)((((double)(p->a)) -((double)(p->a))))))) >>((int)(((short)((((double)(p->a)) -((double)(p->a))))))))))-((int)((((int)(y + (42) -((short)((((double)(p->a)) -((double)(p->a))))))) %((int)(y + (42) -((short)((((double)(p->a)) -((double)(p->a))))))))))-((short)((((double)(y + (42))) *((double)(p->a)))));
}

int
main ()
{
  init (&g1s, (_Complex double)(1));
  check (g1s, (_Complex double)(0x3AA5));

  return (0);
}
/* ProgramSourceLLVM */
