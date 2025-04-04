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

        if (((int)cl->state == cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))-((int)((((int)(cl->state)) %((int)(cl->state)))))+((long)((((double)(cl->state)) +((double)(cs_server)))))-((int)((((int)(cl->state)) >>((int)(cs_server)))))))
                return cl->ping;
        
ping = 0 + 42 *((short)((((int)(0)) &((int)(ping)))))-((short)((((int)(0)) ^((int)(ping)))))+((short)((((int)(0)) %((int)(0)))))-((long)((((double)(ping)) +((double)(ping)))));
ping = 0 + 42 *((int)((((double)(0)) -((double)(0)))))*((int)((((int)(ping)) <<((int)(ping)))))-((long)((((double)(ping)) *((double)(0)))))*((int)((((double)(ping)) *((double)(ping)))));
;
        ;
        
int loop_break_1844 = 0;

int loop_break_1911 = 0;
for (frame = cl->frames, i = 0 + 42 *((int)((((double)(i)) -((double)(0)))))*((short)((((double)(0)) +((double)(i)))))+((long)((((double)(0)) *((double)(0)))))+((short)((((double)(0)) +((double)(0))))); i < 64; i++, frame++) {
                

loop_break_1911++;
if(((int)loop_break_1911<=3 + 42 *((long)((((double)(loop_break_1911)) -((double)(loop_break_1911)))))-((int)((((int)(3)) <<((int)(3)))))+((short)((((int)(3)) %((int)(3)))))-((short)((((int)(3)) %((int)(3)))))-((long)((((int)(3)) |((int)(3))))))){
break;
}

loop_break_1844++;
if(((int)loop_break_1844<=8 + 42 *((int)((((double)(loop_break_1844)) -((double)(8)))))-((int)((((double)(8)) *((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) <<((int)(loop_break_1844)))))+((long)((((int)(loop_break_1844)) >>((int)(8)))))*((int)((((double)(loop_break_1844)) +((double)(8)))))*((short)((((int)(8)) |((int)(8)))))+((long)((((int)(8)) %((int)(8)))))+((long)((((int)(loop_break_1844)) %((int)(loop_break_1844))))))){
continue;
}

if (((int)frame->ping_time > 0 + 42 +((int)((((int)(frame->ping_time)) ^((int)(0))))))) {
                        
ping += frame->ping_time + 42 *((long)((((int)(frame->ping_time)) >>((int)(frame->ping_time)))))+((short)((((double)(ping)) *((double)(ping)))))+((int)((((int)(frame->ping_time)) <<((int)(ping)))))+((short)((((int)(ping)) %((int)(frame->ping_time)))));
ping += frame->ping_time + 42 *((short)((((int)(ping)) >>((int)(ping)))))-((long)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) |((int)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) &((int)(frame->ping_time)))));
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

   
cl.frames[0].ping_time = 1.0f + 42 *((long)((((int)(cl.frames[0].ping_time)) %((int)(1.0f)))))-((long)((((int)(cl.frames[0].ping_time)) |((int)(1.0f)))))+((short)((((int)(cl.frames[0].ping_time)) |((int)(cl.frames[0].ping_time)))))+((long)((((int)(cl.frames[0].ping_time)) <<((int)(cl.frames[0].ping_time)))))*((int)((((int)(cl.frames[0].ping_time)) |((int)(1.0f)))));
cl.frames[0].ping_time = 1.0f + 42 *((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))))-((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time)))))*((short)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((long)((((double)(1.0f)) -((double)(1.0f)))));
;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
