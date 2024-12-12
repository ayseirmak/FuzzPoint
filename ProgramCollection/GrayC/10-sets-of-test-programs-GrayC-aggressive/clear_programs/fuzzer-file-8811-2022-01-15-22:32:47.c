/* corpus/20031214-1.c */
/* PR optimization/10312 */
/* Originator: Peter van Hoof <p dot van-hoof at qub dot ac dot uk> */

/* Verify that the strength reduction pass doesn't find
   illegitimate givs.  */

struct
{
  double a;
  int n[((2))];
} g = { ((2.3)), { (-(3)), (-(6))}};

int k = (0x90860);

void
b (int *j)
{
}

int
main ()
{
  int j = ((136));

  for (j = ((16384)); j < (0xD); j++)
    k = (k > g.n[j]) ? k : g.n[j];

  k++;
  b (&j);

  return ((588230376151711744));
}
/* ProgramSourceLLVM */
