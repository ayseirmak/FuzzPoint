#include <stdio.h>
#include <string.h>  // Required for memset
#include <stddef.h>  // Required for size_t

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

    // Initialize all bytes of cstats to 10
    memset(&cstats, 10, sizeof(cstats));

    // Optionally, print the first few bytes to verify
    unsigned char *bytes = (unsigned char *)&cstats;
    printf("First few bytes of cstats after memset:\n");
    for (size_t i = 0; i < sizeof(__u32); ++i) {
        printf("0x%02x ", bytes[i]);
    }
    printf("\n");

    return 0;
}