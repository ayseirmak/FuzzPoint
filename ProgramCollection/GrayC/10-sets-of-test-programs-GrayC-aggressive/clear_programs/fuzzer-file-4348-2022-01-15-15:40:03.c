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

        if (0)
                return cl->ping;
        ping = 0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((long)((((int)(ping)) ^((int)(0)))))+((long)((((int)(ping)) ^((int)(ping)))))*((short)((((double)(ping)) *((double)(0))))) + 42 -((long)((((int)(ping)) &((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((long)((((int)(ping)) ^((int)(0)))))+((long)((((int)(ping)) ^((int)(ping)))))*((short)((((double)(ping)) *((double)(0))))))))))+((int)((((int)(ping)) &((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((long)((((int)(ping)) ^((int)(0)))))+((long)((((int)(ping)) ^((int)(ping)))))*((short)((((double)(ping)) *((double)(0))))))))))-((short)((((int)(ping)) %((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((long)((((int)(ping)) ^((int)(0)))))+((long)((((int)(ping)) ^((int)(ping)))))*((short)((((double)(ping)) *((double)(0))))))))))+((int)((((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((long)((((int)(ping)) ^((int)(0)))))+((long)((((int)(ping)) ^((int)(ping)))))*((short)((((double)(ping)) *((double)(0))))))) &((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((long)((((int)(ping)) ^((int)(0)))))+((long)((((int)(ping)) ^((int)(ping)))))*((short)((((double)(ping)) *((double)(0))))))))))+((int)((((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((long)((((int)(ping)) ^((int)(0)))))+((long)((((int)(ping)) ^((int)(ping)))))*((short)((((double)(ping)) *((double)(0))))))) ^((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((long)((((int)(ping)) ^((int)(0)))))+((long)((((int)(ping)) ^((int)(ping)))))*((short)((((double)(ping)) *((double)(0))))))))));
        count = 0 + 42 *((long)((((int)(0)) %((int)(0))))) + 42 -((short)((((int)(0 + 42 *((long)((((int)(0)) %((int)(0))))))) &((int)(count)))))-((short)((((int)(0 + 42 *((long)((((int)(0)) %((int)(0))))))) ^((int)(count)))))*((long)((((int)(count)) >>((int)(count)))));
        for (frame = cl->frames, i = 0 + 42 *((int)((((int)(i)) >>((int)(i)))))-((long)((((int)(i)) >>((int)(i))))) + 42 +((long)((((int)(0 + 42 *((int)((((int)(i)) >>((int)(i)))))-((long)((((int)(i)) >>((int)(i))))))) |((int)(i))))); i < 64; i++, frame++) {
                if (0) {
                        ping += frame->ping_time + 42 -((short)((((int)(frame->ping_time)) |((int)(ping)))))-((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))+((int)((((double)(ping)) -((double)(frame->ping_time))))) + 42 -((long)((((double)(((short)((((int)(frame->ping_time)) |((int)(ping))))))) -((double)(frame->ping_time + 42)))));
                        count++;
                }
        }
        if (!count)
                return 9999;
        ping /= count + 42 +((int)((((double)(ping)) -((double)(count)))))*((int)((((int)(ping)) |((int)(ping))))) + 42 +((long)((((int)(ping)) >>((int)(count + 42 +((int)((((double)(ping)) -((double)(count)))))*((int)((((int)(ping)) |((int)(ping))))))))));

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f + 42 +((short)((((int)(1.0f)) <<((int)(cl.frames[0].ping_time)))))-((int)((((int)(cl.frames[0].ping_time)) >>((int)(1.0f)))))*((short)((((int)(cl.frames[0].ping_time)) |((int)(cl.frames[0].ping_time)))))-((short)((((double)(1.0f)) -((double)(1.0f)))))*((int)((((int)(cl.frames[0].ping_time)) &((int)(cl.frames[0].ping_time))))) + 42 +((int)((((int)(cl.frames[0].ping_time)) &((int)(((short)((((double)(1.0f)) -((double)(1.0f)))))*((int)((((int)(cl.frames[0].ping_time)) &((int)(cl.frames[0].ping_time))))))))));

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
