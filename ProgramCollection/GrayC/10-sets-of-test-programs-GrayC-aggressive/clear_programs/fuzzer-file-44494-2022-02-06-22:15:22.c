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
  if (!(__builtin_types_compatible_p (int, const int)
	&& __builtin_types_compatible_p (typeof (hot), int)
	&& __builtin_types_compatible_p (typeof (hot), typeof (laura))
	&& __builtin_types_compatible_p (int[5], int[])
	&& __builtin_types_compatible_p (same1, same2)))
    { abort (); }

  /* Incompatible types.  */
  if (((int)((int)__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d))
      || __builtin_types_compatible_p (typeof (dingos), typeof (cranberry))
      || __builtin_types_compatible_p (char, int)
      || __builtin_types_compatible_p (char *, char **) + 42 *((short)((((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d)))) <<((int)(__builtin_types_compatible_p (char *, char **))))))+((int)((((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *))) <<((int)(__builtin_types_compatible_p (char *, const char *))))))) + 42 *((short)((((int)(42)) |((int)((int)__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double))))))*((short)((((int)((int)__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *))) ^((int)(__builtin_types_compatible_p (typeof (dingos), typeof (cranberry)))))))-((int)((((int)((int)__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d)))) |((int)((int)__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *))))))*((int)((((int)(__builtin_types_compatible_p (typeof (dingos), typeof (cranberry)))) <<((int)((int)__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d))
      || __builtin_types_compatible_p (typeof (dingos), typeof (cranberry)))))))-((int)((((int)(((int)((((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *))) <<((int)(__builtin_types_compatible_p (char *, const char *)))))))) ^((int)((int)__builtin_types_compatible_p (char *, int))))))*((long)((((int)(__builtin_types_compatible_p (char, int))) |((int)(((short)((((int)(__builtin_types_compatible_p (char *, int)
      || __builtin_types_compatible_p (char *, const char *)
      || __builtin_types_compatible_p (long double, double)
      || __builtin_types_compatible_p (typeof (i), typeof (d)))) <<((int)(__builtin_types_compatible_p (char *, char **)))))))))))))
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
