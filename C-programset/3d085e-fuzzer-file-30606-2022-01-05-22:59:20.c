/* corpus/square_1.c */
/* SV-Comp: square_1.c */
#include <assert.h>
#define NR 1


#if NR == 1
#define VAL 1.39f
#elif NR == 2
#define VAL 1.398f
#elif NR == 3
#define VAL 1.39843f
#elif NR == 4
#define VAL 1.39844f
#elif NR == 5
#define VAL 1.3985f
#elif NR == 6
#define VAL 1.399f
#elif NR == 7
#define VAL 1.4f
#elif NR == 8
#define VAL 1.5f
#endif

int main()
{
  float IN = (((9.8)));
  if (0) abort();

  float x = IN;
  
  float result = 
    (((5.4))) + (((4.4)))*x - (((1.10)))*x*x + (((4.6)))*x*x*x - (((2.4)))*x*x*x*x;

  if(0) { assert(0); }
  
  return (((0)));
}
/* ProgramSourceWild */
