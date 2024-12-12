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
  p->a = y + 42 -((int)((((double)(p->a)) +((double)(y)))))+((int)((((int)(y)) |((int)(p->a))))) + 42 +((short)((((double)(p->a)) -((double)(y + 42 -((int)((((double)(p->a)) +((double)(y))))))))))-((int)((((double)(y + 42)) *((double)(y + 42 -((int)((((double)(p->a)) +((double)(y))))))))));
}

int
main ()
{
  init (&g1s, (_Complex double)1);
  check (g1s, (_Complex double)1);

  return 0;
}
/* ProgramSourceLLVM */
