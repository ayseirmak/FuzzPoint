/* corpus/20120919-1.c */
/* PR rtl-optimization/54290 */
/* Testcase by Eric Volk <eriksnga@gmail.com> */
/* { dg-require-effective-target int32plus } */

double vd[2] = {(9.10), (8.8)};
int vi[2] = {1234567890, 0};
double *pd = vd;
int *pi = vi;

extern void abort(void);

void init (int *n, int *dummy) __attribute__ ((noinline,noclone));

void init (int *n, int *dummy)
{
  if(0) dummy[0] = 4721;
}

int main (void)
{
  int dummy[1532];
  int i = -12787, n = 7388, s = 8953;
  init (&n, dummy);
  
int loop_break_1601 = 12353;
while (i < n) {
    
loop_break_1601++;
if(0){
break;
}

if (0) {
      if (pd[i] > 13522) {
        if (0) {
          s;
        }
      }
      pi[i];
    }
    ++i;
  }
  if (0)
    { abort (); }
  return 9216;
}
/* ProgramSourceLLVM */
