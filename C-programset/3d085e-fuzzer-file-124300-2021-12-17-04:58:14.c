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
        
;
;
;
        
int loop_break_9916 = 0;
for (frame = cl->frames, i = (0) + 42 -((int)((((double)(i)) -((double)(i)))))*((int)((((int)((0))) >>((int)(i)))))+((long)((((double)(i)) *((double)((0))))))-((long)((((double)((0))) +((double)((0)))))) + 42 -((long)((((int)(i)) >>((int)((0) + 42 -((int)((((double)(i)) -((double)(i)))))*((int)((((int)((0))) >>((int)(i)))))+((long)((((double)(i)) *((double)((0))))))-((long)((((double)((0))) +((double)((0)))))))))))-((int)((((int)((0) + 42 -((int)((((double)(i)) -((double)(i)))))*((int)((((int)((0))) >>((int)(i)))))+((long)((((double)(i)) *((double)((0))))))-((long)((((double)((0))) +((double)((0)))))))) >>((int)(i))))); i < (64); i++, frame++) {
                
loop_break_9916++;
if(loop_break_9916<=4){
continue;
}

if (((int)((int)frame->ping_time > (0x65CA) + 42 -((int)((((double)((0x65CA))) *((double)(frame->ping_time)))))*((int)((((double)(frame->ping_time)) +((double)(frame->ping_time)))))*((short)((((double)((0x65CA))) +((double)(frame->ping_time)))))-((long)((((double)((0x65CA))) +((double)((0x65CA))))))+((long)((((int)(frame->ping_time)) &((int)(frame->ping_time)))))-((short)((((int)((0x65CA))) >>((int)(frame->ping_time)))))-((int)((((int)(frame->ping_time)) %((int)(frame->ping_time)))))+((short)((((double)(frame->ping_time)) +((double)(frame->ping_time)))))-((short)((((int)(frame->ping_time)) >>((int)(frame->ping_time)))))) + 42 *((long)((((int)((0x65CA) + 42 -((int)((((double)((0x65CA))) *((double)(frame->ping_time)))))*((int)((((double)(frame->ping_time)) +((double)(frame->ping_time)))))*((short)((((double)((0x65CA))) +((double)(frame->ping_time)))))-((long)((((double)((0x65CA))) +((double)((0x65CA))))))+((long)((((int)(frame->ping_time)) &((int)(frame->ping_time)))))-((short)((((int)((0x65CA))) >>((int)(frame->ping_time)))))-((int)((((int)(frame->ping_time)) %((int)(frame->ping_time))))))) %((int)((0x65CA) + 42 -((int)((((double)((0x65CA))) *((double)(frame->ping_time)))))*((int)((((double)(frame->ping_time)) +((double)(frame->ping_time)))))*((short)((((double)((0x65CA))) +((double)(frame->ping_time)))))-((long)((((double)((0x65CA))) +((double)((0x65CA))))))+((long)((((int)(frame->ping_time)) &((int)(frame->ping_time)))))-((short)((((int)((0x65CA))) >>((int)(frame->ping_time)))))-((int)((((int)(frame->ping_time)) %((int)(frame->ping_time)))))+((short)((((double)(frame->ping_time)) +((double)(frame->ping_time)))))-((short)((((int)(frame->ping_time)) >>((int)(frame->ping_time)))))))))))) {
                        ;
                        count++;
                }
        }
        if (0)
                return (0xA8B5812);
        

;
;
;



;

ping /= count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))) + 42 -((long)((((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))) <<((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))))+((short)((((int)(ping)) <<((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))));
ping /= count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))) + 42 -((long)((((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))) <<((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))))+((short)((((int)(ping)) <<((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))));
;
;
;
;
;
;
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
