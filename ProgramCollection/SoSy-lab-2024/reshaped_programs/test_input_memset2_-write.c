#include <stdio.h>
#include <string.h>

struct compstat {
    unsigned int unc_bytes;
    unsigned int unc_packets;
    unsigned int comp_bytes;
    unsigned int comp_packets;
    unsigned int inc_bytes;
    unsigned int inc_packets;
    unsigned int in_count;
    unsigned int bytes_out;
    double ratio;
};

int main() {
    struct compstat cstats;

    // Initialize the compstat structure using memset
    memset((void *)&cstats, 0, sizeof(struct compstat));

    // Printing the initialized values for verification
    printf("Uncompressed Bytes: %u\n", cstats.unc_bytes);
    printf("Uncompressed Packets: %u\n", cstats.unc_packets);
    printf("Compressed Bytes: %u\n", cstats.comp_bytes);
    printf("Compressed Packets: %u\n", cstats.comp_packets);
    printf("Incoming Bytes: %u\n", cstats.inc_bytes);
    printf("Incoming Packets: %u\n", cstats.inc_packets);
    printf("Incoming Count: %u\n", cstats.in_count);
    printf("Bytes Out: %u\n", cstats.bytes_out);
    printf("Compression Ratio: %f\n", cstats.ratio);
    
    return 0;
}