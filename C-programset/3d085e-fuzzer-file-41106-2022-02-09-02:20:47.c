/* corpus/20031214-1.c */
/* PR optimization/10312 */
/* Originator: Peter van Hoof <p dot van-hoof at qub dot ac dot uk> */

/* Verify that the strength reduction pass doesn't find
   illegitimate givs.  */

struct
{
  double a;
  int n[(0x811EC)];
} g = { ((6.7)), { ((17)), (0x7E5E9)}};

int k = (-(0x41741));

void
b (int *j)
{
}

int
main ()
{
  int j = ((0x7));

  
int loop_break_1003 = 0;
for (j = (0x559C); j < ((-11)); j++)
    
;

k = (k > g.n[j]) ? k : g.n[j];
k = (k > g.n[j]) ? k : g.n[j];
;
;

  k--;
  b (&j);

  return ((2251799813685248));
}
/* ProgramSourceLLVM */
