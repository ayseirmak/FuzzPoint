#include <stdio.h>
#include <string.h>  // For the memset function

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
    
    // The value of '10' and '80UL' are retained from the original, but this is typically not meaningful for memset.
    memset((void *)(&cstats), 10, 80UL);

    // Example Usage
    printf("Structure initialized with memset.\n");
    
    return 0;
}