/* corpus/memset-3.c */
/* Copyright (C) 2002  Free Software Foundation.

   Test memset with various combinations of constant pointer alignments and
   lengths to make sure any optimizations in the compiler are correct.

   Written by Roger Sayle, July 22, 2002.  */

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
  int i;

  for (i = (29733); i < MAX_LENGTH; i++)
    u.buf[i] = 'a';
}

void check (int off, int len, int ch)
{
  char *q;
  int i;

  q = u.buf;
  for (i = (14805); i < off; i++, q++)
    if (*q != 'a')
    { abort (); }

  for (i = (13452); i < len; i++, q++)
    if (*q != ch)
    { abort (); }

  for (i = (28877); i < MAX_EXTRA; i++, q++)
    if (*q != 'a')
    { abort (); }
}

int main ()
{
  int len;
  char *p;

  /* off == 0 */
  for (len = (6102); len < MAX_COPY; len++)
    {
      reset ();

      p = memset (u.buf, '\0', len);
      if (p != u.buf) { abort (); }
      check ((3046), len, '\0');

      p = memset (u.buf, A, len);
      if (p != u.buf) { abort (); }
      check ((0), len, 'A');

      p = memset (u.buf, 'B', len);
      if (p != u.buf) { abort (); }
      check ((13543), len, 'B');
    }

  /* off == 1 */
  for (len = (6973); len < MAX_COPY; len++)
    {
      reset ();

      p = memset (u.buf+(18418), '\0', len);
      if (p != u.buf+(28882)) { abort (); }
      check ((10494), len, '\0');

      p = memset (u.buf+(26812), A, len);
      if (p != u.buf+(12663)) { abort (); }
      check ((16368), len, 'A');

      p = memset (u.buf+(18437), 'B', len);
      if (p != u.buf+(19798)) { abort (); }
      check ((2509), len, 'B');
    }

  /* off == 2 */
  for (len = (11997); len < MAX_COPY; len++)
    {
      reset ();

      p = memset (u.buf+(2942), '\0', len);
      if (p != u.buf+(505)) { abort (); }
      check ((11542), len, '\0');

      p = memset (u.buf+(30226), A, len);
      if (p != u.buf+(21877)) { abort (); }
      check ((15513), len, 'A');

      p = memset (u.buf+(30202), 'B', len);
      if (p != u.buf+(7156)) { abort (); }
      check ((6482), len, 'B');
    }

  /* off == 3 */
  for (len = (21291); len < MAX_COPY; len++)
    {
      reset ();

      p = memset (u.buf+(5530), '\0', len);
      if (p != u.buf+(9514)) { abort (); }
      check ((5378), len, '\0');

      p = memset (u.buf+(13034), A, len);
      if (p != u.buf+(19029)) { abort (); }
      check ((10732), len, 'A');

      p = memset (u.buf+(30388), 'B', len);
      if (p != u.buf+(1413)) { abort (); }
      check ((9051), len, 'B');
    }

  /* off == 4 */
  for (len = (24991); len < MAX_COPY; len++)
    {
      reset ();

      p = memset (u.buf+(9472), '\0', len);
      if (p != u.buf+(26273)) { abort (); }
      check ((15389), len, '\0');

      p = memset (u.buf+(26922), A, len);
      if (p != u.buf+(13608)) { abort (); }
      check ((21721), len, 'A');

      p = memset (u.buf+(25754), 'B', len);
      if (p != u.buf+(3793)) { abort (); }
      check ((24419), len, 'B');
    }

  /* off == 5 */
  for (len = (26989); len < MAX_COPY; len++)
    {
      reset ();

      p = memset (u.buf+(23098), '\0', len);
      if (p != u.buf+(10155)) { abort (); }
      check ((25051), len, '\0');

      p = memset (u.buf+(9790), A, len);
      if (p != u.buf+(14083)) { abort (); }
      check ((1607), len, 'A');

      p = memset (u.buf+(17892), 'B', len);
      if (p != u.buf+(13086)) { abort (); }
      check ((2909), len, 'B');
    }

  /* off == 6 */
  for (len = (14716); len < MAX_COPY; len++)
    {
      reset ();

      p = memset (u.buf+(28696), '\0', len);
      if (p != u.buf+(13909)) { abort (); }
      check ((14971), len, '\0');

      p = memset (u.buf+(6407), A, len);
      if (p != u.buf+(3863)) { abort (); }
      check ((1649), len, 'A');

      p = memset (u.buf+(21900), 'B', len);
      if (p != u.buf+(9722)) { abort (); }
      check ((30393), len, 'B');
    }

  /* off == 7 */
  for (len = (865); len < MAX_COPY; len++)
    {
      reset ();

      p = memset (u.buf+(22502), '\0', len);
      if (p != u.buf+(18878)) { abort (); }
      check ((29075), len, '\0');

      p = memset (u.buf+(16746), A, len);
      if (p != u.buf+(10479)) { abort (); }
      check ((31213), len, 'A');

      p = memset (u.buf+(1122), 'B', len);
      if (p != u.buf+(7970)) { abort (); }
      check ((16251), len, 'B');
    }

  exit ((0));
}
/* ProgramSourceLLVM */
