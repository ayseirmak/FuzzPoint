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
  p->a = y + (-((0xBB))) -((int)((((double)(p->a)) +((double)(p->a))))) + 42 +((long)((((int)(y)) >>((int)(p->a)))))*((int)((((double)(y + (-((0xBB))) -((int)((((double)(p->a)) +((double)(p->a))))))) -((double)(y + (-((0xBB))))))))+((short)((((double)(((int)((((double)(p->a)) +((double)(p->a))))))) +((double)((-((0xBB))))))));
}

int
main ()
{
  init (&g1s, (_Complex double)((-(18))));
  check (g1s, (_Complex double)(-(0x3F)));

  return (((0)));
}
/* ProgramSourceLLVM */
