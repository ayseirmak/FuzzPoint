#include <stdio.h>
#include <string.h>

#ifndef MAX_OFFSET
#define MAX_OFFSET (sizeof(long long))
#endif

#ifndef MAX_COPY
#define MAX_COPY (10 * sizeof(long long))
#endif

#ifndef MAX_EXTRA
#define MAX_EXTRA (sizeof(long long))
#endif

#define MAX_LENGTH (MAX_OFFSET + MAX_COPY + MAX_EXTRA)

// Union for buffer
static union {
    char buf[MAX_LENGTH];
    long long align_int;
    long double align_fp;
} u;

int main() {
    int off, len, i;
    char *p, *q;
    char A = 'C';  // Fixed character for testing

    for (off = 0; off < MAX_OFFSET; off++) {
        for (len = 1; len < MAX_COPY; len++) {
            for (i = 0; i < MAX_LENGTH; i++)
                u.buf[i] = 'a';

            p = memset(u.buf + off, '\0', len);
            if (p != u.buf + off) {
                printf("Error: mismatched offset on null set\n");
                return 1;
            }

            q = u.buf;
            for (i = 0; i < off; i++, q++) {
                if (*q != 'a') {
                    printf("Error: incorrect character before offset\n");
                    return 1;
                }
            }

            for (i = 0; i < len; i++, q++) {
                if (*q != '\0') {
                    printf("Error: null character expected\n");
                    return 1;
                }
            }

            for (i = 0; i < MAX_EXTRA; i++, q++) {
                if (*q != 'a') {
                    printf("Error: incorrect character after length\n");
                    return 1;
                }
            }

            p = memset(u.buf + off, A, len);
            if (p != u.buf + off) {
                printf("Error: mismatched offset on character set\n");
                return 1;
            }

            q = u.buf;
            for (i = 0; i < off; i++, q++) {
                if (*q != 'a') {
                    printf("Error: incorrect character before offset (2nd check)\n");
                    return 1;
                }
            }

            for (i = 0; i < len; i++, q++) {
                if (*q != A) {
                    printf("Error: character %c expected\n", A);
                    return 1;
                }
            }

            for (i = 0; i < MAX_EXTRA; i++, q++) {
                if (*q != 'a') {
                    printf("Error: incorrect character after length (2nd check)\n");
                    return 1;
                }
            }

            p = memset(u.buf + off, 'B', len);
            if (p != u.buf + off) {
                printf("Error: mismatched offset on final character set\n");
                return 1;
            }

            q = u.buf;
            for (i = 0; i < off; i++, q++) {
                if (*q != 'a') {
                    printf("Error: incorrect character before offset (final check)\n");
                    return 1;
                }
            }

            for (i = 0; i < len; i++, q++) {
                if (*q != 'B') {
                    printf("Error: character 'B' expected\n");
                    return 1;
                }
            }

            for (i = 0; i < MAX_EXTRA; i++, q++) {
                if (*q != 'a') {
                    printf("Error: incorrect character after length (final check)\n");
                    return 1;
                }
            }
        }
    }

    printf("All checks passed successfully.\n");
    return 0;
}