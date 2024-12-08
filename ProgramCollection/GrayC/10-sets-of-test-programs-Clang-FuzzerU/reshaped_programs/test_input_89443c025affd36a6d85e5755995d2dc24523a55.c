#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    cs_free,
    cs_server,
    cs_zombie,
    cs_connected,
    cs_spawned
} sv_client_state_t;

typedef struct {
    double senttime;
    float ping_time;
} client_frame_t;

typedef struct client_s {
    sv_client_state_t state;
    int ping;
    client_frame_t frames[64];
} client_t;

int CalcPing(client_t *cl) {
    float ping = 0;
    int count = 0;
    int i;
    client_frame_t *frame;

    if (cl->state == cs_server)
        return cl->ping;

    for (frame = cl->frames, i = 0; i < 64; i++, frame++) {
        if (frame->ping_time > 0) {
            ping += frame->ping_time;
            count++;
        }
    }

    if (count == 0) {
        return 9999; // Default fallback when no pings are registered
    }

    ping /= count;
    return ping * 1000;
}

int main(void) {
    client_t cl;

    memset(&cl, 0, sizeof(cl));
    cl.frames[0].ping_time = 1.0f;

    if (CalcPing(&cl) != 1000) {
        printf("Test failed\n");
        abort();
    } else {
        printf("Test passed\n");
    }

    return 0;
}