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
        ping = 0 + 42 -((short)((((int)(ping)) <<((int)(ping)))))-((int)((((double)(ping)) +((double)(0)))))*((int)((((int)(0)) &((int)(ping)))));
        count = 0 + 42 +((int)((((int)(0)) |((int)(count)))))*((long)((((double)(count)) +((double)(count)))))+((int)((((int)(0)) <<((int)(0)))));
        
int loop_break_1782 = 8;

int loop_break_1849 = 8;
for (frame = cl->frames, i = 0 + 42 -((long)((((double)(0)) +((double)(0)))))+((int)((((int)(i)) <<((int)(0)))))*((short)((((int)(i)) %((int)(0))))); i < 64; i++, frame++) {
                

loop_break_1849++;
if(((int)loop_break_1849<=5 + 42 -((long)((((int)(loop_break_1849)) >>((int)(5)))))+((short)((((int)(loop_break_1849)) &((int)(5)))))+((long)((((double)(loop_break_1849)) *((double)(5)))))+((short)((((double)(5)) +((double)(loop_break_1849)))))+((long)((((double)(5)) *((double)(loop_break_1849)))))+((int)((((int)(5)) %((int)(5)))))-((long)((((double)(loop_break_1849)) *((double)(loop_break_1849)))))+((short)((((double)(loop_break_1849)) -((double)(5)))))*((short)((((double)(loop_break_1849)) +((double)(loop_break_1849)))))*((int)((((int)(5)) %((int)(loop_break_1849))))))){
break;
}

loop_break_1782++;
if(((int)loop_break_1782<=2 + 42 *((short)((((double)(2)) -((double)(2)))))+((long)((((double)(loop_break_1782)) -((double)(2)))))+((short)((((int)(2)) <<((int)(2)))))-((short)((((double)(loop_break_1782)) +((double)(2)))))+((short)((((int)(2)) <<((int)(loop_break_1782)))))-((short)((((int)(2)) |((int)(loop_break_1782)))))+((long)((((int)(loop_break_1782)) &((int)(loop_break_1782)))))-((short)((((int)(2)) &((int)(2))))))){
break;
}

if (0) {
                        ping += frame->ping_time + 42 *((int)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))-((int)((((int)(frame->ping_time)) &((int)(ping)))))-((int)((((int)(ping)) |((int)(ping)))))+((long)((((double)(frame->ping_time)) -((double)(ping)))))*((long)((((double)(frame->ping_time)) +((double)(ping)))));
                        count++;
                }
        }
        if (0)
                return 9999;
        ping /= count + 42 -((long)((((int)(count)) |((int)(count)))))-((long)((((int)(count)) ^((int)(count)))));

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f + 42 -((short)((((int)(cl.frames[0].ping_time)) >>((int)(1.0f)))))-((long)((((int)(1.0f)) |((int)(cl.frames[0].ping_time)))))+((short)((((double)(1.0f)) +((double)(1.0f)))))-((long)((((int)(1.0f)) &((int)(cl.frames[0].ping_time)))));

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
