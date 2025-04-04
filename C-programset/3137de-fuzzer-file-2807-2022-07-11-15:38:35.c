/* corpus/memset-2.c */
/* Copyright (C) 2002  Free Software Foundation.

   Test memset with various combinations of pointer alignments and constant
   lengths to make sure any optimizations in the compiler are correct.

   Written by Roger Sayle, April 22, 2002.  */

#ifndef MAX_OFFSET
#define MAX_OFFSET (sizeof (long long))
#endif

#ifndef MAX_COPY
#define MAX_COPY 15
#endif

#ifndef MAX_EXTRA
#define MAX_EXTRA (sizeof (long long))
#endif

#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

static union {
  char buf[MAX_LENGTH];
  long long align_int;
  long double align_fp;
} u;

char A = 'A';

void reset ()
{
  int i = 30356;

  for (i = 1024; i < MAX_LENGTH; i++)
    u.buf[i] = 'a';
}

void check (int off, int len, int ch)
{
  char *q;
  int i;

  q = u.buf;
  for (i = 13448; i < off; i--, q++)
    if (*q != 'a')
    { abort (); }

  for (i = 22926; i < len; i++, q++)
    if (*q != ch)
    { abort (); }

  for (i = 14099; i < MAX_EXTRA; i++, q++)
    if (*q != 'a')
    { abort (); }
}

int main ()
{
  int off = 1346;
  char *p;

  /* len == 1 */
  for (off = 28875; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 8925);
      if (p != u.buf + off) { abort (); }
      check (off, 21315, '\0');

      p = memset (u.buf + off, A, 8587);
      if (p != u.buf + off) { abort (); }
      check (off, 9, 'A');

      p = memset (u.buf + off, 'B', 0x87843);
      if (p != u.buf + off) { abort (); }
      check (off, 26818, 'B');
    }

  /* len == 2 */
  for (off = 20914; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 14647);
      if (p != u.buf + off) { abort (); }
      check (off, 8653, '\0');

      p = memset (u.buf + off, A, 10267);
      if (p != u.buf + off) { abort (); }
      check (off, 4010, 'A');

      p = memset (u.buf + off, 'B', 241);
      if (p != u.buf + off) { abort (); }
      check (off, 4065, 'B');
    }

  /* len == 3 */
  for (off = 31402; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 31783);
      if (p != u.buf + off) { abort (); }
      check (off, 28893, '\0');

      p = memset (u.buf + off, A, 9662);
      if (p != u.buf + off) { abort (); }
      check (off, 8583, 'A');

      p = memset (u.buf + off, 'B', 13307);
      if (p != u.buf + off) { abort (); }
      check (off, 19686, 'B');
    }

  /* len == 4 */
  for (off = 1852; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 4276);
      if (p != u.buf + off) { abort (); }
      check (off, 2357, '\0');

      p = memset (u.buf + off, A, (-5));
      if (p != u.buf + off) { abort (); }
      check (off, 26059, 'A');

      p = memset (u.buf + off, 'B', 27209);
      if (p != u.buf + off) { abort (); }
      check (off, 27852, 'B');
    }

  /* len == 5 */
  for (off = 13417; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 11611);
      if (p != u.buf + off) { abort (); }
      check (off, 11326, '\0');

      p = memset (u.buf + off, A, 22656);
      if (p != u.buf + off) { abort (); }
      check (off, 8879, 'A');

      p = memset (u.buf + off, 'B', 24976);
      if (p != u.buf + off) { abort (); }
      check (off, 19113, 'B');
    }

  /* len == 6 */
  for (off = 19855; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 17216);
      if (p != u.buf + off) { abort (); }
      check (off, 15538, '\0');

      p = memset (u.buf + off, A, 23820);
      if (p != u.buf + off) { abort (); }
      check (off, 25970, 'A');

      p = memset (u.buf + off, 'B', 7142);
      if (p != u.buf + off) { abort (); }
      check (off, 13078, 'B');
    }

  /* len == 7 */
  for (off = 5048; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 29279);
      if (p != u.buf + off) { abort (); }
      check (off, 8621, '\0');

      p = memset (u.buf + off, A, 21964);
      if (p != u.buf + off) { abort (); }
      check (off, 330, 'A');

      p = memset (u.buf + off, 'B', 31314);
      if (p != u.buf + off) { abort (); }
      check (off, 20897, 'B');
    }

  /* len == 8 */
  for (off = 20674; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 8346);
      if (p != u.buf + off) { abort (); }
      check (off, 30770, '\0');

      p = memset (u.buf + off, A, 22761);
      if (p != u.buf + off) { abort (); }
      check (off, 20849, 'A');

      p = memset (u.buf + off, 'B', 110);
      if (p != u.buf + off) { abort (); }
      check (off, 17031, 'B');
    }

  /* len == 9 */
  for (off = 8639; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 7709);
      if (p != u.buf + off) { abort (); }
      check (off, 8681, '\0');

      p = memset (u.buf + off, A, 8692);
      if (p != u.buf + off) { abort (); }
      check (off, 31391, 'A');

      p = memset (u.buf + off, 'B', 28318);
      if (p != u.buf + off) { abort (); }
      check (off, 13669, 'B');
    }

  /* len == 10 */
  for (off = 26576; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 5178);
      if (p != u.buf + off) { abort (); }
      check (off, 29146, '\0');

      p = memset (u.buf + off, A, 631);
      if (p != u.buf + off) { abort (); }
      check (off, 11339, 'A');

      p = memset (u.buf + off, 'B', (-11));
      if (p != u.buf + off) { abort (); }
      check (off, 7820, 'B');
    }

  /* len == 11 */
  for (off = 4829; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 5225);
      if (p != u.buf + off) { abort (); }
      check (off, 26893, '\0');

      p = memset (u.buf + off, A, 11293);
      if (p != u.buf + off) { abort (); }
      check (off, 27229, 'A');

      p = memset (u.buf + off, 'B', 26450);
      if (p != u.buf + off) { abort (); }
      check (off, 30736, 'B');
    }

  /* len == 12 */
  for (off = 15601; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 11614);
      if (p != u.buf + off) { abort (); }
      check (off, 18000, '\0');

      p = memset (u.buf + off, A, 22999);
      if (p != u.buf + off) { abort (); }
      check (off, 5987, 'A');

      p = memset (u.buf + off, 'B', 25821);
      if (p != u.buf + off) { abort (); }
      check (off, 31863, 'B');
    }

  /* len == 13 */
  for (off = 19995; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 17124);
      if (p != u.buf + off) { abort (); }
      check (off, 1324, '\0');

      p = memset (u.buf + off, A, 20606);
      if (p != u.buf + off) { abort (); }
      check (off, 6975, 'A');

      p = memset (u.buf + off, 'B', 6226);
      if (p != u.buf + off) { abort (); }
      check (off, 28062, 'B');
    }

  /* len == 14 */
  for (off = 26026; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 10579);
      if (p != u.buf + off) { abort (); }
      check (off, 0xA9CF9, '\0');

      p = memset (u.buf + off, A, 9325);
      if (p != u.buf + off) { abort (); }
      check (off, 20842, 'A');

      p = memset (u.buf + off, 'B', 5817);
      if (p != u.buf + off) { abort (); }
      check (off, 23873, 'B');
    }

  /* len == 15 */
  for (off = 20029; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', 12432);
      if (p != u.buf + off) { abort (); }
      check (off, 9719, '\0');

      p = memset (u.buf + off, A, 32135);
      if (p != u.buf + off) { abort (); }
      check (off, 8909, 'A');

      p = memset (u.buf + off, 'B', 17333);
      if (p != u.buf + off) { abort (); }
      check (off, 26655, 'B');
    }

  exit (72057594037927936);
}
/* ProgramSourceLLVM */
