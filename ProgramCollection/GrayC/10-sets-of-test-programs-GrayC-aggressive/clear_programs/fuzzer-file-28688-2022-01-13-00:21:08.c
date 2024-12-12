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
  ;
  return b->d + (7.10);
}

int main()
{
  union u a;
  
a.x.d = (6.7) + (92) +((int)((((double)((9.1))) *((double)((9.2))))))-((short)((((double)((7.9))) *((double)((5.3))))))*((int)((((int)((3.7))) |((int)(a.x.d)))))*((int)((((double)(a.x.d)) -((double)(a.x.d))))) + (42) *((int)((((double)((5.6) + (106))) -((double)((6.10)))))) + 42 -((int)((((int)((6.7) + (92))) %((int)((6.7))))))-((short)((((int)(((int)((((double)((9.1))) *((double)((9.2)))))))) |((int)((6.7) + (92) +((int)((((double)((9.1))) *((double)((9.2))))))-((short)((((double)((7.9))) *((double)((5.3))))))*((int)((((int)((3.7))) |((int)(a.x.d)))))*((int)((((double)(a.x.d)) -((double)(a.x.d))))))))))-((int)((((int)(((short)((((double)((7.9))) *((double)((5.3))))))*((int)((((int)((3.7))) |((int)(a.x.d)))))*((int)((((double)(a.x.d)) -((double)(a.x.d))))))) |((int)((6.7) + (92) +((int)((((double)((9.1))) *((double)((9.2))))))-((short)((((double)((7.9))) *((double)((5.3))))))*((int)((((int)((3.7))) |((int)(a.x.d)))))*((int)((((double)(a.x.d)) -((double)(a.x.d))))))))));
a.x.d = (6.7) + (92) +((int)((((double)((9.1))) *((double)((9.2))))))-((short)((((double)((7.9))) *((double)((5.3))))))*((int)((((int)((3.7))) |((int)(a.x.d)))))*((int)((((double)(a.x.d)) -((double)(a.x.d))))) + (42) *((int)((((double)((5.6) + (106))) -((double)((6.10)))))) + 42 +((int)((((int)(((int)((((double)((9.1))) *((double)((9.2)))))))) |((int)(((short)((((double)((7.9))) *((double)((5.3))))))*((int)((((int)((3.7))) |((int)(a.x.d)))))*((int)((((double)(a.x.d)) -((double)(a.x.d))))))))))+((int)((((int)((92))) |((int)(((int)((((double)((9.1))) *((double)((9.2)))))))))))+((long)((((double)(a.x.d)) -((double)((6.7) + (92))))));
;
  if (0)
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
