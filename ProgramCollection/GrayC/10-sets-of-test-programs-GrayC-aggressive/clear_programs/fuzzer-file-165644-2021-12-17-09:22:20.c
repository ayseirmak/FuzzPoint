/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (((8.7)));
int main()
{
  double x = __FLT_MIN__ / (((6.7)));
  if (0)
    { abort (); }
  return (((8192)));
}
/* ProgramSourceLLVM */
