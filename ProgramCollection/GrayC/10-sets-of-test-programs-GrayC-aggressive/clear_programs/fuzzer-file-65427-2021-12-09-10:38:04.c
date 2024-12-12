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

        if (((int)cl->state == cs_server + 42 *((short)((((int)(cl->state)) <<((int)(cs_server)))))*((int)((((int)(cs_server)) %((int)(cl->state)))))-((int)((((int)(cs_server)) |((int)(cl->state)))))*((int)((((double)(cs_server)) *((double)(cs_server)))))*((long)((((double)(cs_server)) *((double)(cs_server)))))+((int)((((int)(cs_server)) ^((int)(cl->state)))))+((short)((((double)(cl->state)) -((double)(cs_server)))))-((int)((((double)(cs_server)) *((double)(cl->state)))))))
                return cl->ping;
        
ping = 0 + 42 *((long)((((double)(ping)) +((double)(0)))));
ping = 0 + 42 +((long)((((int)(ping)) |((int)(0)))))-((long)((((int)(ping)) &((int)(ping)))));
;
        
count = 0 + 42 +((long)((((double)(count)) -((double)(count)))));
count = 0 + 42 +((long)((((double)(count)) +((double)(0)))))+((long)((((int)(count)) |((int)(count)))))*((long)((((int)(count)) |((int)(0)))))*((long)((((double)(0)) *((double)(0)))))-((short)((((int)(count)) |((int)(count)))));
;
        for (frame = cl->frames, i = 0 + 42 -((long)((((double)(i)) *((double)(i))))); i < 64; i++, frame++) {
                if (0) {
                        
ping += frame->ping_time + 42 -((int)((((double)(frame->ping_time)) *((double)(ping)))));
ping += frame->ping_time + 42 -((short)((((int)(frame->ping_time)) ^((int)(frame->ping_time)))));
;
                        count++;
                }
        }
        if (!count)
                return 9999;
        ;

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   
cl.frames[0].ping_time = 1.0f + 42 +((short)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time)))))*((short)((((int)(cl.frames[0].ping_time)) &((int)(cl.frames[0].ping_time)))))+((int)((((int)(cl.frames[0].ping_time)) &((int)(cl.frames[0].ping_time)))))+((short)((((int)(1.0f)) >>((int)(1.0f)))));
cl.frames[0].ping_time = 1.0f + 42 *((int)((((double)(1.0f)) +((double)(1.0f)))))+((int)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))))*((short)((((int)(1.0f)) &((int)(cl.frames[0].ping_time)))))-((short)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))));
;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
