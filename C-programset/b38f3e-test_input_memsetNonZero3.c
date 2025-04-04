#include <stdio.h>
#include <string.h> // For using memset
#include <stdint.h> // For standard integer types

typedef uint32_t __u32; // Using standard uint32_t for unsigned int

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

    // Initialize all fields to zero, ensuring no uninitialized variables
    memset(&cstats, 0, sizeof(cstats));

    // Fill memory with a value starting from &cstats for 80 bytes
    memset(&cstats, 10, 80UL);

    // Logging for verification
    printf("First byte after memset: %d\n", *((unsigned char *)&cstats));
    
    return 0;
}