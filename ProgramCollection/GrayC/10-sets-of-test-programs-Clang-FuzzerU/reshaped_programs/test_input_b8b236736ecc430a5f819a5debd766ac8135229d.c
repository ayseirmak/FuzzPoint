#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
    float ping = 0.0f;
    int count = 0;
    int i;
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

    if (count == 0) {
        return 9999;
    }

    ping /= count;
    return (int)(ping * 1000);
}

int main(void) {
    client_t cl;

    // Initialize the client structure with deterministic values
    memset(&cl, 0, sizeof(cl));

    // Simulating some ping times
    cl.frames[0].ping_time = 1.0f;

    int calculated_ping = CalcPing(&cl);
    printf("Calculated Ping: %d\n", calculated_ping);

    // Assert that calculated ping matches expected value
    assert(calculated_ping == 1000);

    return 0;
}