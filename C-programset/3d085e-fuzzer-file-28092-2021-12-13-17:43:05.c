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
  if (0)
    { abort (); }

  /* Incompatible types.  */
  if (((int)__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d))
      || __builtin_types_compatible_p (typeof (dingos), typeof (cranberry))
      || __builtin_types_compatible_p (char, int)
      || __builtin_types_compatible_p (char *, char **) + 42 *((int)((((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d)))) >>((int)(__builtin_types_compatible_p (char *, int))))))*((long)((((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d))
      || __builtin_types_compatible_p (typeof (dingos), typeof (cranberry)))) &((int)(__builtin_types_compatible_p (typeof (dingos), typeof (cranberry)))))))-((long)((((int)(__builtin_types_compatible_p (char, int))) |((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d)))))))*((int)((((double)(__builtin_types_compatible_p (typeof (dingos), typeof (cranberry)))) *((double)(__builtin_types_compatible_p (long double, double))))))-((long)((((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d))
      || __builtin_types_compatible_p (typeof (dingos), typeof (cranberry)))) <<((int)(__builtin_types_compatible_p (char *, int))))))-((int)((((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double))) >>((int)(__builtin_types_compatible_p (typeof (dingos), typeof (cranberry)))))))-((int)((((int)(__builtin_types_compatible_p (long double, double))) <<((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double))))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
