#include <stdio.h>
#include <string.h>

typedef struct {
    unsigned char colormod;
} entity_state_t;

typedef struct {
    int num_entities;
    entity_state_t *entities;
} packet_entities_t;

typedef struct {
    double senttime;
    float ping_time;
    packet_entities_t entities;
} client_frame_t;

typedef enum {
    cs_free,
    cs_server,
    cs_zombie,
    cs_connected,
    cs_spawned
} sv_client_state_t;

typedef struct client_s {
    sv_client_state_t state;
    int ping;
    client_frame_t frames[64];
} client_t;

int CalcPing(client_t *cl) {
    float ping = 0.0;
    int count = 0, i;
    client_frame_t *frame;

    if (cl->state == cs_server) {
        return cl->ping;
    }

    for (frame = cl->frames, i = 0; i < 64; i++, frame++) {
        if (frame->ping_time > 0) {
            ping += frame->ping_time;
            count++;
        }
    }

    if (!count) {
        return 9999;
    }

    ping /= count;
    return (int)(ping * 1000);
}

int main(void) {
    client_t cl;
    memset(&cl, 0, sizeof(cl));

    // Initialize with sample data simulating a typical input case
    cl.frames[0].ping_time = 1.0; // Example where ping_time is set to 1.0

    if (CalcPing(&cl) != 1000) {
        printf("Ping calculation did not meet expected value.\n");
    } else {
        printf("Ping calculation met expected value of 1000.\n");
    }

    return 0;
}