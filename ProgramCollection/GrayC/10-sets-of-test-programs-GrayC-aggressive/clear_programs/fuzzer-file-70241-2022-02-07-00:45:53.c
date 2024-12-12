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
        ping = 0 + 42 +((long)((((double)(ping)) +((double)(ping))))) + 42 -((short)((((int)(0 + 42 +((long)((((double)(ping)) +((double)(ping))))))) &((int)(ping)))))+((long)((((double)(0 + 42 +((long)((((double)(ping)) +((double)(ping))))))) *((double)(0 + 42 +((long)((((double)(ping)) +((double)(ping))))))))));
        count = 0 + 42 -((short)((((int)(count)) %((int)(count))))) + 42 -((long)((((int)(0)) |((int)(42)))))+((int)((((int)(0 + 42 -((short)((((int)(count)) %((int)(count))))))) |((int)(count)))))-((short)((((int)(count)) %((int)(0 + 42 -((short)((((int)(count)) %((int)(count))))))))));
        
int loop_break_1844 = 0;

int loop_break_4559 = 0;

int loop_break_2497 = 0;

int loop_break_2570 = 0;
for (frame = cl->frames, i = 0 + 42 +((int)((((int)(0)) ^((int)(0))))) + 42 +((long)((((double)(0)) -((double)(i)))))+((short)((((double)(42)) *((double)(0 + 42 +((int)((((int)(0)) ^((int)(0)))))))))); i < 64; i++, frame++) {
                



loop_break_2570++;
if(((int)loop_break_2570<=2 + 42 *((short)((((double)(2)) *((double)(2))))))){
continue;
}

loop_break_2497++;
if(((int)loop_break_2497<=3 + 42 *((short)((((double)(3)) -((double)(3)))))-((int)((((int)(3)) |((int)(3)))))+((short)((((int)(loop_break_2497)) %((int)(loop_break_2497)))))*((short)((((double)(loop_break_2497)) *((double)(3)))))+((long)((((double)(loop_break_2497)) +((double)(loop_break_2497)))))-((int)((((double)(3)) *((double)(3)))))-((long)((((double)(loop_break_2497)) +((double)(loop_break_2497)))))*((short)((((int)(loop_break_2497)) |((int)(3)))))*((long)((((int)(loop_break_2497)) |((int)(loop_break_2497))))))){
continue;
}

loop_break_4559++;
if(0){
continue;
}

loop_break_1844++;
if(0){
continue;
}

if (0) {
                        ping += frame->ping_time + 42 -((short)((((int)(frame->ping_time)) >>((int)(ping)))))+((short)((((int)(ping)) ^((int)(frame->ping_time))))) + 42 *((int)((((int)(42)) >>((int)(((short)((((int)(frame->ping_time)) >>((int)(ping))))))))));
                        count++;
                }
        }
        if (0)
                return 9999;
        ping /= count + 42 -((short)((((int)(ping)) &((int)(count)))))+((int)((((double)(ping)) +((double)(count)))))-((short)((((double)(count)) *((double)(ping))))) + 42 +((short)((((int)(count + 42 -((short)((((int)(ping)) &((int)(count)))))+((int)((((double)(ping)) +((double)(count)))))-((short)((((double)(count)) *((double)(ping))))))) ^((int)(count + 42 -((short)((((int)(ping)) &((int)(count)))))+((int)((((double)(ping)) +((double)(count)))))-((short)((((double)(count)) *((double)(ping))))))))))+((long)((((int)(count + 42 -((short)((((int)(ping)) &((int)(count)))))+((int)((((double)(ping)) +((double)(count)))))-((short)((((double)(count)) *((double)(ping))))))) %((int)(ping)))))+((int)((((int)(ping)) ^((int)(ping)))))-((short)((((int)(ping)) >>((int)(ping)))))+((short)((((double)(ping)) +((double)(ping)))));

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f + 42 *((short)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time)))))*((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))))+((long)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((int)((((double)(1.0f)) -((double)(1.0f))))) + 42 +((int)((((int)(((long)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((int)((((double)(1.0f)) -((double)(1.0f))))))) ^((int)(((long)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((int)((((double)(1.0f)) -((double)(1.0f))))))))))+((int)((((int)(1.0f + 42 *((short)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time)))))*((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))))+((long)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((int)((((double)(1.0f)) -((double)(1.0f))))))) >>((int)(42 *((short)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time)))))*((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f))))))))))-((long)((((int)(((long)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((int)((((double)(1.0f)) -((double)(1.0f))))))) ^((int)(42 *((short)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time)))))*((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f))))))))));

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
