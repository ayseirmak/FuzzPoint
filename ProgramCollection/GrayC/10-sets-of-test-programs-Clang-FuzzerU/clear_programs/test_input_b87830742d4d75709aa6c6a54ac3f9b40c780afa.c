#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    unsigned char colormod;
} entity_state_t;

typedef struct
{
    int num_entities;
    entity_state_t *entities;
} packet_entities_t;

typedef struct
{
    double senttime;
    float ping_time;
    packet_entities_t entities;
} client_frame_t;

typedef enum
{
    cs_free,
    cs_server,
    cs_zombie,
    cs_connected,
    cs_spawned
} sv_client_state_t;

typedef struct client_s
{
    sv_client_state_t state;
    int ping;
    client_frame_t frames[64];
} client_t;

int CalcPing(client_t *cl)
{
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

int main(void)
{
    client_t cl;

    memset(&cl, 0, sizeof(cl));
    cl.frames[0].ping_time = 1.0f;

    assert(CalcPing(&cl) == 1000);

    printf("Test passed successfully.\n");
    return 0;
}