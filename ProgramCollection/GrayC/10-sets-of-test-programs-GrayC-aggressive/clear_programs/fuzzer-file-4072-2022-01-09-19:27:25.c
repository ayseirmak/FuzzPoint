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
  a->d = (3.4) + (42) *((int)((((double)(a->d)) *((double)((8.7))))))+((long)((((double)(a->d)) -((double)(a->d)))))+((short)((((double)((6.1))) -((double)(a->d)))));
  return b->d + (4.3);
}

int main()
{
  union u a;
  a.x.d = (10.2) + (0x927278) *((short)((((double)(a.x.d)) +((double)((9.4))))))+((int)((((int)(a.x.d)) ^((int)(a.x.d)))))+((long)((((double)(a.x.d)) -((double)((4.8))))))-((short)((((double)((10.10))) *((double)((6.7))))))+((short)((((int)((10.6))) &((int)((3.1))))));
  if (0)
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
