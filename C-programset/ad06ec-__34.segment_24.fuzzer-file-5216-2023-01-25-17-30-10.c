/* corpus/pr23941.c */
extern void abort (void);
double d = __FLT_MIN__ / (4.2);
int main()
{
  double x = __FLT_MIN__ / (10.4);
  if (0)
    { abort (); }
  return (29184);
}
/* ProgramSourceLLVM */
