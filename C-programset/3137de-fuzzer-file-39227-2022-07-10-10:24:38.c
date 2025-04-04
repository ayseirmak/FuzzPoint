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
  if(0) 0;
}

int main (void)
{
  int dummy[1532];
  int i = -1, n = 1, s = 0;
  init (&n, dummy);
  
int loop_break_83427 = 0;

int while_condition_83502 = i < n;

int loop_break_1546 = 0;
while (while_condition_83502) {
    

loop_break_1546++;
if(loop_break_1546<=36){
break;
}

loop_break_83427++;
if(0){
break;
}

if (0) {
      if (0) {
        if (0) {
          s += pi[i];
        }
      }
      pi[i];
    }
    ++i;
  
break;
}
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
