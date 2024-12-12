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
        
ping = 0 + 42 *((long)((((double)(ping)) *((double)(0)))))-((int)((((int)(ping)) &((int)(0)))))-((int)((((int)(0)) |((int)(0)))))*((short)((((double)(ping)) -((double)(ping))))) + 42 -((short)((((int)(0 + 42 *((long)((((double)(ping)) *((double)(0)))))-((int)((((int)(ping)) &((int)(0)))))-((int)((((int)(0)) |((int)(0)))))*((short)((((double)(ping)) -((double)(ping))))))) >>((int)(ping)))));
ping = 0 + 42 *((long)((((double)(ping)) *((double)(0)))))-((int)((((int)(ping)) &((int)(0)))))-((int)((((int)(0)) |((int)(0)))))*((short)((((double)(ping)) -((double)(ping))))) + 42 *((long)((((int)(0 + 42 *((long)((((double)(ping)) *((double)(0)))))-((int)((((int)(ping)) &((int)(0)))))-((int)((((int)(0)) |((int)(0)))))*((short)((((double)(ping)) -((double)(ping))))))) &((int)(0 + 42 *((long)((((double)(ping)) *((double)(0)))))-((int)((((int)(ping)) &((int)(0)))))-((int)((((int)(0)) |((int)(0)))))*((short)((((double)(ping)) -((double)(ping))))))))))*((short)((((double)(ping)) -((double)(ping)))))+((short)((((int)(ping)) &((int)(ping)))));
;
        
count = 0 + 42 +((short)((((int)(0)) ^((int)(count)))))-((long)((((double)(0)) -((double)(0)))))*((short)((((int)(count)) ^((int)(count)))))+((long)((((double)(0)) +((double)(0))))) + 42 -((short)((((int)(count)) <<((int)(0 + 42 +((short)((((int)(0)) ^((int)(count)))))-((long)((((double)(0)) -((double)(0)))))*((short)((((int)(count)) ^((int)(count)))))+((long)((((double)(0)) +((double)(0))))))))))-((short)((((int)(0 + 42 +((short)((((int)(0)) ^((int)(count)))))-((long)((((double)(0)) -((double)(0)))))*((short)((((int)(count)) ^((int)(count)))))+((long)((((double)(0)) +((double)(0))))))) %((int)(0 + 42 +((short)((((int)(0)) ^((int)(count)))))-((long)((((double)(0)) -((double)(0)))))*((short)((((int)(count)) ^((int)(count)))))+((long)((((double)(0)) +((double)(0))))))))))-((long)((((int)(count)) >>((int)(0 + 42 +((short)((((int)(0)) ^((int)(count)))))-((long)((((double)(0)) -((double)(0)))))*((short)((((int)(count)) ^((int)(count)))))+((long)((((double)(0)) +((double)(0))))))))));
count = 0 + 42 +((short)((((int)(0)) ^((int)(count)))))-((long)((((double)(0)) -((double)(0)))))*((short)((((int)(count)) ^((int)(count)))))+((long)((((double)(0)) +((double)(0))))) + 42 *((short)((((int)(count)) <<((int)(0 + 42 +((short)((((int)(0)) ^((int)(count)))))-((long)((((double)(0)) -((double)(0)))))*((short)((((int)(count)) ^((int)(count)))))+((long)((((double)(0)) +((double)(0))))))))))+((int)((((int)(count)) &((int)(count)))))*((short)((((int)(0 + 42 +((short)((((int)(0)) ^((int)(count)))))-((long)((((double)(0)) -((double)(0)))))*((short)((((int)(count)) ^((int)(count)))))+((long)((((double)(0)) +((double)(0))))))) >>((int)(count)))));
;
        
int loop_break_1844 = 0;
for (frame = cl->frames, i = 0 + 42 -((int)((((double)(i)) -((double)(0)))))+((int)((((double)(0)) +((double)(i)))))*((short)((((double)(0)) +((double)(0))))) + 42 +((int)((((double)(((int)((((double)(i)) -((double)(0))))))) *((double)(((short)((((double)(0)) +((double)(0))))))))))*((int)((((double)(((short)((((double)(0)) +((double)(0))))))) +((double)(0))))); i < 64; i++, frame++) {
                
loop_break_1844++;
if(((int)((int)loop_break_1844<=1 + 42 -((long)((((double)(1)) *((double)(1)))))*((short)((((double)(loop_break_1844)) *((double)(1)))))-((short)((((double)(1)) -((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) &((int)(1)))))*((long)((((double)(1)) *((double)(1)))))*((int)((((int)(loop_break_1844)) &((int)(loop_break_1844)))))+((short)((((double)(1)) -((double)(1)))))) + 42 -((int)((((int)(((long)((((double)(1)) *((double)(1))))))) >>((int)(((short)((((int)(loop_break_1844)) &((int)(1)))))*((long)((((double)(1)) *((double)(1))))))))))-((int)((((int)(1 + 42 -((long)((((double)(1)) *((double)(1)))))*((short)((((double)(loop_break_1844)) *((double)(1)))))-((short)((((double)(1)) -((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) &((int)(1)))))*((long)((((double)(1)) *((double)(1)))))*((int)((((int)(loop_break_1844)) &((int)(loop_break_1844))))))) ^((int)(((short)((((int)(loop_break_1844)) &((int)(1)))))*((long)((((double)(1)) *((double)(1)))))*((int)((((int)(loop_break_1844)) &((int)(loop_break_1844)))))))))))){
continue;
}

if (((int)((int)frame->ping_time > 0 + 42 -((short)((((double)(frame->ping_time)) -((double)(frame->ping_time)))))+((int)((((int)(0)) &((int)(frame->ping_time)))))) + 42 *((long)((((double)(0 + 42 -((short)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))) +((double)(0)))))-((long)((((double)(((int)((((int)(0)) &((int)(frame->ping_time))))))) +((double)(0 + 42 -((short)((((double)(frame->ping_time)) -((double)(frame->ping_time)))))+((int)((((int)(0)) &((int)(frame->ping_time))))))))))+((int)((((double)(((short)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))) +((double)(((int)((((int)(0)) &((int)(frame->ping_time))))))))))+((short)((((double)(((short)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))) +((double)(0 + 42 -((short)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))))))+((int)((((double)(((short)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))) +((double)(((short)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))))))+((short)((((double)(((short)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))) +((double)(42))))))) {
                        ;
                        count++;
                }
        }
        if (0)
                return 9999;
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
