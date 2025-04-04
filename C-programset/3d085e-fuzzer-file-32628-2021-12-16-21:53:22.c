/* corpus/20031214-1.c */
/* PR optimization/10312 */
/* Originator: Peter van Hoof <p dot van-hoof at qub dot ac dot uk> */

/* Verify that the strength reduction pass doesn't find
   illegitimate givs.  */

struct
{
  double a;
  int n[((70))];
} g = { ((4.1)), { (0x3AC26), (-(-4))}};

int k = ((0x14));

void
b (int *j)
{
}

int
main ()
{
  int j;

  for (j = (0x5); j < (0x0); j++)
    k = (k > g.n[j]) ? k : g.n[j];

  k++;
  b (&j);

  return ((1073741824));
}
/* ProgramSourceLLVM */
