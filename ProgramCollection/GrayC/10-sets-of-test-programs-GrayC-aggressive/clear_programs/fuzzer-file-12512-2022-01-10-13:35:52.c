/* corpus/20031214-1.c */
/* PR optimization/10312 */
/* Originator: Peter van Hoof <p dot van-hoof at qub dot ac dot uk> */

/* Verify that the strength reduction pass doesn't find
   illegitimate givs.  */

struct
{
  double a;
  int n[2];
} g = { 0., { 1, 2}};

int k = 0;

void
b (int *j)
{
}

int
main ()
{
  int j = 8;

  for (j = 0 + 42 +((int)((((int)(0)) |((int)(0)))))-((int)((((double)(0)) *((double)(j)))))*((short)((((int)(0)) >>((int)(j))))); j < 2; j++)
    k = (k > g.n[j]) ? k : g.n[j] + 42 -((short)((((int)(k)) |((int)((k > g.n[j]) ? k : g.n[j])))))*((short)((((double)(k)) *((double)(k)))));

  k++;
  b (&j);

  return 0;
}
/* ProgramSourceLLVM */
