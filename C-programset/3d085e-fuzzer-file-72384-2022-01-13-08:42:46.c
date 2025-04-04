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
        ping = 0 + 42 +((int)((((int)(0)) |((int)(0)))))*((long)((((double)(ping)) *((double)(0)))));
        count = 0 + 42 -((long)((((double)(count)) +((double)(count)))))*((short)((((int)(count)) |((int)(0)))));
        
int loop_break_1782 = 0;

int loop_break_3932 = 0;
for (frame = cl->frames, i = 0 + 42 *((int)((((int)(0)) |((int)(0)))))+((int)((((int)(i)) ^((int)(0)))))+((short)((((int)(0)) &((int)(0)))))*((short)((((double)(0)) -((double)(0)))))+((short)((((double)(i)) *((double)(i))))); i < 64; i++, frame++) {
                

loop_break_3932++;
if(loop_break_3932<=5){
continue;
}

loop_break_1782++;
if(((int)loop_break_1782<=4 + 42 *((int)((((double)(4)) +((double)(loop_break_1782)))))-((long)((((double)(loop_break_1782)) *((double)(4)))))-((int)((((int)(4)) %((int)(4)))))*((int)((((int)(4)) >>((int)(loop_break_1782)))))*((int)((((double)(4)) -((double)(loop_break_1782)))))+((short)((((double)(4)) -((double)(loop_break_1782)))))+((int)((((double)(4)) -((double)(4)))))+((long)((((double)(4)) *((double)(loop_break_1782))))))){
break;
}

if (0) {
                        ping += frame->ping_time + 42 *((long)((((int)(frame->ping_time)) >>((int)(ping)))))*((short)((((double)(frame->ping_time)) *((double)(frame->ping_time)))));
                        count++;
                }
        }
        if (!count)
                return 9999;
        ping /= count + 42 +((long)((((int)(count)) >>((int)(count)))))-((int)((((int)(ping)) <<((int)(ping)))))+((long)((((double)(ping)) +((double)(ping)))))-((short)((((double)(ping)) -((double)(count)))));

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f + 42 -((long)((((int)(cl.frames[0].ping_time)) <<((int)(cl.frames[0].ping_time)))))+((short)((((double)(1.0f)) *((double)(1.0f)))))+((int)((((double)(1.0f)) +((double)(1.0f)))));

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
