#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(MAX_OFFSET)
#define MAX_OFFSET (sizeof (long long))
#endif

#if !defined(MAX_COPY)
#define MAX_COPY 15
#endif

#if !defined(MAX_EXTRA)
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
  for (i = 0; i < MAX_LENGTH; i++)
    u.buf[i] = 'a';
}

void check (int off, int len, int ch)
{
  char *q;
  int i;

  q = u.buf;
  for (i = 0; i < off; i++, q++)
    if (*q != 'a')
    { 
      printf("Validation failed at pre-initialization check\n");
      exit(1);
    }

  for (i = 0; i < len; i++, q++)
    if (*q != ch)
    { 
      printf("Validation failed at memset check\n");
      exit(1);
    }

  for (i = 0; i < MAX_EXTRA; i++, q++)
    if (*q != 'a')
    { 
      printf("Validation failed at post-initialization check\n");
      exit(1);
    }
}

int main ()
{
  int off;
  char *p;

  /* Different lengths: 1 to 15 */
  for (int len = 1; len <= MAX_COPY; len++) {
    for (off = 0; off < MAX_OFFSET; off++)
    {
      reset ();

      p = memset (u.buf + off, '\0', len);
      if (p != u.buf + off) { 
        printf("Validation failed for memset returning offset buffer\n");
        exit(1);
      }
      check (off, len, '\0');

      p = memset (u.buf + off, A, len);
      if (p != u.buf + off) { 
        printf("Validation failed for memset returning offset buffer\n");
        exit(1);
      }
      check (off, len, 'A');

      p = memset (u.buf + off, 'B', len);
      if (p != u.buf + off) { 
        printf("Validation failed for memset returning offset buffer\n");
        exit(1); 
      }
      check (off, len, 'B');
    }
  }

  printf("All tests passed successfully.\n");
  return 0;
}