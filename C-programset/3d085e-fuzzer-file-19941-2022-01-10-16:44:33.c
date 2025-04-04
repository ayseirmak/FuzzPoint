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
  p->a = y + 42 +((long)((((int)(p->a)) %((int)(y)))))+((long)((((double)(y)) -((double)(y)))))*((int)((((int)(y)) |((int)(p->a)))))*((short)((((double)(p->a)) -((double)(p->a))))) + 42 *((short)((((int)(y + 42 +((long)((((int)(p->a)) %((int)(y)))))+((long)((((double)(y)) -((double)(y)))))*((int)((((int)(y)) |((int)(p->a)))))*((short)((((double)(p->a)) -((double)(p->a))))))) ^((int)(y + 42 +((long)((((int)(p->a)) %((int)(y)))))+((long)((((double)(y)) -((double)(y)))))*((int)((((int)(y)) |((int)(p->a)))))*((short)((((double)(p->a)) -((double)(p->a))))))))))-((int)((((double)(p->a)) +((double)(p->a)))))+((short)((((int)(y + 42 +((long)((((int)(p->a)) %((int)(y)))))+((long)((((double)(y)) -((double)(y)))))*((int)((((int)(y)) |((int)(p->a)))))*((short)((((double)(p->a)) -((double)(p->a))))))) ^((int)(p->a))))) + 42 -((short)((((int)(((short)((((int)(y + 42 +((long)((((int)(p->a)) %((int)(y)))))+((long)((((double)(y)) -((double)(y)))))*((int)((((int)(y)) |((int)(p->a)))))*((short)((((double)(p->a)) -((double)(p->a))))))) ^((int)(p->a))))))) >>((int)(42 *((short)((((int)(y + 42 +((long)((((int)(p->a)) %((int)(y)))))+((long)((((double)(y)) -((double)(y)))))*((int)((((int)(y)) |((int)(p->a)))))*((short)((((double)(p->a)) -((double)(p->a))))))) ^((int)(y + 42 +((long)((((int)(p->a)) %((int)(y)))))+((long)((((double)(y)) -((double)(y)))))*((int)((((int)(y)) |((int)(p->a)))))*((short)((((double)(p->a)) -((double)(p->a)))))))))))))));
}

int
main ()
{
  init (&g1s, (_Complex double)1);
  check (g1s, (_Complex double)1);

  return 0;
}
/* ProgramSourceLLVM */
