#include <stdio.h>
#include <stdlib.h>

struct S { 
    unsigned int u[4]; 
};

void foo(struct S *out, const struct S *in, int shift) {
    unsigned long long th, tl, oh, ol;

    // Calculate high and low parts
    th = ((unsigned long long) in->u[3] << 32) | in->u[2];
    tl = ((unsigned long long) in->u[1] << 32) | in->u[0];

    // Shift operations
    oh = th >> (shift * 8);
    ol = tl >> (shift * 8);
    ol |= th << (64 - shift * 8);

    // Store results in output structure
    out->u[1] = ol >> 32;
    out->u[0] = ol;
    out->u[3] = oh >> 32;
    out->u[2] = oh;
}

void bar(struct S *out, const struct S *in, int shift) {
    unsigned long long th, tl, oh, ol;

    // Calculate high and low parts
    th = ((unsigned long long) in->u[3] << 32) | in->u[2];
    tl = ((unsigned long long) in->u[1] << 32) | in->u[0];

    // Shift operations
    oh = th << (shift * 8);
    ol = tl << (shift * 8);
    oh |= tl >> (64 - shift * 8);

    // Store results in output structure
    out->u[1] = ol >> 32;
    out->u[0] = ol;
    out->u[3] = oh >> 32;
    out->u[2] = oh;
}

void baz(struct S *r, struct S *a, struct S *b, struct S *c, struct S *d) {
    struct S x, y;

    // Use bar and foo functions
    bar(&x, a, 1);
    foo(&y, c, 1);

    // XOR operations with shifts and masks
    r->u[0] = a->u[0] ^ x.u[0] ^ ((b->u[0] >> 11) & 0xdfffffef) ^ y.u[0] ^ (d->u[0] << 18);
    r->u[1] = a->u[1] ^ x.u[1] ^ ((b->u[1] >> 11) & 0xddfecb7f) ^ y.u[1] ^ (d->u[1] << 18);
    r->u[2] = a->u[2] ^ x.u[2] ^ ((b->u[2] >> 11) & 0xbffaffff) ^ y.u[2] ^ (d->u[2] << 18);
    r->u[3] = a->u[3] ^ x.u[3] ^ ((b->u[3] >> 11) & 0xbffffff6) ^ y.u[3] ^ (d->u[3] << 18);
}

int main(void) {
    if (sizeof(int) == 4 && sizeof(long long) == 8 && __CHAR_BIT__ == 8) {
        struct S a[] = {
            {0x000004d3, 0xbc5448db, 0xf22bde9f, 0xebb44f8f},
            {0x03a32799, 0x60be8246, 0xa2d266ed, 0x7aa18536},
            {0x15a38518, 0xcf655ce1, 0xf3e09994, 0x50ef69fe},
            {0x88274b07, 0xe7c94866, 0xc0ea9f47, 0xb6a83c43},
            {0xcd0d0032, 0x5d47f5d7, 0x5afbf6, 0xaea87b24},
            {0, 0, 0, 0}
        };

        baz(&a[5], &a[0], &a[1], &a[2], &a[3]);

        // Verification
        if (a[4].u[0] != a[5].u[0] || a[4].u[1] != a[5].u[1] ||
            a[4].u[2] != a[5].u[2] || a[4].u[3] != a[5].u[3]) {
            abort();
        }
    }
    return 0;
}