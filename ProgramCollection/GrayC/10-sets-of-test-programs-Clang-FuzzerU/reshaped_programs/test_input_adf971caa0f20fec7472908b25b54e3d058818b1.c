#include <stdio.h>

typedef unsigned char u8;

struct S {
    u8 a, b;
    u8 c[2];
};

struct T {
    u8 s[16];
    u8 a;
};

struct U {
    u8 a;
    struct S s;
    u8 b;
    struct T t;
};

struct V {
    struct S s;
    struct T t;
    u8 a;
};

struct W {
    struct V t;
    struct S s[];
};

struct pkthdr {
    struct S saddr, daddr;
};

u8 global = 0;

struct Wrap {
    void (*func)(void);
};

void inc_global(void) {
    global++;
}

struct Wrap global_wrap[] = {
    {inc_global},
    {inc_global}
};

void print_(const char *name, const u8 *p, long size) {
    printf("%s:", name);
    while (size--) {
        printf(" %x", *p++);
    }
    printf("\n");
}

#define print(x) print_(#x, (u8*)&x, sizeof(x))

void foo(struct W *w, struct pkthdr *phdr_) {
    struct S ls = {1, 2, {3, 4}};
    struct T lt = {"hello", 42};
    struct U lu = {3, {5, 6, {7, 8}}, 4, {"huhu", 43}};
    const struct S *pls = &ls;
    struct S ls21 = *pls;
    struct pkthdr *phdr = phdr_;
    
    struct V lv2 = {(struct S)w->t.s, {"hihi", 47}, 48};

    print(ls);
    print(lt);
    print(lu);
    print(ls21);
    print(lv2);
}

void test_compound_with_relocs(void) {
    struct Wrap local_wrap[] = {
        {inc_global},
        {inc_global}
    };
    
    void (*p)(void);
    p = global_wrap[0].func;
    p();
}

int main() {
    struct W gw = {{{1, 2, {3, 4}}, {"hello", 42}, 5}, {{1, 2, {3, 4}}}};
    struct pkthdr phdr = { {1, 2, {3, 4}}, {1, 2, {3, 4}} };

    print(gw);
    print(phdr);
    foo(&gw, &phdr);

    test_compound_with_relocs();

    return 0;
}