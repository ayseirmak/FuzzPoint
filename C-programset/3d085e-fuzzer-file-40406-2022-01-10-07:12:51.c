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
        ;
        
int loop_break_1751 = 0;
for (frame = cl->frames, i = 0 + 42 +((short)((((int)(0)) |((int)(0))))); i < 64; i++, frame++) {
                
loop_break_1751++;
if(((int)loop_break_1751<=4 + 42 +((short)((((double)(4)) -((double)(4)))))*((int)((((double)(4)) -((double)(loop_break_1751)))))+((short)((((int)(loop_break_1751)) >>((int)(loop_break_1751)))))-((short)((((double)(loop_break_1751)) +((double)(loop_break_1751)))))+((long)((((int)(4)) &((int)(loop_break_1751)))))+((long)((((int)(4)) <<((int)(4)))))+((long)((((int)(loop_break_1751)) <<((int)(4)))))-((long)((((double)(4)) *((double)(loop_break_1751)))))+((int)((((int)(4)) ^((int)(loop_break_1751))))))){
continue;
}

if (((int)frame->ping_time > 0 + 42 *((int)((((int)(frame->ping_time)) &((int)(frame->ping_time)))))-((short)((((double)(0)) *((double)(0)))))-((int)((((int)(0)) ^((int)(0)))))*((short)((((int)(frame->ping_time)) |((int)(0)))))-((long)((((double)(frame->ping_time)) +((double)(0)))))-((short)((((int)(frame->ping_time)) |((int)(0)))))-((long)((((int)(frame->ping_time)) %((int)(0)))))+((long)((((int)(frame->ping_time)) ^((int)(frame->ping_time)))))*((short)((((int)(frame->ping_time)) <<((int)(0)))))*((long)((((int)(0)) |((int)(0))))))) {
                        ;
                        count++;
                }
        }
        if (0)
                return 9999;
        
ping /= count + 42 *((short)((((int)(ping)) ^((int)(ping)))))+((short)((((double)(ping)) -((double)(count)))))*((int)((((double)(count)) *((double)(ping)))))+((long)((((double)(count)) *((double)(ping)))));
ping /= count + 42 +((long)((((int)(ping)) &((int)(count)))))+((long)((((double)(count)) *((double)(ping)))))+((long)((((double)(ping)) *((double)(count)))));
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
