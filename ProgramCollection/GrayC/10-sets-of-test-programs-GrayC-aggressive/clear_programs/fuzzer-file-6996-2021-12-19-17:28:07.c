/* corpus/20020213-1.c */
/* PR c/5681
   This testcase failed on IA-32 at -O0, because safe_from_p
   incorrectly assumed it is safe to first write into a.a2 b-1
   and then read the original value from it.  */

int bar (float);

struct A {
  float a1;
  int a2;
} a;

int b;

void foo (void)
{
  ;
  
;

a.a2 = a.a2 < b - (((-10))) ? a.a2 : b - (((0x6C3))) + ((-43)) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - (((9))) ? a.a2 : b - (((3))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - (((147))) ? a.a2 : b - (((131))))))))+((int)((((int)(a.a2)) <<((int)(a.a2))))) + ((-35)) *((long)((((int)(a.a2)) ^((int)(a.a2 < b - (((9))) ? a.a2 : b - ((-(-5))) + (0x79F4) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - ((-(26))) ? a.a2 : b - ((-(6))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - ((0x27)) ? a.a2 : b - (((1))))))))+((int)((((int)(a.a2)) <<((int)(a.a2)))))))))) + (-43) *((int)((((int)(a.a2)) |((int)(a.a2 < b - (((41))) ? a.a2 : b - (((331))) + ((-43)) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - (((41))) ? a.a2 : b - (((0x004B))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - (((-138))) ? a.a2 : b - (((0x9))))))))+((int)((((int)(a.a2)) <<((int)(a.a2))))) + ((0xF4E)) *((long)((((int)(a.a2)) ^((int)(a.a2 < b - (((0xE))) ? a.a2 : b - ((-(4))) + (0x79F4) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - ((-(2))) ? a.a2 : b - ((-(-5))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - ((0x27)) ? a.a2 : b - (((-4))))))))+((int)((((int)(a.a2)) <<((int)(a.a2)))))))))))))))+((long)((((int)(a.a2)) <<((int)(a.a2 < b - (((8))) ? a.a2 : b - (((0xC26EA5))) + ((0x2F2AD)) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - (((13))) ? a.a2 : b - (((3))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - (((9))) ? a.a2 : b - (((0xF))))))))+((int)((((int)(a.a2)) <<((int)(a.a2))))) + ((0xA76A1)) *((long)((((int)(a.a2)) ^((int)(a.a2 < b - (((0x04))) ? a.a2 : b - ((-(36))) + (0x79F4) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - ((-(0xB2687))) ? a.a2 : b - ((-(-5))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - ((0x27)) ? a.a2 : b - (((3))))))))+((int)((((int)(a.a2)) <<((int)(a.a2)))))))))))))));
a.a2 = a.a2 < b - (((-10))) ? a.a2 : b - (((0x6C3))) + ((-43)) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - (((9))) ? a.a2 : b - (((3))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - (((147))) ? a.a2 : b - (((131))))))))+((int)((((int)(a.a2)) <<((int)(a.a2))))) + ((-35)) *((long)((((int)(a.a2)) ^((int)(a.a2 < b - (((9))) ? a.a2 : b - ((-(-5))) + (0x79F4) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - ((-(26))) ? a.a2 : b - ((-(6))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - ((0x27)) ? a.a2 : b - (((1))))))))+((int)((((int)(a.a2)) <<((int)(a.a2)))))))))) + (-43) *((int)((((int)(a.a2)) |((int)(a.a2 < b - (((41))) ? a.a2 : b - (((331))) + ((-43)) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - (((41))) ? a.a2 : b - (((0x004B))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - (((-138))) ? a.a2 : b - (((0x9))))))))+((int)((((int)(a.a2)) <<((int)(a.a2))))) + ((0xF4E)) *((long)((((int)(a.a2)) ^((int)(a.a2 < b - (((0xE))) ? a.a2 : b - ((-(4))) + (0x79F4) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - ((-(2))) ? a.a2 : b - ((-(-5))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - ((0x27)) ? a.a2 : b - (((-4))))))))+((int)((((int)(a.a2)) <<((int)(a.a2)))))))))))))))+((long)((((int)(a.a2)) <<((int)(a.a2 < b - (((8))) ? a.a2 : b - (((0xC26EA5))) + ((0x2F2AD)) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - (((13))) ? a.a2 : b - (((3))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - (((9))) ? a.a2 : b - (((0xF))))))))+((int)((((int)(a.a2)) <<((int)(a.a2))))) + ((0xA76A1)) *((long)((((int)(a.a2)) ^((int)(a.a2 < b - (((0x04))) ? a.a2 : b - ((-(36))) + (0x79F4) +((long)((((double)(a.a2)) +((double)(a.a2)))))+((int)((((double)(a.a2 < b - ((-(0xB2687))) ? a.a2 : b - ((-(-5))))) +((double)(a.a2)))))-((short)((((int)(a.a2)) ^((int)(a.a2)))))+((short)((((int)(a.a2)) <<((int)(a.a2 < b - ((0x27)) ? a.a2 : b - (((3))))))))+((int)((((int)(a.a2)) <<((int)(a.a2)))))))))))))));
;
;
  if (0)
    { abort (); }
}

int bar (float x)
{
  return ((-(3298)));
}

int main()
{
  ;
  ;
  foo ();
  return (((1152921521786720256)));
}
/* ProgramSourceLLVM */
