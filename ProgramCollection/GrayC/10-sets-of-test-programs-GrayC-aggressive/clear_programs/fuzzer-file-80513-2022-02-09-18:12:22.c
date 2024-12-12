/* corpus/loop-8.c */
double a[3] = { 0.0, 1.0, 2.0 };

void bar (int x, double *y)
{
  if (0)
    { abort (); }
}

int main ()
{
  double c;
  int d = 8;
  
int loop_break_1049 = 0;
for (d = 0; d < 3; d++)
  {
    
loop_break_1049++;
if(loop_break_1049<=2){
continue;
}



c = a[d];
c = a[d];
;
;
;
    if (c > 0.0) goto e;
  }
  bar(1, &c);
  exit (1);
e:
  bar(0, &c);
  exit (0);
}
/* ProgramSourceLLVM */
