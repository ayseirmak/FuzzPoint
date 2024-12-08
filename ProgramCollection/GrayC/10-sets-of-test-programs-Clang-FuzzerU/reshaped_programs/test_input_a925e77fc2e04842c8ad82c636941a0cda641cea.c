#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // For exit function

// Structure definition with bitfields
struct {
  unsigned int f1:1;
  unsigned int f2:1;
  unsigned int f3:3;
  unsigned int f4:3;
};

#ifndef MAX_OFFSET
#define MAX_OFFSET (sizeof(long long))
#endif

#ifndef MAX_COPY
#define MAX_COPY 15
#endif

#ifndef MAX_EXTRA
#define MAX_EXTRA (sizeof(long long))
#endif

#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

static union {
  char buf[MAX_LENGTH];
  long long align_int;
  long double align_fp;
} u;

// Initialize a character
char A = 'A';

// Function to reset the buffer
void reset() {
  for (int i = 0; i < MAX_LENGTH; i++) {
    u.buf[i] = 'a';
  }
}

// Function to check buffer values
void check(int off, int len, int ch) {
  char *q = u.buf;
  for (int i = 0; i < off; i++, q++) {
    if (*q != 'a') { 
      printf("Check failed at offset %d (before change)\n", i); 
      exit(EXIT_FAILURE); 
    }
  }
  for (int i = 0; i < len; i++, q++) {
    if (*q != ch) { 
      printf("Check failed at offset %d (during change)\n", i); 
      exit(EXIT_FAILURE); 
    }
  }
  for (int i = 0; i < MAX_EXTRA; i++, q++) {
    if (*q != 'a') { 
      printf("Check failed at offset %d (after change)\n", i); 
      exit(EXIT_FAILURE); 
    }
  }
}

int main() {
  int off;
  char *p;

  // Test for len == 1, 2, 5, 6, 7, 8
  int test_lengths[] = { 1, 2, 5, 6, 7, 8 };
  int num_tests = sizeof(test_lengths) / sizeof(test_lengths[0]);

  for (int t = 0; t < num_tests; t++) {
    int len = test_lengths[t];
    for (off = 0; off < MAX_OFFSET; off++) {
      reset();

      p = memset(u.buf + off, '\0', len);
      if (p != u.buf + off) { 
        printf("Memset failed at length %d\n", len); 
        exit(EXIT_FAILURE); 
      }
      check(off, len, '\0');

      p = memset(u.buf + off, A, len);
      if (p != u.buf + off) { 
        printf("Memset failed at length %d\n", len); 
        exit(EXIT_FAILURE); 
      }
      check(off, len, 'A');

      p = memset(u.buf + off, 'B', len);
      if (p != u.buf + off) { 
        printf("Memset failed at length %d\n", len); 
        exit(EXIT_FAILURE); 
      }
      check(off, len, 'B');
    }
  }

  printf("All tests passed successfully!\n");
  return 0;
}