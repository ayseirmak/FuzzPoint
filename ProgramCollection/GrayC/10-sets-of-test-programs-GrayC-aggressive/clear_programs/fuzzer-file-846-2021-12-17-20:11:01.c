/* corpus/20031214-1.c */
/* PR optimization/10312 */
/* Originator: Peter van Hoof <p dot van-hoof at qub dot ac dot uk> */

/* Verify that the strength reduction pass doesn't find
   illegitimate givs.  */

struct
{
  double a;
  int n[(66)];
} g = { (5.9), { (0x3AC26), (-3)}};

int k = (0);

void
b (int *j)
{
}

int
main ()
{
  int j;

  for (j = (0x5) + 42 +((long)((((int)((0x5))) <<((int)((0x5)))))); j < (0x0); j++)
    k = (k > g.n[j]) ? k : g.n[j] + 42 +((int)((((int)((k > g.n[j]) ? k : g.n[j])) ^((int)(k)))))+((int)((((double)(k)) -((double)(k)))))*((int)((((int)((k > g.n[j]) ? k : g.n[j])) |((int)((k > g.n[j]) ? k : g.n[j])))))-((long)((((int)((k > g.n[j]) ? k : g.n[j])) &((int)(k)))))+((short)((((int)((k > g.n[j]) ? k : g.n[j])) >>((int)((k > g.n[j]) ? k : g.n[j])))));

  k++;
  b (&j);

  return (0);
}
/* ProgramSourceLLVM */
