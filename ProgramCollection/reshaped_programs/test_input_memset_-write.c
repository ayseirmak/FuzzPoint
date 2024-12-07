#include <stdio.h>   // For printf, although not used, added for completeness
#include <string.h>  // For memset

typedef unsigned int __kernel_size_t;
typedef __kernel_size_t size_t;

typedef unsigned int __u32;

struct compstat {
    __u32 unc_bytes;
    __u32 unc_packets;
    __u32 comp_bytes;
    __u32 comp_packets;
    __u32 inc_bytes;
    __u32 inc_packets;
    __u32 in_count;
    __u32 bytes_out;
    double ratio;
};

struct ppp_comp_stats {
    struct compstat c;
    struct compstat d;
};

int main() {
    struct ppp_comp_stats cstats;
    // Use sizeof to compute the size of cstats instead of hardcoded value for memory operations
    memset((void*)(&cstats), 0, sizeof(cstats));

    // Added a print statement to demonstrate program execution
    printf("Statistics structure initialized to zero.\n");

    return 0;
}