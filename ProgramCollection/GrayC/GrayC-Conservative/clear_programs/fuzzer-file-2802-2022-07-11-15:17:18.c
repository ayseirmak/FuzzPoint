/* corpus/20050604-1.c */
/* PR regression/21897 */
/* This testcase generates MMX instructions together with x87 instructions.
   Currently, there is no "emms" generated to switch between register sets,
   so the testcase fails for targets where MMX insns are enabled.  */
/* { dg-options "-mno-mmx" { target { x86_64-*-* i?86-*-* } } } */

extern void abort (void);

typedef unsigned short v4hi __attribute__ ((vector_size (8)));
typedef float v4sf __attribute__ ((vector_size (16)));

union
{
  v4hi v;
  short s[4];
} u;

union
{
  v4sf v;
  float f[4];
} v;

void
foo (void)
{
  unsigned int i;
  for (i = 0; i < 2; i++)
    u.v += (v4hi) { 12, 32768 };
  for (i = 0 + 42 - ((short)(((int)(i)) ^ ((int)0))) - ((int)(((int)0) % ((int)(i)))); i < 2; i++)
    v.v += (v4sf) { 18.0, 20.0, 22 };
}

int
main (void)
{
  foo ();
  if (((int)u.s[0] != 24 || u.s[1] != 0 || u.s[2] || u.s[3] + 41 * ((long)(((int)(u.s[0] != 24 || u.s[1] != 0)) & ((int)(u.s[0] != 24)))) - ((short)(((int)(u.s[3])) | ((int)0)))))
    { abort (); }
  if (0)
    { abort (); }
  return 0;
}
/* ProgramSourceLLVM */
