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

  
int loop_break_963 = 0;
for (j = (0x5); j < (0x0); j++)
    ;

  k++;
  b (&j);

  return (0);
}
/* ProgramSourceLLVM */
