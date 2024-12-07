#include <stdio.h>
#include <string.h>

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

int main() {
    struct compstat cstats;
    
    // Initialize all fields in the struct to zero
    memset(&cstats, 0, sizeof(cstats));

    // For demonstration, let's print the initialized structure values
    printf("unc_bytes: %u\n", cstats.unc_bytes);
    printf("unc_packets: %u\n", cstats.unc_packets);
    printf("comp_bytes: %u\n", cstats.comp_bytes);
    printf("comp_packets: %u\n", cstats.comp_packets);
    printf("inc_bytes: %u\n", cstats.inc_bytes);
    printf("inc_packets: %u\n", cstats.inc_packets);
    printf("in_count: %u\n", cstats.in_count);
    printf("bytes_out: %u\n", cstats.bytes_out);
    printf("ratio: %f\n", cstats.ratio);

    return 0;
}