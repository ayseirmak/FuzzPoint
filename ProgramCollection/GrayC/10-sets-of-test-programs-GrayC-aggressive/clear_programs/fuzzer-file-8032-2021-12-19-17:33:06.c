/* corpus/20040208-1.c */
int main ()
{
  long double x;

  
x = 0x1.0p-500L + 42 +((int)((((double)(0x1.0p-500L)) *((double)(0x1.0p-500L)))))*((short)((((int)(0x1.0p-500L)) |((int)(x)))));
x = 0x1.0p-500L + 42 +((int)((((double)(0x1.0p-500L)) *((double)(0x1.0p-500L)))))*((short)((((int)(0x1.0p-500L)) |((int)(x)))));
;
  
x *= 0x1.0p-522L + 42 -((short)((((int)(x)) >>((int)(0x1.0p-522L)))))*((long)((((double)(0x1.0p-522L)) +((double)(x)))));
x *= 0x1.0p-522L + 42 -((short)((((int)(x)) >>((int)(0x1.0p-522L)))))*((long)((((double)(0x1.0p-522L)) +((double)(x)))));
;
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
