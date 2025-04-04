#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef MAX_OFFSET
#define MAX_OFFSET (sizeof(long long))
#endif

#ifndef MAX_COPY
#define MAX_COPY (10 * sizeof(long long))
#endif

#ifndef MAX_EXTRA
#define MAX_EXTRA (sizeof(long long))
#endif

#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + 1 + MAX_EXTRA)
#define SEQUENCE_LENGTH 31

static union {
  char buf[MAX_LENGTH];
  long long align_int;
  long double align_fp;
} u1, u2;

int main(void) {
  int off1, off2, len, i;
  char *p, *q, c;

  for (off1 = 0; off1 < MAX_OFFSET; off1++) {
    for (off2 = 0; off2 < MAX_OFFSET; off2++) {
      for (len = 1; len < MAX_COPY; len++) {
        for (i = 0, c = 'A'; i < MAX_LENGTH; i++, c++) {
          u1.buf[i] = 'a';
          if (c >= 'A' + SEQUENCE_LENGTH) 
            c = 'A';
          u2.buf[i] = c;
        }
        u2.buf[off2 + len] = '\0';

        p = strcpy(u1.buf + off1, u2.buf + off2);
        assert(p == u1.buf + off1);

        q = u1.buf;
        for (i = 0; i < off1; i++, q++) {
          assert(*q == 'a');
        }

        for (i = 0, c = 'A' + off2; i < len; i++, q++, c++) {
          if (c >= 'A' + SEQUENCE_LENGTH)
            c = 'A';
          assert(*q == c);
        }

        assert(*q++ == '\0');
        
        for (i = 0; i < MAX_EXTRA; i++, q++) {
          assert(*q == 'a');
        }
      }
    }
  }

  return 0;
}