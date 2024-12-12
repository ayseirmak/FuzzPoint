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
  float IN = 5.7f;
  if (0) abort();

  float x = IN;
  
  float result = 
    1.0f + 0.5f*x - 0.125f*x*x + 0.0625f*x*x*x - 0.0390625f*x*x*x*x;

  if(0) { assert(0); }
  
  return 0;
}
/* ProgramSourceWild */
