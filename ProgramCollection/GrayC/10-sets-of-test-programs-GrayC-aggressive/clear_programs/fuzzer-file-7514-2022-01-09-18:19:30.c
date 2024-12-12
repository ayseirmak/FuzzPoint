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
  float IN = (4.6);
  if (0) abort();

  float x = IN;
  
  float result = 
    (10.8) + (1.10)*x - (1.8)*x*x + (7.1)*x*x*x - (5.3)*x*x*x*x;

  if(0) { assert(0); }
  
  return (0);
}
/* ProgramSourceWild */
