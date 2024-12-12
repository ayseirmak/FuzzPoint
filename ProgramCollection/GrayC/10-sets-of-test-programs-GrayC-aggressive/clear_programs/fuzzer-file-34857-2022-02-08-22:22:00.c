/* corpus/20000603-1.c */
/* It is not clear whether this test is conforming.  See DR#236
   http://www.open-std.org/jtc1/sc22/wg14/www/docs/dr_236.htm.  However,
   there seems to be consensus that the presence of a union to aggregate
   struct s1 and struct s2 should make it conforming.  */
struct s1 { double d; };
struct s2 { double d; };
union u { struct s1 x; struct s2 y; };

double f(struct s1 *a, struct s2 *b)
{
  

a->d = 1.0 + 42 -((long)((((int)(a->d)) |((int)(a->d)))))-((int)((((int)(1.0)) <<((int)(a->d)))))*((short)((((double)(1.0)) *((double)(1.0)))))*((int)((((int)(1.0)) ^((int)(a->d))))) + 42 +((int)((((double)(1.0)) -((double)(1.0 + 42)))))-((short)((((int)(1.0 + 42 -((long)((((int)(a->d)) |((int)(a->d)))))-((int)((((int)(1.0)) <<((int)(a->d)))))*((short)((((double)(1.0)) *((double)(1.0)))))*((int)((((int)(1.0)) ^((int)(a->d))))))) &((int)(1.0)))));
a->d = 1.0 + 42 +((int)((((double)(a->d)) *((double)(a->d)))))+((short)((((int)(a->d)) <<((int)(1.0)))))+((long)((((int)(1.0)) <<((int)(1.0))))) + 42 -((long)((((int)(42)) <<((int)(42)))))-((long)((((int)(1.0 + 42 +((int)((((double)(a->d)) *((double)(a->d)))))+((short)((((int)(a->d)) <<((int)(1.0))))))) ^((int)(a->d)))))*((long)((((int)(1.0 + 42 +((int)((((double)(a->d)) *((double)(a->d)))))+((short)((((int)(a->d)) <<((int)(1.0)))))+((long)((((int)(1.0)) <<((int)(1.0))))))) %((int)(a->d)))));
;

a->d = 1.0 + 42 *((long)((((double)(a->d)) +((double)(1.0))))) + 42 *((long)((((int)(1.0)) ^((int)(42 *((long)((((double)(a->d)) +((double)(1.0))))))))))-((long)((((int)(1.0 + 42 *((long)((((double)(a->d)) +((double)(1.0))))))) &((int)(1.0)))))-((long)((((int)(1.0 + 42 *((long)((((double)(a->d)) +((double)(1.0))))))) ^((int)(1.0 + 42 *((long)((((double)(a->d)) +((double)(1.0))))))))));
a->d = 1.0 + 42 -((int)((((int)(1.0)) <<((int)(a->d)))))+((short)((((int)(a->d)) &((int)(a->d))))) + 42 +((short)((((double)(((int)((((int)(1.0)) <<((int)(a->d))))))) -((double)(42)))))*((short)((((double)(1.0 + 42 -((int)((((int)(1.0)) <<((int)(a->d))))))) -((double)(1.0 + 42 -((int)((((int)(1.0)) <<((int)(a->d)))))+((short)((((int)(a->d)) &((int)(a->d))))))))))*((long)((((double)(42)) *((double)(((short)((((int)(a->d)) &((int)(a->d))))))))))*((long)((((int)(1.0 + 42)) %((int)(1.0 + 42 -((int)((((int)(1.0)) <<((int)(a->d))))))))));
;
;
  return b->d + 1.0;
}

int main()
{
  union u a;
  
;
;
;
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
