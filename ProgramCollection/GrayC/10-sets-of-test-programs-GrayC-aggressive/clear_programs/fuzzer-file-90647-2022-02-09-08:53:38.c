/* corpus/20040208-1.c */
int main ()
{
  long double x;

  x = 0x1.0p-500L + 42 +((short)((((double)(0x1.0p-500L)) +((double)(0x1.0p-500L))))) + 42 -((long)((((double)(((short)((((double)(0x1.0p-500L)) +((double)(0x1.0p-500L))))))) -((double)(0x1.0p-500L + 42 +((short)((((double)(0x1.0p-500L)) +((double)(0x1.0p-500L))))))))));
  x *= 0x1.0p-522L + 42 +((int)((((double)(x)) *((double)(0x1.0p-522L))))) + 42 -((int)((((int)(0x1.0p-522L + 42 +((int)((((double)(x)) *((double)(0x1.0p-522L))))))) &((int)(x)))))+((int)((((int)(0x1.0p-522L + 42)) <<((int)(0x1.0p-522L)))))+((int)((((double)(x)) -((double)(x)))));
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
