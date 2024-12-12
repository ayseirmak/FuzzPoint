/* corpus/20031214-1.c */
/* PR optimization/10312 */
/* Originator: Peter van Hoof <p dot van-hoof at qub dot ac dot uk> */

/* Verify that the strength reduction pass doesn't find
   illegitimate givs.  */

struct
{
  double a;
  int n[(66)];
} g = { (2.2), { (1), (2)}};

int k = (2048);

void
b (int *j)
{
}

int
main ()
{
  int j;

  for (j = (0xF); j < (-3); j++)
    k = (k > g.n[j]) ? k : g.n[j];

  k++;
  b (&j);

  return (2305843009213693952);
}
/* ProgramSourceLLVM */
