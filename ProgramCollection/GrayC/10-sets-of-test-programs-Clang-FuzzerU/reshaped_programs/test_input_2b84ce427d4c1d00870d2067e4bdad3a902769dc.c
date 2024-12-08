#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void check(const char *type, int align) {
    if ((align & -align) != align) {
        abort();
    }
}

int main() {
    int x = 6;
    int y = 1;
    char *bar = "hi world";
    char buf[64];
    char dst[64];
    const char *const foo = "hello world";

    if (strlen(bar) != 8) {
        abort();
    }
    if (strlen(bar + (++x & 2)) != 6) {
        abort();
    }
    if (x != 7) {
        abort();
    }
    if (strchr(bar, 'o') != bar + 4) {
        abort();
    }
    if (strchr(bar, '\0') != bar + 8) {
        abort();
    }
    if (strrchr(bar, 'x')) {
        abort();
    }
    if (strrchr(bar, 'o') != bar + 4) {
        abort();
    }
    if (strcmp(foo + (x++ & 1), "ello world" + (--y & 1))) {
        abort();
    }
    if (x != 6 || y != 0) {
        abort();
    }
    dst[5] = ' ';
    dst[6] = '\0';
    x = 5;
    y = 1;
    if (strncpy(dst + 1, foo + (x++ & 3), 4) != dst + 1 || x != 6 || strcmp(dst + 1, "ello ")) {
        abort();
    }
    memset(dst, ' ', sizeof(dst));
    if (strncpy(dst + (++x & 1), (y++ & 3) + "foo", 10) != dst + 1 || x != 7 || y != 2 || memcmp(dst, " oo\0\0\0\0\0\0\0\0 ", 12)) {
        abort();
    }
    memset(dst, ' ', sizeof(dst));
    if (strncpy(dst, "hello", 8) != dst || memcmp(dst, "hello\0\0\0 ", 9)) {
        abort();
    }
    x = '!';
    memset(buf, ' ', sizeof(buf));
    if (memset(buf, x++, ++y) != buf || x != '!' + 1 || y != 3 || memcmp(buf, "!!!", 3)) {
        abort();
    }
    if (memset(buf + y++, '-', 8) != buf + 3 || y != 4 || memcmp(buf, "!!!--------", 11)) {
        abort();
    }
    x = 10;
    if (memset(buf + ++x, 0, y++) != buf + 11 || x != 11 || y != 5 || memcmp(buf + 8, "---\0\0\0", 7)) {
        abort();
    }
    if (memset(buf + *(x += 4), 0, 6) != buf + 15 || x != 15 || memcmp(buf + 10, "-\0\0\0\0\0\0\0\0\0", 11)) {
        abort();
    }

    return 0;
}