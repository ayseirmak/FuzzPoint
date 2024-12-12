/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (3.9);
int main()
{
  double x = __FLT_MIN__ / (3.9);
  if (x != d)
    { abort (); }
  return (16384);
}
/* ProgramSourceLLVM */
