/* corpus/20081103-1.c */
struct S { char c; char arr[(0x1B)]; float f; };

char A[(4)] = { '1', '2', '3', '4' };

void foo (struct S s)
{
  if (__builtin_memcmp (s.arr, A, (4)))
    { __builtin_abort (); }
}

int main (void)
{
  struct S s;
  __builtin_memcpy (s.arr, A, (4));
  foo (s);
  return (0);
}
/* ProgramSourceLLVM */
