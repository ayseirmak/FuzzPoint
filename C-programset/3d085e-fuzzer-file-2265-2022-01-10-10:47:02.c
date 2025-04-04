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
  p->a = y + (-43) -((short)((((int)(y)) ^((int)(y)))))-((short)((((int)(y)) <<((int)(p->a)))))+((long)((((int)(p->a)) &((int)(p->a)))))*((int)((((double)(p->a)) -((double)(p->a)))));
}

int
main ()
{
  init (&g1s, (_Complex double)(129));
  check (g1s, (_Complex double)(0x2));

  return (281474976710656);
}
/* ProgramSourceLLVM */
