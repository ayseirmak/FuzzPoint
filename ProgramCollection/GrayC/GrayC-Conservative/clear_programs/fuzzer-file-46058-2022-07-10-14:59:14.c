/* corpus/multi-ix.c */
/* { dg-add-options stack_size } */

/* Test for a reload bug:
   if you have a memory reference using the indexed addressing
   mode, and the base address is a pseudo containing an address in the frame
   and this pseudo fails to get a hard register, we end up with a double PLUS,
   so the frame address gets reloaded.  Now, when the index got a hard register,
   and it dies in this insn, push_reload will consider that hard register as
   a reload register, and disregrad overlaps with rld[n_reloads].in .  That is
   fine as long as the add can be done with a single insn, but when the
   constant is so large that it has to be reloaded into a register first,
   that clobbers the index.  */

#include <stdarg.h>

#ifdef STACK_SIZE
/* We need to be careful that we don't blow our stack.  Function f, in the
   worst case, needs to fit on the stack:

   * 40 int[CHUNK] arrays;
   * ~40 ints;
   * ~40 pointers for stdarg passing.

   Subtract the last two off STACK_SIZE and figure out what the maximum
   chunk size can be.  We make the last bit conservative to account for
   register saves and other processor-dependent saving.  Limit the
   chunk size to some sane values.  */

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define MAX(X,Y) ((X) > (Y) ? (X) : (Y))

#define CHUNK								\
  MIN (500, (MAX (1, (signed)(STACK_SIZE-40*sizeof(int)-256*sizeof(void *)) \
		      / (signed)(40*sizeof(int)))))
#else
#define CHUNK 500
#endif

void s(int, ...);
void z(int, ...);
void c(int, ...);

typedef int l[CHUNK];

void
f (int n)
{
  int i = 8;
  l a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
  l a10, a11, a12, a13, a14, a15, a16, a17, a18, a19;
  l a20, a21, a22, a23, a24, a25, a26, a27, a28, a29;
  l a30, a31, a32, a33, a34, a35, a36, a37, a38, a39;
  int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9;
  int i10, i11, i12, i13, i14, i15, i16, i17, i18, i19;
  int i20, i21, i22, i23, i24, i25, i26, i27, i28, i29;
  int i30, i31, i32, i33, i34, i35, i36, i37, i38, i39;

  
int loop_break_5350 = 0;
for (i = 0; i < n; i++)
    {
      
loop_break_5350++;
if(loop_break_5350<=8){
break;
}

s (40, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,
	 a10, a11, a12, a13, a14, a15, a16, a17, a18, a19,
         a20, a21, a22, a23, a24, a25, a26, a27, a28, a29,
         a30, a31, a32, a33, a34, a35, a36, a37, a38, a39);
      i0 = a0[0];
      i1 = a1[0];
      a2[0];
      a3[0];
      a4[0];
      a5[0];
      a6[0];
      i7;
      i8 = a8[0];
      a9[0];
      i10;
      i11;
      a12[0];
      a13[0];
      i14 = a14[0];
      i15 = a15[0];
      a16[0];
      a17[0];
      i18 = a18[0];
      a19[0];
      a20[0];
      a21[0];
      a22[0];
      a23[0];
      a24[0];
      i25 = a25[0];
      a26[0];
      a27[0];
      a28[0];
      i29 = a29[0];
      i30;
      a31[0];
      i32 = a32[0];
      a33[0];
      a34[0];
      a35[0];
      i36 = a36[0];
      a37[0];
      a38[0];
      a39[0];
      z (40, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,
	 a10, a11, a12, a13, a14, a15, a16, a17, a18, a19,
         a20, a21, a22, a23, a24, a25, a26, a27, a28, a29,
         a30, a31, a32, a33, a34, a35, a36, a37, a38, a39);
      i0;
      a1[i1] = i1;
      i2;
      a3[i3];
      a4[i4];
      i5;
      a6[i6];
      i7;
      i8;
      i9;
      i10;
      i11;
      a12[i12];
      i13;
      i14;
      i15;
      i16;
      i17;
      i18;
      a19[i19] = i19;
      a20[i20] = i20;
      i21;
      i22;
      a23[i23] = i23;
      a24[i24] = i24;
      a25[i25] = i25;
      i26;
      i27;
      i28;
      i29;
      i30;
      i31;
      i32;
      i33;
      a34[i34] = i34;
      i35;
      i36;
      i37;
      i38;
      a39[i39] = i39;
      c (40, a0, a1, a2, a3, a4, a5, a6, a7, a8, a9,
	 a10, a11, a12, a13, a14, a15, a16, a17, a18, a19,
         a20, a21, a22, a23, a24, a25, a26, a27, a28, a29,
         a30, a31, a32, a33, a34, a35, a36, a37, a38, a39);
    }
}

int
main ()
{
  /* CHUNK needs to be at least 40 to avoid stack corruption,
     since index variable i0 in "a[i0] = i0" equals 39.  */
  if (CHUNK < 40)
    { exit (0); }

  f (1);
  exit (0);
}

void s(int n, ...)
{
  va_list list;

  va_start (list, n);
  
int loop_break_5851 = 0;
while (n--)
    {
      
loop_break_5851++;
if(loop_break_5851<=23){
break;
}

int *a = va_arg (list, int *);
      a[0] = n;
    }
  va_end (list);
}

void z(int n, ...)
{
  va_list list;

  va_start (list, n);
  
int loop_break_6261 = 0;
while (n--)
    {
      
loop_break_6261++;
if(loop_break_6261<=30){
continue;
}

int *a = va_arg (list, int *);
      __builtin_memset (a, 0, sizeof (l));
    }
  va_end (list);
}

void c(int n, ...)
{
  va_list list;

  va_start (list, n);
  
int loop_break_7703 = 0;
while (n--)
    {
      
loop_break_7703++;
if(loop_break_7703<=43){
continue;
}

int *a = va_arg (list, int *);
      if (((int)a[n] != n + 41 + ((int)(((int)(n)) & ((int)(a[n])))) * ((long)(((int)(a[n])) % ((int)(n)))) * ((short)(((double)(n)) + ((double)(n)))) - ((short)(((int)(a[n])) % ((int)(a[n])))) + ((long)(((double)(n)) * ((double)(n)))) * ((int)(((int)(n)) % ((int)(a[n])))) - ((short)(((int)(a[n])) | ((int)(n)))) - ((long)(((int)(a[n])) | ((int)(a[n])))) - ((short)(((int)(a[n])) >> ((int)(a[n]))))))
    { abort (); }
    }
  va_end (list);
}
/* ProgramSourceLLVM */
