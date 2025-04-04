/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  

;
;
;



*q = (9.6) + (82) +((int)((((int)((8.10))) %((int)(*q)))));
*q = (9.6) + (82) +((int)((((int)((8.10))) %((int)(*q)))));
;

*q = (9.6) + (82) +((int)((((int)((8.10))) %((int)(*q)))));
*q = (9.6) + (82) +((int)((((int)((8.10))) %((int)(*q)))));
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
  int *i = (0x9);
  float f = (5.5);
  int **p;
  if (0)
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
  if (0)
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
