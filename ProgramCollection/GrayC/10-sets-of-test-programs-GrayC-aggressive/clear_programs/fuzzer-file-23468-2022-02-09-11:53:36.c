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

  
int loop_break_2525 = 0;
for (j = (0x559C) + 42 *((int)((((int)((0x559C))) ^((int)(j)))))*((short)((((int)(j)) &((int)(j)))))+((long)((((double)(j)) *((double)(j)))))-((long)((((double)(j)) -((double)((0x559C))))))*((short)((((int)(j)) %((int)(j))))) + 42 -((int)((((int)((0x559C) + 42 *((int)((((int)((0x559C))) ^((int)(j)))))*((short)((((int)(j)) &((int)(j)))))+((long)((((double)(j)) *((double)(j)))))-((long)((((double)(j)) -((double)((0x559C))))))*((short)((((int)(j)) %((int)(j))))))) ^((int)(j)))))+((long)((((int)(j)) >>((int)(j)))))*((int)((((int)(j)) &((int)(j)))))-((int)((((double)(j)) *((double)(j))))); j < (10); j++)
    
;
;
;

  k--;
  b (&j);

  return (0);
}
/* ProgramSourceLLVM */
