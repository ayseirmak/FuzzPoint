#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
float fx(float x);
unsigned long long Sum(struct Struct3* instrs);
long long Sum2(struct Struct3* instrs);
float inita();
float initc();

// Define Struct1
typedef struct {
    short a;
    unsigned short b;
    unsigned short c;
    unsigned long long Count;
    long long Count2;
} __attribute__((packed)) Struct1;

// Define Struct2
typedef struct {
    short a;
    unsigned short b;
    unsigned short c;
    unsigned long long d;
    long long e;
    long long f;
} __attribute__((packed)) Struct2;

// Define Union
typedef union {
    Struct1 a;
    Struct2 b;
} Union;

// Define Struct3
typedef struct {
    int Count;
    Union List[0];
} __attribute__((packed)) Struct3;

// Function implementations
float fx(float x) {
    return 1.0 + 3.0 / (2.302585093 * x);
}

unsigned long long Sum(Struct3* instrs) {
    unsigned long long count = 0;
    for (int i = 0; i < instrs->Count; i++) {
        count += instrs->List[i].a.Count;
    }
    return count;
}

long long Sum2(Struct3* instrs) {
    long long count = 0;
    for (int i = 0; i < instrs->Count; i++) {
        count += instrs->List[i].a.Count2;
    }
    return count;
}

float inita() {
    return 3.0;
}

float initc() {
    return 4.0;
}

int main() {
    float a, b, c;
    a = inita();
    c = initc();
    b = fx(c) + a;

    if (a != 3.0 || b < 4.3257 || b > 4.3258 || c != 4.0) {
        printf("Abort due to condition\n");
        exit(EXIT_FAILURE);
    }

    Struct3* p = malloc(sizeof(int) + 3 * sizeof(Union));
    memset(p, 0, sizeof(int) + 3 * sizeof(Union));
    p->Count = 3;
    p->List[0].a.Count = 555;
    p->List[1].a.Count = 999;
    p->List[2].a.Count = 0x101010101ULL;
    p->List[0].a.Count2 = 555;
    p->List[1].a.Count2 = 999;
    p->List[2].a.Count2 = 0x101010101LL;

    if (Sum(p) != 555 + 999 + 0x101010101ULL) {
        printf("Abort due to Sum mismatch\n");
        exit(EXIT_FAILURE);
    }

    if (Sum2(p) != 555 + 999 + 0x101010101LL) {
        printf("Abort due to Sum2 mismatch\n");
        exit(EXIT_FAILURE);
    }

    free(p);
    return 0;
}