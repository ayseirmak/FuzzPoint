#include <stdio.h>
#include <string.h>

// Structures and unions
struct task_struct {
  char comm[16];
};

union task_union {
  struct task_struct task;
  unsigned long stack[2048];
};

union task_union init_task_union = { .task = { .comm = "swapper" } };

struct inflate_huft_s {
  union {
    struct {
      unsigned char Exop;
      unsigned char Bits;
    } what;
    unsigned pad;
  } word;
  unsigned base;
};

struct inflate_huft_s fixed_tl[] = {
  { .word.what = { 96, 7 }, .base = 256 }
};

union bt4 {
  struct {
    unsigned long int av4;
  } gv4;
  double hv4;
};

union bt4 bkv4 = { .gv4 = { .av4 = 61172160UL } };

struct bt1 {
  signed dv1:4;
  signed ev1:6;
  unsigned char fv1[1];
};

struct bt1 cav1 = { .dv1 = 4, .ev1 = 22, .fv1 = { '\x2' } };

union foo {
  struct { char A, B; } X;
  int C;
};

union foo V = { .X = {1, 2} };

union nameData {
  char data[64];
  int alignmentDummy;
};

union nameData nd = {.data = "relname"};

struct one {
  int a;
  int values[3];
};

struct one hobbit = {5, {1, 2, 3}};
struct one hobbit2 = {5, {1, 2, 3}};

struct {
  int x;
  int v[3];
} data = {0, {1,2,3} };

struct {
  char *inplace;
  char chunk_data[16];
} s = {.inplace = NULL, .chunk_data = "   xyzkasjdlf     "};

struct dvd_send_key {
  unsigned agid : 2;
  unsigned char key[5];
};

union {
  struct dvd_send_key lsk;
} ai = {.lsk = {3, "foo"}};

typedef struct {} emptystruct;

typedef struct {
  emptystruct raw_lock;
} spinlock_t;

emptystruct one_raw_spinlock (void) {
  emptystruct raw;
  printf("returning raw_lock\n");
  return raw;
}

union ucast {
  int i;
  struct s {
    int i1, i2, i3;
  } s;
};

union ucast ucast_test (void) {
  struct s y = {1, 2, 0};  // Initializing i3 to zero for safety
  union ucast z;
  memcpy(&z.s, &y, sizeof(struct s)); // Use memcpy to avoid cast warnings
  return z;
}

#pragma pack(4)
struct foo2 {
  short a;
  long  x;
  short y;
};
#pragma pack()
struct foo2 foo2 = { 23122, -12312731, -312 };

// Main function
int main() {
  union ucast XX;
  spinlock_t lock;
  printf("PR156: %s\n", init_task_union.task.comm);
  printf("PR295/PR568: %d, %d\n", fixed_tl[0].word.pad, fixed_tl[0].base);
  printf("PR574: %ld, %d, %d, %d\n", bkv4.gv4.av4, cav1.dv1, cav1.ev1,
         cav1.fv1[0]);
  printf("PR162: %d, %d\n", V.X.A, V.X.B);
  printf("PR650: %s, %d\n", nd.data, nd.alignmentDummy);
  printf("PR199: %d, %d, %d, %d\n", hobbit.a, hobbit.values[0],
         hobbit.values[1], hobbit.values[2]);
  printf("PR199: %d, %d, %d, %d\n", hobbit2.a, hobbit2.values[0],
         hobbit2.values[1], hobbit2.values[2]);
  printf("PR431: %d, %d, %d, %d\n", data.x, data.v[0],
         data.v[1], data.v[2]);
  printf("PR654: %ld, '%s'\n", (long) s.inplace, s.chunk_data);
  printf("PR323: %d, '%s'\n", ai.lsk.agid, ai.lsk.key);
  lock.raw_lock = one_raw_spinlock();
  printf("PR627: %d\n", (int)sizeof(lock));
  XX = ucast_test();
  printf("PR684: %d, %d, %d %d\n", XX.s.i1, XX.s.i2, XX.s.i3, XX.i);
  printf("rdar://6828787: %d, %ld, %d\n", foo2.a, foo2.x, foo2.y);
  return 0;
}