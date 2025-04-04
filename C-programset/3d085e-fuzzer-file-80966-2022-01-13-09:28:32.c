/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)((int)x != 0.0 && (x * 0.5 == x) + 42 *((short)((((int)(0.0)) ^((int)(0.0)))))+((long)((((int)((x * 0.5 == x))) &((int)(0.0)))))*((int)((((int)((x * 0.5 == x))) |((int)(0.0)))))-((long)((((int)((x * 0.5 == x))) ^((int)(x)))))-((short)((((int)(x != 0.0)) &((int)((x * 0.5 == x))))))*((short)((((double)(x != 0.0)) +((double)(0.0)))))) + 42 *((short)((((int)(((short)((((int)(x != 0.0)) &((int)((x * 0.5 == x))))))*((short)((((double)(x != 0.0)) +((double)(0.0))))))) <<((int)((int)x)))))-((long)((((int)(((int)((((int)((x * 0.5 == x))) |((int)(0.0))))))) %((int)(((long)((((int)((x * 0.5 == x))) ^((int)(x))))))))))+((long)((((int)((x * 0.5 == x) + 42 *((short)((((int)(0.0)) ^((int)(0.0)))))+((long)((((int)((x * 0.5 == x))) &((int)(0.0)))))*((int)((((int)((x * 0.5 == x))) |((int)(0.0))))))) <<((int)(((long)((((int)((x * 0.5 == x))) &((int)(0.0))))))))))+((short)((((int)(((short)((((int)(x != 0.0)) &((int)((x * 0.5 == x))))))*((short)((((double)(x != 0.0)) +((double)(0.0))))))) &((int)(0.0)))))))
    { return 1; }
  if (0)
    return 2;
  else
    return 3;
}
int main(void)
{
  double x = -0.0;
  if (0)
    { __builtin_abort (); }
  return 0;
}
/* ProgramSourceLLVM */
