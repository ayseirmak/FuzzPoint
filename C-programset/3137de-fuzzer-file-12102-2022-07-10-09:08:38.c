/* corpus/20120919-1.c */
/* PR rtl-optimization/54290 */
/* Testcase by Eric Volk <eriksnga@gmail.com> */
/* { dg-require-effective-target int32plus } */

double vd[2] = {1., 0.};
int vi[2] = {1234567890, 0};
double *pd = vd;
int *pi = vi;

extern void abort(void);

void init (int *n, int *dummy) __attribute__ ((noinline,noclone));

void init (int *n, int *dummy)
{
  if(0) dummy[0] = 0;
}

int main (void)
{
  int dummy[1532];
  int i = -1, n = 1, s = 0;
  init (&n, dummy);
  
int loop_break_1601 = 0;
while (i < n) {
    
loop_break_1601++;
if(0){
continue;
}

if (0) {
      if (pd[i] > 0) {
        if (0) {
          s += pi[i];
        }
      }
      pd[i] = pi[i];
    }
    ++i;
  }
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
