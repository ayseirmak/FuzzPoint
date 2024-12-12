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
        ;
        
count = 0 + 42 *((short)((((int)(0)) &((int)(0))))) + 42 *((int)((((double)(42)) +((double)(((short)((((int)(0)) &((int)(0))))))))));
count = 0 + 42 -((long)((((int)(count)) <<((int)(0)))))*((int)((((int)(count)) <<((int)(0)))))+((int)((((int)(0)) <<((int)(0))))) + 42 -((short)((((int)(count)) ^((int)(count)))))*((int)((((int)(0 + 42 -((long)((((int)(count)) <<((int)(0)))))*((int)((((int)(count)) <<((int)(0)))))+((int)((((int)(0)) <<((int)(0))))))) >>((int)(count)))))+((int)((((int)(count)) %((int)(count)))))+((short)((((int)(count)) |((int)(count)))))-((int)((((double)(count)) +((double)(count)))));
;
        
int loop_break_1844 = 0;
for (frame = cl->frames, i = 0 + 42 -((int)((((double)(0)) *((double)(i)))))*((int)((((int)(i)) <<((int)(0))))) + 42 *((long)((((int)(i)) >>((int)(((int)((((int)(i)) <<((int)(0))))))))))+((int)((((int)(i)) |((int)(i)))))*((long)((((int)(0 + 42)) <<((int)(0 + 42 -((int)((((double)(0)) *((double)(i)))))*((int)((((int)(i)) <<((int)(0))))))))))-((long)((((int)(0 + 42 -((int)((((double)(0)) *((double)(i)))))*((int)((((int)(i)) <<((int)(0))))))) <<((int)(0 + 42 -((int)((((double)(0)) *((double)(i)))))*((int)((((int)(i)) <<((int)(0)))))))))); i < 64; i++, frame--) {
                
loop_break_1844++;
if(((int)((int)loop_break_1844<=7 + 42 -((long)((((int)(loop_break_1844)) &((int)(loop_break_1844)))))) + 42 *((long)((((int)((int)loop_break_1844)) <<((int)(7 + 42 -((long)((((int)(loop_break_1844)) &((int)(loop_break_1844))))))))))*((short)((((int)((int)loop_break_1844)) <<((int)(((long)((((int)(loop_break_1844)) &((int)(loop_break_1844))))))))))*((int)((((double)(((long)((((int)(loop_break_1844)) &((int)(loop_break_1844))))))) -((double)((int)loop_break_1844)))))*((short)((((double)((int)loop_break_1844)) +((double)((int)loop_break_1844))))))){
continue;
}

if (((int)((int)frame->ping_time > 0 + 42 -((short)((((double)(frame->ping_time)) *((double)(0)))))*((int)((((int)(frame->ping_time)) &((int)(0)))))) + 42 -((int)((((int)(((short)((((double)(frame->ping_time)) *((double)(0))))))) %((int)(((int)((((int)(frame->ping_time)) &((int)(0))))))))))-((long)((((int)(0 + 42 -((short)((((double)(frame->ping_time)) *((double)(0)))))*((int)((((int)(frame->ping_time)) &((int)(0))))))) ^((int)(0 + 42))))))) {
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

   ;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
