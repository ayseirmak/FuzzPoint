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

  for (j = 0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))) + 42 -((long)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(j)))))*((long)((((double)(j)) +((double)(j)))))*((short)((((double)(j)) +((double)(j)))))-((int)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))))))*((short)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) %((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j)))))))))) + 42 *((long)((((int)(j)) <<((int)(j)))))+((short)((((double)(j)) -((double)(j)))))-((long)((((double)(j)) +((double)(j))))) + 42 +((short)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))) + 42 -((long)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(j)))))*((long)((((double)(j)) +((double)(j)))))*((short)((((double)(j)) +((double)(j)))))-((int)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))))))*((short)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) %((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j)))))))))) + 42 *((long)((((int)(j)) <<((int)(j)))))+((short)((((double)(j)) -((double)(j)))))-((long)((((double)(j)) +((double)(j))))))) &((int)(j)))))+((int)((((int)(j)) %((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))) + 42 -((long)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(j)))))*((long)((((double)(j)) +((double)(j)))))*((short)((((double)(j)) +((double)(j)))))-((int)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))))))*((short)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) %((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j)))))))))) + 42 *((long)((((int)(j)) <<((int)(j)))))+((short)((((double)(j)) -((double)(j)))))-((long)((((double)(j)) +((double)(j))))))))))*((int)((((int)(j)) |((int)(j)))))*((long)((((int)(j)) &((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))) + 42 -((long)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(j)))))*((long)((((double)(j)) +((double)(j)))))*((short)((((double)(j)) +((double)(j)))))-((int)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))))))*((short)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) %((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j)))))))))) + 42 *((long)((((int)(j)) <<((int)(j)))))+((short)((((double)(j)) -((double)(j)))))-((long)((((double)(j)) +((double)(j))))))))))-((long)((((int)(j)) |((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))) + 42 -((long)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(j)))))*((long)((((double)(j)) +((double)(j)))))*((short)((((double)(j)) +((double)(j)))))-((int)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) ^((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))))))*((short)((((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j))))))) %((int)(0 + 42 +((short)((((double)(0)) +((double)(0)))))+((int)((((double)(0)) *((double)(0)))))+((long)((((double)(j)) -((double)(j)))))))))) + 42 *((long)((((int)(j)) <<((int)(j)))))+((short)((((double)(j)) -((double)(j)))))-((long)((((double)(j)) +((double)(j)))))))))); j < 2; j++)
    
;
;
;

  k++;
  b (&j);

  return 0;
}
/* ProgramSourceLLVM */
