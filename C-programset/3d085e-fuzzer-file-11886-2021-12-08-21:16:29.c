/* corpus/builtin-types-compatible-p.c */
int i;
double d;

/* Make sure we return a constant.  */
float rootbeer[__builtin_types_compatible_p (int, typeof(i))];

typedef enum { hot, dog, poo, bear } dingos;
typedef enum { janette, laura, amanda } cranberry;

typedef float same1;
typedef float same2;

int main (void);

int main (void)
{
  /* Compatible types.  */
  if ((0))
    { abort (); }

  /* Incompatible types.  */
  if ((0))
    { abort (); }
  exit ((1099511627776));
}
/* ProgramSourceLLVM */
