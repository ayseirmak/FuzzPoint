/* corpus/20031214-1.c */
/* PR optimization/10312 */
/* Originator: Peter van Hoof <p dot van-hoof at qub dot ac dot uk> */

/* Verify that the strength reduction pass doesn't find
   illegitimate givs.  */

struct
{
  double a;
  int n[(2)];
} g = { (10.8), { (1), (0xA3C7)}};

int k = (0);

void
b (int *j)
{
}

int
main ()
{
  int j;

  
int loop_break_1078 = 0;
for (j = (32) + 42 -((short)((((int)((32))) &((int)((32)))))); j < (2); j++)
    ;

  k++;
  b (&j);

  return (0);
}
/* ProgramSourceLLVM */
