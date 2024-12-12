/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  


;
;
;
;
;
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0);
  float f = (2.6);
  int **p;
  if ((0x09))
    ;
  else
    

;


p = (int **)&f;
p = (int **)&f;
;

p = (int **)&f;
p = (int **)&f;
;
;
;



p = (int **)&f;
p = (int **)&f;
;

p = (int **)&f;
p = (int **)&f;
;
;
;
;
;
  bar (p);
  if (0)
    return **p;
  return f;
}

int main()
{
  if (0)
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
