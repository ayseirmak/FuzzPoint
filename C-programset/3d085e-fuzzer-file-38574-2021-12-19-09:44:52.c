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
  p->a = y + (-43) +((short)((((double)(p->a)) +((double)(p->a)))))*((short)((((int)(p->a)) <<((int)(p->a)))))*((short)((((double)(p->a)) +((double)(p->a))))) + 42 -((int)((((int)(y + (-43))) >>((int)(y))))) + 42 +((short)((((double)(y + (-43))) -((double)(y)))))+((int)((((int)(y + (-43) +((short)((((double)(p->a)) +((double)(p->a)))))*((short)((((int)(p->a)) <<((int)(p->a)))))*((short)((((double)(p->a)) +((double)(p->a))))))) &((int)(y + (-43) +((short)((((double)(p->a)) +((double)(p->a)))))*((short)((((int)(p->a)) <<((int)(p->a)))))*((short)((((double)(p->a)) +((double)(p->a))))) + 42)))))*((short)((((int)(y + (-43) +((short)((((double)(p->a)) +((double)(p->a)))))*((short)((((int)(p->a)) <<((int)(p->a)))))*((short)((((double)(p->a)) +((double)(p->a))))) + 42 -((int)((((int)(y + (-43))) >>((int)(y))))))) &((int)(42)))))+((short)((((int)(((int)((((int)(y + (-43))) >>((int)(y))))))) >>((int)(y + (-43) +((short)((((double)(p->a)) +((double)(p->a)))))*((short)((((int)(p->a)) <<((int)(p->a)))))*((short)((((double)(p->a)) +((double)(p->a))))) + 42 -((int)((((int)(y + (-43))) >>((int)(y))))))))))-((int)((((int)(p->a)) ^((int)(((short)((((double)(p->a)) +((double)(p->a)))))*((short)((((int)(p->a)) <<((int)(p->a)))))*((short)((((double)(p->a)) +((double)(p->a)))))))))) + 42 -((int)((((double)(((short)((((double)(y + (-43))) -((double)(y))))))) -((double)((-43))))))+((short)((((int)(((short)((((int)(((int)((((int)(y + (-43))) >>((int)(y))))))) >>((int)(y + (-43) +((short)((((double)(p->a)) +((double)(p->a)))))*((short)((((int)(p->a)) <<((int)(p->a)))))*((short)((((double)(p->a)) +((double)(p->a))))) + 42 -((int)((((int)(y + (-43))) >>((int)(y)))))))))))) %((int)(y + (-43) +((short)((((double)(p->a)) +((double)(p->a)))))*((short)((((int)(p->a)) <<((int)(p->a)))))*((short)((((double)(p->a)) +((double)(p->a))))) + 42 -((int)((((int)(y + (-43))) >>((int)(y))))))))))*((int)((((int)(y + (-43))) >>((int)(y + (-43) +((short)((((double)(p->a)) +((double)(p->a)))))*((short)((((int)(p->a)) <<((int)(p->a)))))*((short)((((double)(p->a)) +((double)(p->a))))) + 42)))));
}

int
main ()
{
  init (&g1s, (_Complex double)(1));
  check (g1s, (_Complex double)(9));

  return (0);
}
/* ProgramSourceLLVM */
