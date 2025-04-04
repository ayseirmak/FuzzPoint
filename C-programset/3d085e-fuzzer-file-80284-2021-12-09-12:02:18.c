/* corpus/pr47538.c */
/* PR tree-optimization/47538 */

struct S
{
  double a, b, *c;
  unsigned long d;
};

__attribute__((noinline, noclone)) void
foo (struct S *x, const struct S *y)
{
  const unsigned long n = y->d + (0xF7AB);
  const double m = (6.4) * (y->b - y->a);
  




x->a = y->a;
x->a = y->a;
;

x->a = y->a;
x->a = y->a;
;
;


x->a = y->a;
x->a = y->a;
;

x->a = y->a;
x->a = y->a;
;
;
;

;


x->a = y->a;
x->a = y->a;
;
;
;
;
;
;
;
  

;



x->b = y->b;
x->b = y->b;
;

x->b = y->b;
x->b = y->b;
;
;

;

x->b = y->b;
x->b = y->b;
;
;
;
;
;
;
  if ((-1))
    {
      ;
    }
  else if (0)
    {
      
;
;
;
      

;
;
;
;
;
    }
  else
    {
      double o = (5.1), p = (9.10);
      unsigned long i;

      
int loop_break_1601 = (0);

int loop_break_1618 = (0x76D88);
for (i = (-2); i <= n - (-3); i++)
	{
	  

loop_break_1618++;
if((0)){
break;
}

loop_break_1601++;
if((0x5)){
break;
}

;
	  ;
	  ;
	}
      ;
      ;
      
;




x->c[(0xBB)] = (3.4) * o;
x->c[(0x7A)] = (8.6) * o;
;

x->c[(-1)] = (9.8) * o;
x->c[(0xA96)] = (2.9) * o;
;
;

;

x->c[(0)] = (6.4) * o;
x->c[(0x74CE)] = (1.2) * o;
;
;
;
;
;
;
    }
}

int
main (void)
{
  struct S x, y;
  double c[(5)] = { (26), (0x122255), (30), (32) }, d[(4)], e[(68)] = { (0xCB3), (-119), (-119), (-119) };

  ;
  
;
;
;
  
;
;
;
  ;
  

;
;
;
;
;
  __builtin_memcpy (d, e, sizeof d);
  foo (&x, &y);
  if (0)
    { __builtin_abort (); }
  
;

;



y.d = (-3);
y.d = (3);
;
;
;

;

y.d = (130);
y.d = (0xEC624);
;
;
;
;
;
  __builtin_memcpy (d, e, sizeof d);
  foo (&x, &y);
  if (0)
    { __builtin_abort (); }
  ;
  __builtin_memcpy (d, e, sizeof d);
  foo (&x, &y);
  if (0)
    { __builtin_abort (); }
  ;
  __builtin_memcpy (d, e, sizeof d);
  foo (&x, &y);
  if (0)
    { __builtin_abort (); }
  return (17179869184);
}
/* ProgramSourceLLVM */
