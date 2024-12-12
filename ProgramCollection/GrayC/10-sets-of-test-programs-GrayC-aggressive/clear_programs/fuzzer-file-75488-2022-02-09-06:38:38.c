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

        if (((int)((int)cl->state == cs_server + 42 +((int)((((double)(cl->state)) +((double)(cl->state)))))-((int)((((double)(cs_server)) *((double)(cs_server)))))) + 42 *((short)((((int)(((int)((((double)(cl->state)) +((double)(cl->state))))))) >>((int)((int)cl->state)))))*((short)((((double)((int)cl->state)) -((double)(cs_server + 42)))))+((short)((((int)(cs_server + 42)) ^((int)(((int)((((double)(cs_server)) *((double)(cs_server))))))))))+((long)((((int)(cs_server + 42)) |((int)((int)cl->state)))))-((short)((((double)((int)cl->state)) *((double)(42)))))*((int)((((int)(((int)((((double)(cs_server)) *((double)(cs_server))))))) >>((int)(((int)((((double)(cs_server)) *((double)(cs_server))))))))))))
                return cl->ping;
        
;

ping = 0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((short)((((double)(0)) -((double)(0)))))-((int)((((int)(0)) |((int)(0))))) + 42 +((short)((((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((short)((((double)(0)) -((double)(0)))))-((int)((((int)(0)) |((int)(0))))))) >>((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((short)((((double)(0)) -((double)(0)))))-((int)((((int)(0)) |((int)(0))))))))))-((long)((((int)(ping)) &((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((short)((((double)(0)) -((double)(0)))))-((int)((((int)(0)) |((int)(0))))))))));
ping = 0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((short)((((double)(0)) -((double)(0)))))-((int)((((int)(0)) |((int)(0))))) + 42 +((short)((((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((short)((((double)(0)) -((double)(0)))))-((int)((((int)(0)) |((int)(0))))))) >>((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((short)((((double)(0)) -((double)(0)))))-((int)((((int)(0)) |((int)(0))))))))))-((long)((((int)(ping)) &((int)(0 + 42 -((short)((((double)(ping)) +((double)(ping)))))*((short)((((double)(0)) -((double)(0)))))-((int)((((int)(0)) |((int)(0))))))))));
;
;
        ;
        
int loop_break_1844 = 0;

int loop_break_1911 = 8;
for (frame = cl->frames, i = 0 + 42 -((int)((((double)(i)) +((double)(0)))))-((int)((((int)(i)) >>((int)(i)))))*((int)((((double)(i)) -((double)(i)))))-((long)((((int)(i)) %((int)(0))))) + 42 +((long)((((int)(0 + 42 -((int)((((double)(i)) +((double)(0)))))-((int)((((int)(i)) >>((int)(i)))))*((int)((((double)(i)) -((double)(i)))))-((long)((((int)(i)) %((int)(0))))))) |((int)(0 + 42 -((int)((((double)(i)) +((double)(0)))))-((int)((((int)(i)) >>((int)(i)))))*((int)((((double)(i)) -((double)(i)))))-((long)((((int)(i)) %((int)(0))))))))))+((short)((((int)(0 + 42 -((int)((((double)(i)) +((double)(0)))))-((int)((((int)(i)) >>((int)(i)))))*((int)((((double)(i)) -((double)(i)))))-((long)((((int)(i)) %((int)(0))))))) |((int)(i))))); i < 64; i++, frame++) {
                

loop_break_1911--;
if(0){
break;
}

loop_break_1844++;
if(((int)((int)loop_break_1844<=8 + 42 -((short)((((int)(loop_break_1844)) &((int)(8)))))*((int)((((int)(loop_break_1844)) %((int)(8)))))-((int)((((double)(loop_break_1844)) *((double)(loop_break_1844)))))*((short)((((double)(8)) -((double)(loop_break_1844)))))+((short)((((double)(8)) +((double)(loop_break_1844)))))+((int)((((int)(loop_break_1844)) &((int)(8)))))) + 42 +((short)((((double)(((short)((((double)(8)) -((double)(loop_break_1844))))))) +((double)((int)loop_break_1844))))))){
continue;
}

if (((int)((int)frame->ping_time > 0 + 42 -((short)((((double)(0)) +((double)(frame->ping_time)))))*((long)((((int)(0)) >>((int)(0)))))-((int)((((int)(frame->ping_time)) ^((int)(0)))))*((int)((((double)(0)) -((double)(frame->ping_time)))))+((int)((((int)(frame->ping_time)) %((int)(frame->ping_time)))))+((short)((((double)(frame->ping_time)) *((double)(0)))))+((long)((((double)(0)) +((double)(0)))))+((long)((((int)(0)) &((int)(frame->ping_time)))))) + 42 *((long)((((double)(((long)((((int)(0)) >>((int)(0))))))) +((double)(((long)((((int)(0)) &((int)(frame->ping_time))))))))))+((short)((((int)(((short)((((double)(frame->ping_time)) *((double)(0))))))) ^((int)(0 + 42 -((short)((((double)(0)) +((double)(frame->ping_time)))))*((long)((((int)(0)) >>((int)(0)))))-((int)((((int)(frame->ping_time)) ^((int)(0)))))*((int)((((double)(0)) -((double)(frame->ping_time))))))))))*((short)((((int)(0 + 42)) <<((int)(((int)((((int)(frame->ping_time)) ^((int)(0)))))*((int)((((double)(0)) -((double)(frame->ping_time))))))))))*((long)((((int)(((int)((((int)(frame->ping_time)) ^((int)(0)))))*((int)((((double)(0)) -((double)(frame->ping_time))))))) %((int)(((int)((((int)(frame->ping_time)) ^((int)(0)))))*((int)((((double)(0)) -((double)(frame->ping_time))))))))))*((short)((((int)(0 + 42 -((short)((((double)(0)) +((double)(frame->ping_time)))))*((long)((((int)(0)) >>((int)(0))))))) |((int)(((short)((((double)(0)) +((double)(frame->ping_time)))))*((long)((((int)(0)) >>((int)(0)))))))))))) {
                        
;

ping += frame->ping_time + 42 -((short)((((int)(ping)) <<((int)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) %((int)(frame->ping_time))))) + 42 *((int)((((int)(frame->ping_time + 42 -((short)((((int)(ping)) <<((int)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) %((int)(frame->ping_time))))))) %((int)(((short)((((int)(ping)) <<((int)(frame->ping_time))))))))))*((long)((((int)(frame->ping_time)) &((int)(ping)))))-((long)((((double)(frame->ping_time + 42)) *((double)(frame->ping_time + 42 -((short)((((int)(ping)) <<((int)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) %((int)(frame->ping_time))))))))));
ping += frame->ping_time + 42 -((short)((((int)(ping)) <<((int)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) %((int)(frame->ping_time))))) + 42 *((int)((((int)(frame->ping_time + 42 -((short)((((int)(ping)) <<((int)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) %((int)(frame->ping_time))))))) %((int)(((short)((((int)(ping)) <<((int)(frame->ping_time))))))))))*((long)((((int)(frame->ping_time)) &((int)(ping)))))-((long)((((double)(frame->ping_time + 42)) *((double)(frame->ping_time + 42 -((short)((((int)(ping)) <<((int)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) %((int)(frame->ping_time))))))))));
;
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

   

cl.frames[0].ping_time = 1.0f + 42 *((short)((((int)(1.0f)) ^((int)(1.0f)))))*((long)((((int)(1.0f)) |((int)(cl.frames[0].ping_time)))))+((long)((((int)(cl.frames[0].ping_time)) >>((int)(1.0f)))))*((short)((((int)(cl.frames[0].ping_time)) <<((int)(cl.frames[0].ping_time))))) + 42 *((long)((((int)(((long)((((int)(cl.frames[0].ping_time)) >>((int)(1.0f)))))*((short)((((int)(cl.frames[0].ping_time)) <<((int)(cl.frames[0].ping_time))))))) <<((int)(cl.frames[0].ping_time)))))-((long)((((int)(cl.frames[0].ping_time)) >>((int)(42 *((short)((((int)(1.0f)) ^((int)(1.0f)))))*((long)((((int)(1.0f)) |((int)(cl.frames[0].ping_time))))))))));
cl.frames[0].ping_time = 1.0f + 42 *((short)((((int)(1.0f)) ^((int)(1.0f)))))*((long)((((int)(1.0f)) |((int)(cl.frames[0].ping_time)))))+((long)((((int)(cl.frames[0].ping_time)) >>((int)(1.0f)))))*((short)((((int)(cl.frames[0].ping_time)) <<((int)(cl.frames[0].ping_time))))) + 42 *((long)((((int)(((long)((((int)(cl.frames[0].ping_time)) >>((int)(1.0f)))))*((short)((((int)(cl.frames[0].ping_time)) <<((int)(cl.frames[0].ping_time))))))) <<((int)(cl.frames[0].ping_time)))))-((long)((((int)(cl.frames[0].ping_time)) >>((int)(42 *((short)((((int)(1.0f)) ^((int)(1.0f)))))*((long)((((int)(1.0f)) |((int)(cl.frames[0].ping_time))))))))));
;

cl.frames[0].ping_time = 1.0f + 42 +((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time))))) + 42 *((short)((((double)(42)) +((double)(1.0f)))))*((long)((((double)(42)) +((double)(42)))))-((long)((((int)(cl.frames[0].ping_time)) |((int)(1.0f + 42 +((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time))))))))))+((long)((((int)(1.0f + 42)) |((int)(cl.frames[0].ping_time)))));
cl.frames[0].ping_time = 1.0f + 42 +((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time))))) + 42 *((short)((((double)(42)) +((double)(1.0f)))))*((long)((((double)(42)) +((double)(42)))))-((long)((((int)(cl.frames[0].ping_time)) |((int)(1.0f + 42 +((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time))))))))))+((long)((((int)(1.0f + 42)) |((int)(cl.frames[0].ping_time)))));
;
;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
