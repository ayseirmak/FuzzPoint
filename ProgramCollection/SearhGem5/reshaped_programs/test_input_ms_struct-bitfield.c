#include <stdio.h>
#include <stdlib.h>

#define size_struct_0 1
#define size_struct_1 4
#define size_struct_2 24
#define size_struct_3 8
#define size_struct_4 32
#define size_struct_5 12
#define size_struct_6 40
#define size_struct_7 8
#define size_struct_8 20
#define size_struct_9 32

struct _struct_0 {
    char member_0;
};
typedef struct _struct_0 struct_0;

struct _struct_1 {
    char member_0;
    short member_1:13;
};
typedef struct _struct_1 struct_1;

struct _struct_2 {
    double member_0;
    unsigned char member_1:8;
    int member_2:32;
    unsigned char member_3:5;
    short member_4:14;
    short member_5:13;
    unsigned char:0;
};
typedef struct _struct_2 struct_2;

struct _struct_3 {
    unsigned int member_0:26;
    unsigned char member_1:2;
};
typedef struct _struct_3 struct_3;

struct _struct_4 {
    unsigned char member_0:7;
    double member_1;
    double member_2;
    short member_3:5;
    char member_4:2;
};
typedef struct _struct_4 struct_4;

struct _struct_5 {
    unsigned short member_0:12;
    int member_1:1;
    unsigned short member_2:6;
};
typedef struct _struct_5 struct_5;

struct _struct_6 {
    unsigned char member_0:7;
    unsigned int member_1:25;
    char member_2:1;
    double member_3;
    short member_4:9;
    double member_5;
};
typedef struct _struct_6 struct_6;

struct _struct_7 {
    double member_0;
};
typedef struct _struct_7 struct_7;

struct _struct_8 {
    unsigned char member_0:7;
    int member_1:11;
    int member_2:5;
    int:0;
    char member_4:8;
    unsigned short member_5:4;
    unsigned char member_6:3;
    int member_7:23;
};
typedef struct _struct_8 struct_8;

struct _struct_9 {
    double member_0;
    unsigned int member_1:6;
    int member_2:17;
    double member_3;
    unsigned int member_4:22;
};
typedef struct _struct_9 struct_9;

struct_0 test_struct_0 = { 123 };
struct_1 test_struct_1 = { 82, 1081 };
struct_2 test_struct_2 = { 20.0, 31, 407760, 1, 14916, 6712 };
struct_3 test_struct_3 = { 64616999, 1 };
struct_4 test_struct_4 = { 61, 20.0, 20.0, 12, 0 };
struct_5 test_struct_5 = { 909, 1, 57 };
struct_6 test_struct_6 = { 12, 21355796, 0, 20.0, 467, 20.0 };
struct_7 test_struct_7 = { 20.0 };
struct_8 test_struct_8 = { 126, 1821, 22, 125, 6, 0, 2432638 };
struct_9 test_struct_9 = { 20.0, 3, 23957, 20.0, 1001631 };

void my_abort() {
    printf("Size mismatch, aborting execution.\n");
    exit(1);
}

int main(void) {
    if (size_struct_0 != sizeof(struct_0))
        my_abort();

    if (size_struct_1 != sizeof(struct_1))
        my_abort();

    if (size_struct_2 != sizeof(struct_2))
        my_abort();

    if (size_struct_3 != sizeof(struct_3))
        my_abort();

    if (size_struct_4 != sizeof(struct_4))
        my_abort();

    if (size_struct_5 != sizeof(struct_5))
        my_abort();

    if (size_struct_6 != sizeof(struct_6))
        my_abort();

    if (size_struct_7 != sizeof(struct_7))
        my_abort();

    if (size_struct_8 != sizeof(struct_8))
        my_abort();

    if (size_struct_9 != sizeof(struct_9))
        my_abort();

    return 0;
}