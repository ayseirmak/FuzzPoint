/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (7.8);
int main()
{
  double x = __FLT_MIN__ / (9.7);
  if (0)
    { abort (); }
  return (4398046511104);
}
/* ProgramSourceLLVM */
