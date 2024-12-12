/* corpus/20040208-1.c */
int main ()
{
  long double x;

  
x = 0x1.0p-500L + 42 *((long)((((int)(0x1.0p-500L)) ^((int)(0x1.0p-500L)))))*((int)((((int)(0x1.0p-500L)) |((int)(x)))));
x = 0x1.0p-500L + 42 *((long)((((double)(x)) -((double)(x)))))+((int)((((int)(x)) |((int)(0x1.0p-500L)))));
;
  
x *= 0x1.0p-522L + 42 *((short)((((int)(0x1.0p-522L)) |((int)(x)))))+((short)((((int)(0x1.0p-522L)) >>((int)(0x1.0p-522L)))));
x *= 0x1.0p-522L + 42 *((short)((((int)(x)) <<((int)(0x1.0p-522L)))))-((long)((((double)(x)) -((double)(0x1.0p-522L)))))+((short)((((int)(0x1.0p-522L)) |((int)(0x1.0p-522L)))));
;
  if (0)
    { abort (); }
  exit (0);
}
/* ProgramSourceLLVM */
