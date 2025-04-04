#include <stdio.h>
#include <string.h>  // For memset

// Custom typedefs from the original code
typedef unsigned int __u32;

// Struct as defined in the original code
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

int main() {
    struct compstat cstats;
    
    // Using `sizeof` to ensure proper struct size is used for memset
    memset((void *)(&cstats), 10, sizeof(struct compstat));
    
    printf("Memory for cstats is initialized.\n");

    return 0;
}