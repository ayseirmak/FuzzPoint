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
  
a->d = (2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))-((int)((((int)(a->d)) %((int)(a->d)))))+((int)((((int)(a->d)) |((int)(a->d))))) + 42 +((long)((((int)(((int)((((int)(a->d)) |((int)(a->d))))))) |((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))))))) + 42 *((int)((((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))-((int)((((int)(a->d)) %((int)(a->d)))))+((int)((((int)(a->d)) |((int)(a->d))))) + 42 +((long)((((int)(((int)((((int)(a->d)) |((int)(a->d))))))) |((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))))))))) |((int)(((int)((((int)(a->d)) %((int)(a->d))))))))))-((int)((((int)(((int)((((int)(a->d)) %((int)(a->d))))))) %((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))-((int)((((int)(a->d)) %((int)(a->d)))))+((int)((((int)(a->d)) |((int)(a->d))))) + 42)))))+((short)((((int)(a->d)) %((int)(((long)((((int)(((int)((((int)(a->d)) |((int)(a->d))))))) |((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))))))))))))*((short)((((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))-((int)((((int)(a->d)) %((int)(a->d)))))+((int)((((int)(a->d)) |((int)(a->d))))) + 42 +((long)((((int)(((int)((((int)(a->d)) |((int)(a->d))))))) |((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))))))))) %((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1)))))))))));
a->d = (2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))-((int)((((int)(a->d)) %((int)(a->d)))))+((int)((((int)(a->d)) |((int)(a->d))))) + 42 +((long)((((int)(((int)((((int)(a->d)) |((int)(a->d))))))) |((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))))))) + 42 *((short)((((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))-((int)((((int)(a->d)) %((int)(a->d)))))+((int)((((int)(a->d)) |((int)(a->d))))) + 42)) >>((int)(((long)((((int)(((int)((((int)(a->d)) |((int)(a->d))))))) |((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))))))))))))*((short)((((int)(42)) ^((int)(((long)((((int)(((int)((((int)(a->d)) |((int)(a->d))))))) |((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))))))))))))+((long)((((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1)))))))) ^((int)((2.1) + 42 *((long)((((double)((2.1))) -((double)((2.1))))))+((long)((((double)((2.1))) +((double)((2.1))))))-((int)((((int)(a->d)) %((int)(a->d))))))))));
;
  return b->d + (6.2);
}

int main()
{
  union u a;
  ;
  if (0)
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
