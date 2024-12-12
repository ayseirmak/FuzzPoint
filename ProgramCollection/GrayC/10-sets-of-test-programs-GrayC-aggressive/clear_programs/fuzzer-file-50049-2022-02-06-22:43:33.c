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
  
p->a = y + 42 -((short)((((int)(p->a)) >>((int)(p->a)))))-((long)((((int)(y)) |((int)(p->a))))) + 42 -((int)((((int)(((long)((((int)(y)) |((int)(p->a))))))) &((int)(p->a)))))*((long)((((double)(y + 42 -((short)((((int)(p->a)) >>((int)(p->a))))))) -((double)(y + 42)))))+((int)((((double)(((short)((((int)(p->a)) >>((int)(p->a))))))) *((double)(y + 42)))))-((short)((((double)(((long)((((int)(y)) |((int)(p->a))))))) -((double)(p->a)))))+((short)((((double)(y + 42)) *((double)(p->a)))));
p->a = y + 42 -((short)((((double)(p->a)) +((double)(p->a)))))-((long)((((int)(p->a)) >>((int)(y)))))*((long)((((double)(y)) -((double)(y))))) + 42 *((long)((((double)(y + 42 -((short)((((double)(p->a)) +((double)(p->a))))))) *((double)(42)))))-((long)((((int)(((long)((((int)(p->a)) >>((int)(y)))))*((long)((((double)(y)) -((double)(y))))))) &((int)(y + 42 -((short)((((double)(p->a)) +((double)(p->a)))))-((long)((((int)(p->a)) >>((int)(y)))))*((long)((((double)(y)) -((double)(y))))))))));
;
}

int
main ()
{
  init (&g1s, (_Complex double)(1));
  check (g1s, (_Complex double)(1));

  return (0);
}
/* ProgramSourceLLVM */
