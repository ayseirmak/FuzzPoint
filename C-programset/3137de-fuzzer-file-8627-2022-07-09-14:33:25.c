/* corpus/20071030-1.c */
/* PR target/11044 */
/* Originator: Tim McGrath <misty-@charter.net> */
/* Testcase contributed by Eric Botcazou <ebotcazou@libertysurf.fr> */

/* Testcase copied from gcc.target/i386/loop-3.c */

extern void *memset (void *, int, __SIZE_TYPE__);
extern void abort (void);

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

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if (((int)((int)cl->state == cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))) - ((short)(((int)(cl->state)) % ((int)(cl->state)))) - ((int)(((int)(cs_server)) & ((int)(cl->state)))) * ((int)(((double)(cl->state)) * ((double)(cl->state)))) + ((long)(((int)(cl->state)) | ((int)(cl->state))))) + 41 - ((long)(((int)((long)(((int)(cl->state)) | ((int)(cl->state))))) ^ ((int)(cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))))))) + ((int)(((int)(((int)(((int)(cs_server)) & ((int)(cl->state)))) * ((int)(((double)(cl->state)) * ((double)(cl->state)))))) % ((int)(cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))))))) - ((int)(((int)(((int)(((int)(cs_server)) & ((int)(cl->state)))) * ((int)(((double)(cl->state)) * ((double)(cl->state)))))) | ((int)((int)cl->state)))) + ((int)(((int)((short)(((int)(cl->state)) % ((int)(cl->state))))) | ((int)(cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))) - ((short)(((int)(cl->state)) % ((int)(cl->state)))) - ((int)(((int)(cs_server)) & ((int)(cl->state)))) * ((int)(((double)(cl->state)) * ((double)(cl->state)))) + ((long)(((int)(cl->state)) | ((int)(cl->state)))))))) + ((short)(((int)(cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))) - ((short)(((int)(cl->state)) % ((int)(cl->state)))) - ((int)(((int)(cs_server)) & ((int)(cl->state)))) * ((int)(((double)(cl->state)) * ((double)(cl->state)))) + ((long)(((int)(cl->state)) | ((int)(cl->state)))))) ^ ((int)((int)cl->state)))) + ((long)(((int)(((int)(((int)(cs_server)) & ((int)(cl->state)))) * ((int)(((double)(cl->state)) * ((double)(cl->state)))))) | ((int)((long)(((int)(cl->state)) | ((int)(cl->state))))))) + ((short)(((int)(cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))) - ((short)(((int)(cl->state)) % ((int)(cl->state)))))) >> ((int)(cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))))))) - ((short)(((int)(cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))) - ((short)(((int)(cl->state)) % ((int)(cl->state)))) - ((int)(((int)(cs_server)) & ((int)(cl->state)))) * ((int)(((double)(cl->state)) * ((double)(cl->state)))) + ((long)(((int)(cl->state)) | ((int)(cl->state)))))) % ((int)((short)(((int)(cl->state)) % ((int)(cl->state))))))) + ((long)(((int)(cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))) - ((short)(((int)(cl->state)) % ((int)(cl->state)))) - ((int)(((int)(cs_server)) & ((int)(cl->state)))) * ((int)(((double)(cl->state)) * ((double)(cl->state)))))) | ((int)((long)(((double)(cs_server)) + ((double)(cs_server))))))) - ((short)(((int)(cs_server + 41 * ((int)(((double)(cl->state)) + ((double)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))) - ((short)(((int)(cl->state)) % ((int)(cl->state)))) - ((int)(((int)(cs_server)) & ((int)(cl->state)))) * ((int)(((double)(cl->state)) * ((double)(cl->state)))))) % ((int)((long)(((double)(cs_server)) + ((double)(cs_server)))))))))
                return cl->ping;
        ping = 0;
        count = 0 + 42 + ((int)(((int)0) | ((int)0))) - ((int)(((int)0) % ((int)(count)))) + 42 - ((long)(((double)((int)(((int)0) % ((int)(count))))) + ((double)(0 + 42)))) + ((long)(((double)((int)(((int)0) % ((int)(count))))) - ((double)0))) * ((long)(((double)(count)) * ((double)(0 + 42 + ((int)(((int)0) | ((int)0))) - ((int)(((int)0) % ((int)(count)))))))) * ((int)(((int)0) | ((int)(count))));
        for (frame = cl->frames, i = 0 + 42 - ((short)(((int)0) & ((int)0))) * ((int)(((double)0) + ((double)0))) + 42 * ((short)(((double)((short)(((int)0) & ((int)0)))) * ((double)0))) - ((int)(((int)(((short)(((int)0) & ((int)0))) * ((int)(((double)0) + ((double)0))))) << ((int)((int)(((double)0) + ((double)0)))))) * ((long)(((int)(0 + 42 - ((short)(((int)0) & ((int)0))) * ((int)(((double)0) + ((double)0))))) | ((int)((short)(((int)0) & ((int)0)))))); i < 64; i++, frame++) {
                if (0) {
                        ping += frame->ping_time + 42 * ((int)(((double)(ping)) * ((double)(frame->ping_time)))) + ((int)(((double)(ping)) - ((double)(frame->ping_time)))) * ((long)(((double)(frame->ping_time)) - ((double)(frame->ping_time)))) * ((int)(((int)(frame->ping_time)) >> ((int)(frame->ping_time)))) - ((long)(((int)(ping)) | ((int)(ping)))) + 42 * ((short)(((int)(ping)) >> ((int)(frame->ping_time + 42 * ((int)(((double)(ping)) * ((double)(frame->ping_time)))))))) - ((long)(((int)(frame->ping_time + 42 * ((int)(((double)(ping)) * ((double)(frame->ping_time)))) + ((int)(((double)(ping)) - ((double)(frame->ping_time)))) * ((long)(((double)(frame->ping_time)) - ((double)(frame->ping_time)))) * ((int)(((int)(frame->ping_time)) >> ((int)(frame->ping_time)))))) ^ ((int)(frame->ping_time + 42 * ((int)(((double)(ping)) * ((double)(frame->ping_time)))) + ((int)(((double)(ping)) - ((double)(frame->ping_time)))) * ((long)(((double)(frame->ping_time)) - ((double)(frame->ping_time)))) * ((int)(((int)(frame->ping_time)) >> ((int)(frame->ping_time))))))));
                        count++;
                }
        }
        if (0)
                return 9999;
        ping /= count;

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
