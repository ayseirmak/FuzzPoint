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
  

p->a = y + 42 -((int)((((double)(p->a)) +((double)(p->a))))) + 42 *((long)((((double)(((int)((((double)(p->a)) +((double)(p->a))))))) -((double)(42)))))+((long)((((int)(42)) |((int)(y + 42 -((int)((((double)(p->a)) +((double)(p->a))))))))))-((long)((((double)(p->a)) *((double)(((int)((((double)(p->a)) +((double)(p->a))))))))))-((int)((((int)(42)) &((int)(((int)((((double)(p->a)) +((double)(p->a))))))))));
p->a = y + 42 -((int)((((double)(p->a)) +((double)(p->a))))) + 42 *((long)((((double)(((int)((((double)(p->a)) +((double)(p->a))))))) -((double)(42)))))+((long)((((int)(42)) |((int)(y + 42 -((int)((((double)(p->a)) +((double)(p->a))))))))))-((long)((((double)(p->a)) *((double)(((int)((((double)(p->a)) +((double)(p->a))))))))))-((int)((((int)(42)) &((int)(((int)((((double)(p->a)) +((double)(p->a))))))))));
;
;
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
