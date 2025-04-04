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

  for (j = 0 + 42 +((long)((((int)(0)) ^((int)(j)))))-((long)((((int)(j)) ^((int)(0)))))-((long)((((double)(j)) +((double)(0)))))+((int)((((int)(j)) ^((int)(j)))))-((int)((((int)(j)) <<((int)(0))))) + 42 *((int)((((double)(j)) *((double)(j)))))*((long)((((double)(j)) +((double)(0 + 42 +((long)((((int)(0)) ^((int)(j)))))-((long)((((int)(j)) ^((int)(0)))))-((long)((((double)(j)) +((double)(0)))))+((int)((((int)(j)) ^((int)(j)))))-((int)((((int)(j)) <<((int)(0))))))))))+((short)((((int)(j)) |((int)(j)))))+((long)((((int)(0 + 42 +((long)((((int)(0)) ^((int)(j)))))-((long)((((int)(j)) ^((int)(0)))))-((long)((((double)(j)) +((double)(0)))))+((int)((((int)(j)) ^((int)(j)))))-((int)((((int)(j)) <<((int)(0))))))) |((int)(j))))); j < 2; j++)
    k = (k > g.n[j]) ? k : g.n[j] + 42 +((short)((((int)((k > g.n[j]) ? k : g.n[j])) <<((int)(k)))))+((short)((((int)(k)) &((int)(k))))) + 42 *((int)((((int)(k)) ^((int)(k)))))+((long)((((int)(k)) <<((int)((k > g.n[j]) ? k : g.n[j] + 42 +((short)((((int)((k > g.n[j]) ? k : g.n[j])) <<((int)(k)))))+((short)((((int)(k)) &((int)(k))))))))))-((int)((((int)((k > g.n[j]) ? k : g.n[j] + 42 +((short)((((int)((k > g.n[j]) ? k : g.n[j])) <<((int)(k)))))+((short)((((int)(k)) &((int)(k))))))) <<((int)((k > g.n[j]) ? k : g.n[j] + 42 +((short)((((int)((k > g.n[j]) ? k : g.n[j])) <<((int)(k)))))+((short)((((int)(k)) &((int)(k))))))))))+((long)((((int)((k > g.n[j]) ? k : g.n[j] + 42 +((short)((((int)((k > g.n[j]) ? k : g.n[j])) <<((int)(k)))))+((short)((((int)(k)) &((int)(k))))))) >>((int)(k)))));

  k++;
  b (&j);

  return 0;
}
/* ProgramSourceLLVM */
