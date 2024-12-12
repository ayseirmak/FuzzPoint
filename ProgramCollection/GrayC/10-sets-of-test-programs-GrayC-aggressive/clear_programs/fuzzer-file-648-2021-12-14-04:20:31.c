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
        
ping = (67108864) + 42 -((long)((((int)((67108864))) %((int)(ping)))))-((long)((((int)(ping)) |((int)((67108864))))))*((short)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) *((double)(ping)))));
ping = (67108864) + 42 *((long)((((int)(ping)) >>((int)(ping)))))-((short)((((double)((67108864))) -((double)(ping)))))*((int)((((int)(ping)) <<((int)(ping)))));
;
        ;
        for (frame = cl->frames, i = (-1) + 42 *((long)((((int)(i)) &((int)(i)))))+((short)((((int)(i)) ^((int)(i)))))*((short)((((int)(i)) ^((int)(i))))); i < (96); i++, frame++) {
                if (0) {
                        
ping += frame->ping_time + 42 *((int)((((double)(ping)) +((double)(frame->ping_time)))));
ping += frame->ping_time + 42 +((int)((((double)(ping)) *((double)(ping)))))+((short)((((int)(ping)) %((int)(ping)))))-((int)((((double)(ping)) +((double)(ping)))))*((long)((((double)(frame->ping_time)) *((double)(ping)))))+((short)((((int)(frame->ping_time)) %((int)(frame->ping_time)))));
;
                        count++;
                }
        }
        if (0)
                return (-10000);
        ;

        return ping * (1003);
}

int main(void)
{
   client_t cl;

   memset(&cl, (2147483648), sizeof(cl));

   ;

   if (0)
    { abort (); }

   return (0);
}
/* ProgramSourceLLVM */
