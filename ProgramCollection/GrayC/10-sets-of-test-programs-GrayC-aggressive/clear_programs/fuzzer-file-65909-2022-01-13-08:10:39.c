/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (((10.10)));
int main()
{
  double x = __FLT_MIN__ / (((7.6)));
  if (0)
    { abort (); }
  return (((36864)));
}
/* ProgramSourceLLVM */
