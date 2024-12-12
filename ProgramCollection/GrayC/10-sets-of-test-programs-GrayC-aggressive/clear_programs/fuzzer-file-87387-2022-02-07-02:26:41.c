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
  
p->a = y + (10) -((short)((((int)(p->a)) >>((int)(p->a)))))-((long)((((int)(y)) |((int)(p->a))))) + 42 +((int)((((double)(y + (10) -((short)((((int)(p->a)) >>((int)(p->a))))))) *((double)(y + (10))))))-((long)((((double)(y + (10) -((short)((((int)(p->a)) >>((int)(p->a)))))-((long)((((int)(y)) |((int)(p->a))))))) *((double)(((long)((((int)(y)) |((int)(p->a))))))))))+((long)((((int)(y + (10) -((short)((((int)(p->a)) >>((int)(p->a)))))-((long)((((int)(y)) |((int)(p->a))))))) ^((int)((10))))))-((long)((((double)(y + (10) -((short)((((int)(p->a)) >>((int)(p->a)))))-((long)((((int)(y)) |((int)(p->a))))))) -((double)(y)))));
p->a = y + (-43) -((short)((((double)(p->a)) +((double)(p->a)))))-((long)((((int)(p->a)) >>((int)(y)))))*((long)((((double)(y)) -((double)(y))))) + 42 -((int)((((int)(y + (-43) -((short)((((double)(p->a)) +((double)(p->a))))))) |((int)(p->a)))));
;
}

int
main ()
{
  init (&g1s, (_Complex double)((0)));
  check (g1s, (_Complex double)((17)));

  return ((0));
}
/* ProgramSourceLLVM */
