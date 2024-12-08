#include <stdio.h>
#include <string.h>

// Define the types explicitly for standard use
typedef unsigned int size_t;
typedef unsigned int __u32;

// Define the compstat structure
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

// Define the ppp_comp_stats structure containing two compstat structures
struct ppp_comp_stats {
    struct compstat c;
    struct compstat d;
};

int main() {
    // Declare and initialize the ppp_comp_stats structure
    struct ppp_comp_stats cstats;
    
    // Use memset to initialize entire structure to zero
    memset(&cstats, 0, sizeof(struct ppp_comp_stats));
    
    // Additional output to verify program behavior, though not required
    printf("Initialized ppp_comp_stats structure with zero values.\n");

    return 0;
}