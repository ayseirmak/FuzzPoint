/* corpus/20031214-1.c */
/* PR optimization/10312 */
/* Originator: Peter van Hoof <p dot van-hoof at qub dot ac dot uk> */

/* Verify that the strength reduction pass doesn't find
   illegitimate givs.  */

struct
{
  double a;
  int n[(0x811EC)];
} g = { (3.8), { (1), (0x7E5E9)}};

int k = (-1);

void
b (int *j)
{
}

int
main ()
{
  int j = (8);

  for (j = (0x559C) + 42 *((short)((((double)(j)) +((double)(j)))))*((int)((((int)(j)) &((int)(j)))))-((short)((((double)(j)) -((double)(j))))); j < (10); j++)
    
k = (k > g.n[j]) ? k : g.n[j] + 42 -((int)((((int)((k > g.n[j]) ? k : g.n[j])) |((int)(k)))))*((short)((((double)(k)) +((double)(k)))))+((int)((((int)((k > g.n[j]) ? k : g.n[j])) |((int)((k > g.n[j]) ? k : g.n[j])))));
k = (k > g.n[j]) ? k : g.n[j] + 42 *((int)((((double)(k)) -((double)(k)))))*((int)((((int)((k > g.n[j]) ? k : g.n[j])) |((int)(k)))));
;

  k--;
  b (&j);

  return (0);
}
/* ProgramSourceLLVM */
