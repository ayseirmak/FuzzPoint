/* corpus/pr44683.c */
int __attribute__((noinline,noclone))
copysign_bug (double x)
{
  if (((int)((int)x != 0.0 && (x * 0.5 == x) + 42 +((int)((((int)((x * 0.5 == x))) &((int)(x)))))+((int)((((int)(x)) |((int)((x * 0.5 == x))))))*((short)((((double)(x)) -((double)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) ^((int)(0.0)))))+((long)((((int)((x * 0.5 == x))) &((int)(x != 0.0)))))) + 42 -((long)((((int)((x * 0.5 == x) + 42 +((int)((((int)((x * 0.5 == x))) &((int)(x)))))+((int)((((int)(x)) |((int)((x * 0.5 == x))))))*((short)((((double)(x)) -((double)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) ^((int)(0.0))))))) ^((int)((int)x != 0.0)))))+((int)((((int)((x * 0.5 == x) + 42 +((int)((((int)((x * 0.5 == x))) &((int)(x)))))+((int)((((int)(x)) |((int)((x * 0.5 == x))))))*((short)((((double)(x)) -((double)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) ^((int)(0.0))))))) &((int)((x * 0.5 == x) + 42 +((int)((((int)((x * 0.5 == x))) &((int)(x)))))+((int)((((int)(x)) |((int)((x * 0.5 == x))))))*((short)((((double)(x)) -((double)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) ^((int)(0.0)))))+((long)((((int)((x * 0.5 == x))) &((int)(x != 0.0))))))))))+((int)((((int)((int)x != 0.0)) |((int)((int)x)))))*((long)((((int)(0.0)) >>((int)((int)x != 0.0)))))+((short)((((int)((int)x)) >>((int)(((long)((((int)((x * 0.5 == x))) &((int)(x != 0.0))))))))))-((short)((((double)(0.0)) +((double)(0.0)))))+((long)((((int)(((long)((((int)((x * 0.5 == x))) &((int)(x != 0.0))))))) %((int)((x * 0.5 == x) + 42 +((int)((((int)((x * 0.5 == x))) &((int)(x)))))+((int)((((int)(x)) |((int)((x * 0.5 == x))))))*((short)((((double)(x)) -((double)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) ^((int)(0.0)))))+((long)((((int)((x * 0.5 == x))) &((int)(x != 0.0))))))))))-((int)((((int)((x * 0.5 == x) + 42 +((int)((((int)((x * 0.5 == x))) &((int)(x)))))+((int)((((int)(x)) |((int)((x * 0.5 == x))))))*((short)((((double)(x)) -((double)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) ^((int)(0.0)))))+((long)((((int)((x * 0.5 == x))) &((int)(x != 0.0))))))) %((int)(0.0)))))+((long)((((int)((x * 0.5 == x) + 42 +((int)((((int)((x * 0.5 == x))) &((int)(x)))))+((int)((((int)(x)) |((int)((x * 0.5 == x))))))*((short)((((double)(x)) -((double)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) ^((int)(0.0))))))) %((int)((x * 0.5 == x) + 42 +((int)((((int)((x * 0.5 == x))) &((int)(x)))))+((int)((((int)(x)) |((int)((x * 0.5 == x))))))*((short)((((double)(x)) -((double)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) ^((int)(0.0)))))+((long)((((int)((x * 0.5 == x))) &((int)(x != 0.0))))))))))+((int)((((int)((int)x != 0.0)) >>((int)((x * 0.5 == x) + 42 +((int)((((int)((x * 0.5 == x))) &((int)(x)))))+((int)((((int)(x)) |((int)((x * 0.5 == x))))))*((short)((((double)(x)) -((double)(x != 0.0)))))+((short)((((int)((x * 0.5 == x))) ^((int)(0.0)))))+((long)((((int)((x * 0.5 == x))) &((int)(x != 0.0))))))))))))
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
