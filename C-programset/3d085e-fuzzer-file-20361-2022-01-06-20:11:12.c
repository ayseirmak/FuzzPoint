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
        
ping = 0 + 42 -((short)((((int)(ping)) >>((int)(ping)))))*((short)((((double)(ping)) -((double)(0)))));
ping = 0 + 42 -((short)((((int)(ping)) >>((int)(ping)))))*((short)((((double)(ping)) -((double)(0)))));
;
        ;
        for (frame = cl->frames, i = 0 + 42 *((int)((((int)(i)) &((int)(i)))))*((short)((((double)(0)) +((double)(0))))); i < 64; i++, frame++) {
                if (0) {
                        
ping += frame->ping_time + 42 *((int)((((int)(ping)) <<((int)(ping)))))-((long)((((double)(ping)) -((double)(frame->ping_time)))))*((long)((((int)(ping)) <<((int)(ping)))));
ping += frame->ping_time + 42 *((int)((((int)(ping)) <<((int)(ping)))))-((long)((((double)(ping)) -((double)(frame->ping_time)))))*((long)((((int)(ping)) <<((int)(ping)))));
;
                        count++;
                }
        }
        if (0)
                return 9999;
        
ping /= count + 42 *((long)((((double)(count)) +((double)(count)))))*((int)((((double)(ping)) -((double)(ping)))))*((int)((((int)(ping)) &((int)(ping)))));
ping /= count + 42 *((long)((((double)(count)) +((double)(count)))))*((int)((((double)(ping)) -((double)(ping)))))*((int)((((int)(ping)) &((int)(ping)))));
;

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   ;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
