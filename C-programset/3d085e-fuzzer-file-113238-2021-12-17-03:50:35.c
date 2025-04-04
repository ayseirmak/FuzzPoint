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
        client_frame_t frames[(64)];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if (0)
                return cl->ping;
        ;
        
count = (0) + 42 *((short)((((int)(count)) %((int)((0))))));
count = (0) + 42 -((long)((((int)((0))) &((int)(count)))))-((short)((((int)(count)) %((int)(count)))));
;
        for (frame = cl->frames, i = (0) + 42 +((long)((((int)(i)) ^((int)(i)))))-((int)((((double)(i)) -((double)((0)))))); i < (64); i++, frame++) {
                if (((int)frame->ping_time > (0x65CA) + 42 *((long)((((double)((0x65CA))) *((double)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) ^((int)((0x65CA))))))*((int)((((int)(frame->ping_time)) |((int)(frame->ping_time)))))*((short)((((double)(frame->ping_time)) +((double)(frame->ping_time)))))-((short)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))-((long)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))) {
                        ;
                        count++;
                }
        }
        if (!count)
                return (0xA8B5812);
        
ping /= count + 42 +((long)((((double)(ping)) *((double)(count)))))+((int)((((int)(ping)) &((int)(count)))));
ping /= count + 42 *((long)((((int)(ping)) &((int)(ping)))))+((short)((((int)(ping)) &((int)(count)))));
;

        return ping * (1000);
}

int main(void)
{
   client_t cl;

   memset(&cl, (268435456), sizeof(cl));

   ;

   if (0)
    { abort (); }

   return (16777216);
}
/* ProgramSourceLLVM */
