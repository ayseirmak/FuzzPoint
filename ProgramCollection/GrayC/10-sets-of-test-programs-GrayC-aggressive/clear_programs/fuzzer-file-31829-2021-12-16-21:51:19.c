/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (((6.1)));
int main()
{
  double x = __FLT_MIN__ / (((4.6)));
  if (0)
    { abort (); }
  return (((8704)));
}
/* ProgramSourceLLVM */
