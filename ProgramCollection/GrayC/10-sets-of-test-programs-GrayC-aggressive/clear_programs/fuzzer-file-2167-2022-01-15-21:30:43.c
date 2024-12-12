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
        ping = 0 + 42 -((long)((((double)(ping)) -((double)(0)))))*((int)((((int)(ping)) &((int)(ping)))))-((long)((((int)(ping)) |((int)(ping))))) + 42 *((int)((((int)(0 + 42 -((long)((((double)(ping)) -((double)(0)))))*((int)((((int)(ping)) &((int)(ping)))))-((long)((((int)(ping)) |((int)(ping))))))) ^((int)(ping)))))-((long)((((int)(ping)) >>((int)(0 + 42 -((long)((((double)(ping)) -((double)(0)))))*((int)((((int)(ping)) &((int)(ping)))))-((long)((((int)(ping)) |((int)(ping))))))))))-((long)((((int)(ping)) |((int)(ping)))))*((short)((((int)(0 + 42 -((long)((((double)(ping)) -((double)(0)))))*((int)((((int)(ping)) &((int)(ping)))))-((long)((((int)(ping)) |((int)(ping))))))) ^((int)(0 + 42 -((long)((((double)(ping)) -((double)(0)))))*((int)((((int)(ping)) &((int)(ping)))))-((long)((((int)(ping)) |((int)(ping))))))))))-((short)((((int)(ping)) &((int)(0 + 42 -((long)((((double)(ping)) -((double)(0)))))*((int)((((int)(ping)) &((int)(ping)))))-((long)((((int)(ping)) |((int)(ping))))))))));
        count = 0 + 42 -((short)((((double)(count)) *((double)(count)))))+((int)((((int)(count)) %((int)(0)))))*((short)((((double)(count)) *((double)(count)))))+((long)((((double)(count)) +((double)(0))))) + 42 -((short)((((int)(0 + 42 -((short)((((double)(count)) *((double)(count)))))+((int)((((int)(count)) %((int)(0)))))*((short)((((double)(count)) *((double)(count)))))+((long)((((double)(count)) +((double)(0))))))) <<((int)(count)))))+((long)((((int)(0 + 42 -((short)((((double)(count)) *((double)(count)))))+((int)((((int)(count)) %((int)(0)))))*((short)((((double)(count)) *((double)(count)))))+((long)((((double)(count)) +((double)(0))))))) >>((int)(count)))))-((short)((((double)(count)) *((double)(count)))))*((long)((((int)(0 + 42 -((short)((((double)(count)) *((double)(count)))))+((int)((((int)(count)) %((int)(0)))))*((short)((((double)(count)) *((double)(count)))))+((long)((((double)(count)) +((double)(0))))))) <<((int)(0 + 42 -((short)((((double)(count)) *((double)(count)))))+((int)((((int)(count)) %((int)(0)))))*((short)((((double)(count)) *((double)(count)))))+((long)((((double)(count)) +((double)(0))))))))));
        for (frame = cl->frames, i = 0 + 42 -((short)((((double)(i)) *((double)(0)))))*((int)((((int)(0)) |((int)(i)))))+((int)((((double)(i)) *((double)(0)))))*((int)((((double)(i)) -((double)(0)))))-((short)((((int)(i)) |((int)(0))))) + 42 +((short)((((int)(0 + 42 -((short)((((double)(i)) *((double)(0)))))*((int)((((int)(0)) |((int)(i)))))+((int)((((double)(i)) *((double)(0)))))*((int)((((double)(i)) -((double)(0))))))) <<((int)(i)))))-((long)((((int)(42)) <<((int)(((short)((((double)(i)) *((double)(0))))))))))*((long)((((int)(((int)((((double)(i)) -((double)(0))))))) >>((int)(((int)((((double)(i)) *((double)(0))))))))))-((long)((((int)(0)) ^((int)(0 + 42 -((short)((((double)(i)) *((double)(0)))))*((int)((((int)(0)) |((int)(i))))))))))-((short)((((int)(((short)((((double)(i)) *((double)(0)))))*((int)((((int)(0)) |((int)(i))))))) >>((int)(0 + 42 -((short)((((double)(i)) *((double)(0)))))*((int)((((int)(0)) |((int)(i)))))+((int)((((double)(i)) *((double)(0)))))*((int)((((double)(i)) -((double)(0)))))-((short)((((int)(i)) |((int)(0)))))))))); i < 64; i++, frame++) {
                if (0) {
                        ping += frame->ping_time + 42 *((short)((((double)(ping)) +((double)(ping)))))*((int)((((double)(ping)) *((double)(frame->ping_time)))))*((int)((((int)(frame->ping_time)) ^((int)(ping)))))-((int)((((int)(frame->ping_time)) ^((int)(ping)))))-((int)((((double)(ping)) +((double)(ping))))) + 42 +((short)((((int)(ping)) <<((int)(frame->ping_time + 42 *((short)((((double)(ping)) +((double)(ping)))))*((int)((((double)(ping)) *((double)(frame->ping_time)))))*((int)((((int)(frame->ping_time)) ^((int)(ping)))))-((int)((((int)(frame->ping_time)) ^((int)(ping)))))-((int)((((double)(ping)) +((double)(ping))))))))))-((long)((((int)(42 *((short)((((double)(ping)) +((double)(ping)))))*((int)((((double)(ping)) *((double)(frame->ping_time)))))*((int)((((int)(frame->ping_time)) ^((int)(ping))))))) %((int)(frame->ping_time + 42 *((short)((((double)(ping)) +((double)(ping)))))*((int)((((double)(ping)) *((double)(frame->ping_time)))))*((int)((((int)(frame->ping_time)) ^((int)(ping))))))))))*((short)((((int)(42 *((short)((((double)(ping)) +((double)(ping)))))*((int)((((double)(ping)) *((double)(frame->ping_time)))))*((int)((((int)(frame->ping_time)) ^((int)(ping))))))) &((int)(frame->ping_time + 42 *((short)((((double)(ping)) +((double)(ping)))))*((int)((((double)(ping)) *((double)(frame->ping_time)))))*((int)((((int)(frame->ping_time)) ^((int)(ping)))))-((int)((((int)(frame->ping_time)) ^((int)(ping))))))))));
                        count--;
                }
        }
        if (!count)
                return 9999;
        ping /= count + 42 *((short)((((double)(count)) -((double)(ping))))) + 42 *((int)((((int)(count + 42 *((short)((((double)(count)) -((double)(ping))))))) ^((int)(count + 42 *((short)((((double)(count)) -((double)(ping))))))))))-((long)((((int)(count + 42 *((short)((((double)(count)) -((double)(ping))))))) >>((int)(count + 42 *((short)((((double)(count)) -((double)(ping))))))))));

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f + 42 -((long)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time)))))+((int)((((int)(1.0f)) %((int)(1.0f))))) + 42 +((short)((((int)(1.0f + 42 -((long)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time)))))+((int)((((int)(1.0f)) %((int)(1.0f))))))) &((int)(((int)((((int)(1.0f)) %((int)(1.0f))))))))));

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
