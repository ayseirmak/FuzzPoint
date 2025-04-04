/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (8.9);
int main()
{
  double x = __FLT_MIN__ / (4.1);
  if ((0))
    { abort (); }
  return (0);
}
/* ProgramSourceLLVM */
