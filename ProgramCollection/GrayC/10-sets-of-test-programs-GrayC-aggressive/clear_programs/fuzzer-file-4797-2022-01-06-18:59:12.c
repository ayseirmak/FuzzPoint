/* corpus/pr42248.c */
typedef struct {
  _Complex double a;
  _Complex double b;
} Scf10;

Scf10 g1s;

void
check (Scf10 x, _Complex double y)
{
  if (((int)((int)x.a != y + 42 +((short)((((int)(y)) |((int)(x.a)))))*((short)((((double)(x.a)) -((double)(x.a)))))*((short)((((double)(y)) -((double)(y)))))) + 42 -((short)((((double)(y + 42)) +((double)(y + 42)))))*((int)((((double)(42)) +((double)((int)x.a)))))*((int)((((int)(((short)((((int)(y)) |((int)(x.a)))))*((short)((((double)(x.a)) -((double)(x.a)))))*((short)((((double)(y)) -((double)(y))))))) ^((int)(((short)((((int)(y)) |((int)(x.a)))))*((short)((((double)(x.a)) -((double)(x.a)))))*((short)((((double)(y)) -((double)(y))))))))))-((int)((((int)(y)) ^((int)(42))))))) __builtin_abort ();
}

void
init (Scf10 *p, _Complex double y)
{
  ;
}

int
main ()
{
  init (&g1s, (_Complex double)1);
  check (g1s, (_Complex double)1);

  return 0;
}
/* ProgramSourceLLVM */
