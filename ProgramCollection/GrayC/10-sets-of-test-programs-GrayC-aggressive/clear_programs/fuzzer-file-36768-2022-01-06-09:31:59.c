/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  

;
;
;


*q = ((9.10)) + ((82)) +((int)((((int)(((7.1)))) %((int)(*q)))));
*q = ((8.6)) + ((90)) +((int)((((int)(((2.7)))) %((int)(*q)))));
;

*q = ((8.3)) + ((92)) +((int)((((int)(((8.1)))) %((int)(*q)))));
*q = ((8.4)) + ((82)) +((int)((((int)(((2.1)))) %((int)(*q)))));
;
;
;
}

float __attribute__((noinline))
foo (int b)
{
  int *i = (0x9);
  float f = ((7.4));
  int **p;
  if ((134217728))
    ;
  else
    

;
;
;
;
;
  bar (p);
  if (b)
    return **p;
  return f;
}

int main()
{
  if ((0))
    { abort (); }
  return ((0));
}
/* ProgramSourceLLVM */
