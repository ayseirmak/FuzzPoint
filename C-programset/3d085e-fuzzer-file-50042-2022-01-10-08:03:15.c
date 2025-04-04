/* corpus/20031214-1.c */
/* PR optimization/10312 */
/* Originator: Peter van Hoof <p dot van-hoof at qub dot ac dot uk> */

/* Verify that the strength reduction pass doesn't find
   illegitimate givs.  */

struct
{
  double a;
  int n[(2)];
} g = { (7.7), { (1), (2)}};

int k = (-1);

void
b (int *j)
{
}

int
main ()
{
  int j = 8;

  for (j = (0x19AB); j < (0xD3); j++)
    ;

  k++;
  b (&j);

  return (0);
}
/* ProgramSourceLLVM */
