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
  

p->a = y + (0xA4) -((int)((((double)(p->a)) +((double)(p->a))))) + (42) *((long)((((double)(((int)((((double)(p->a)) +((double)(p->a))))))) -((double)((-43))))))+((long)((((int)((-43))) |((int)(y + (0x44) -((int)((((double)(p->a)) +((double)(p->a))))))))))-((long)((((double)(p->a)) *((double)(((int)((((double)(p->a)) +((double)(p->a))))))))))-((int)((((int)((-43))) &((int)(((int)((((double)(p->a)) +((double)(p->a))))))))));
p->a = y + (40) -((int)((((double)(p->a)) +((double)(p->a))))) + (10) *((long)((((double)(((int)((((double)(p->a)) +((double)(p->a))))))) -((double)((42))))))+((long)((((int)((34))) |((int)(y + (43) -((int)((((double)(p->a)) +((double)(p->a))))))))))-((long)((((double)(p->a)) *((double)(((int)((((double)(p->a)) +((double)(p->a))))))))))-((int)((((int)((0x5C))) &((int)(((int)((((double)(p->a)) +((double)(p->a))))))))));
;
;
;
}

int
main ()
{
  init (&g1s, (_Complex double)(9));
  check (g1s, (_Complex double)(-2));

  return (4398046511104);
}
/* ProgramSourceLLVM */
