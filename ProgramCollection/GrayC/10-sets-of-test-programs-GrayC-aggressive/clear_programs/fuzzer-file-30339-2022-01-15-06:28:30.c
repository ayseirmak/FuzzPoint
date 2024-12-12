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

  for (j = 0 + 42 +((short)((((int)(j)) >>((int)(j)))))+((int)((((int)(0)) &((int)(j)))))+((int)((((int)(j)) |((int)(0)))))*((int)((((int)(j)) ^((int)(j))))); j < 2; j--)
    ;

  k++;
  b (&j);

  return 0;
}
/* ProgramSourceLLVM */
