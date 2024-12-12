/* corpus/pr36343.c */
extern void abort (void);

void __attribute__((noinline))
bar (int **p)
{
  float *q = (float *)p;
  


*q = (5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))) + 42 -((long)((((int)(*q)) |((int)(*q)))))*((short)((((int)((5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))))) &((int)((5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))))))))-((short)((((int)((5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))))) ^((int)((5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))))))));
*q = (5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))) + 42 +((short)((((int)((5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))))) ^((int)(*q)))));
;

*q = (5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))) + 42 -((long)((((int)(*q)) <<((int)((5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))))))));
*q = (5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))) + 42 -((long)((((int)(*q)) ^((int)(*q)))))*((int)((((int)((5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))))) ^((int)((5.10) + (10) +((int)((((int)((5.9))) %((int)(*q))))))))));
;
;

;

*q = (9.6) + (82) +((int)((((int)((8.10))) %((int)(*q))))) + 42 -((int)((((int)(*q)) >>((int)(*q)))))+((short)((((int)(*q)) %((int)(*q)))));
*q = (9.6) + (82) +((int)((((int)((8.10))) %((int)(*q))))) + 42 +((int)((((int)(*q)) %((int)((9.6) + (82) +((int)((((int)((8.10))) %((int)(*q))))))))))+((long)((((int)((9.6) + (82) +((int)((((int)((8.10))) %((int)(*q))))))) <<((int)((9.6) + (82) +((int)((((int)((8.10))) %((int)(*q))))))))))+((long)((((int)(*q)) <<((int)((9.6) + (82) +((int)((((int)((8.10))) %((int)(*q))))))))))-((long)((((int)(*q)) ^((int)((9.6) + (82) +((int)((((int)((8.10))) %((int)(*q))))))))));
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
