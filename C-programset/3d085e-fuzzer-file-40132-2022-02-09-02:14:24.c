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

        if (((int)((int)cl->state == cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))-((int)((((int)(cl->state)) %((int)(cl->state)))))+((long)((((double)(cl->state)) +((double)(cs_server)))))-((int)((((int)(cl->state)) >>((int)(cs_server)))))) + 42 +((long)((((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))-((int)((((int)(cl->state)) %((int)(cl->state)))))+((long)((((double)(cl->state)) +((double)(cs_server))))))) >>((int)(((long)((((int)(cl->state)) ^((int)(cs_server))))))))))+((long)((((int)(((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server))))))) &((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))-((int)((((int)(cl->state)) %((int)(cl->state))))))))))+((short)((((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server))))))) ^((int)(((int)((((int)(cl->state)) %((int)(cl->state))))))))))-((long)((((double)(((long)((((double)(cs_server)) -((double)(cs_server))))))) *((double)(((long)((((double)(cl->state)) +((double)(cs_server))))))))))-((short)((((double)(((int)((((int)(cl->state)) %((int)(cl->state))))))) *((double)(((long)((((int)(cl->state)) ^((int)(cs_server))))))))))-((long)((((double)(((long)((((int)(cl->state)) ^((int)(cs_server))))))) -((double)(((long)((((double)(cs_server)) -((double)(cs_server))))))))))-((int)((((int)(((long)((((double)(cs_server)) -((double)(cs_server))))))) %((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server))))))))))-((int)((((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))-((int)((((int)(cl->state)) %((int)(cl->state)))))+((long)((((double)(cl->state)) +((double)(cs_server)))))-((int)((((int)(cl->state)) >>((int)(cs_server))))))) ^((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))-((int)((((int)(cl->state)) %((int)(cl->state))))))))))*((int)((((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server))))))) ^((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))-((int)((((int)(cl->state)) %((int)(cl->state)))))+((long)((((double)(cl->state)) +((double)(cs_server)))))-((int)((((int)(cl->state)) >>((int)(cs_server))))))))))+((int)((((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state))))))) <<((int)(cs_server + 42 +((int)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((int)(cs_server)) &((int)(cl->state)))))+((long)((((double)(cs_server)) -((double)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))-((int)((((int)(cl->state)) %((int)(cl->state)))))+((long)((((double)(cl->state)) +((double)(cs_server)))))-((int)((((int)(cl->state)) >>((int)(cs_server))))))))))))
                return cl->ping;
        
ping = 0 + 42 *((short)((((int)(0)) &((int)(ping)))))-((short)((((int)(0)) ^((int)(ping)))))+((short)((((int)(0)) %((int)(0)))))-((long)((((double)(ping)) +((double)(ping))))) + 42 *((short)((((int)(ping)) ^((int)(0 + 42 *((short)((((int)(0)) &((int)(ping)))))-((short)((((int)(0)) ^((int)(ping)))))+((short)((((int)(0)) %((int)(0)))))-((long)((((double)(ping)) +((double)(ping))))))))));
ping = 0 + 42 *((int)((((double)(0)) -((double)(0)))))*((int)((((int)(ping)) <<((int)(ping)))))-((long)((((double)(ping)) *((double)(0)))))*((int)((((double)(ping)) *((double)(ping))))) + 42 -((long)((((int)(0 + 42 *((int)((((double)(0)) -((double)(0)))))*((int)((((int)(ping)) <<((int)(ping)))))-((long)((((double)(ping)) *((double)(0)))))*((int)((((double)(ping)) *((double)(ping))))))) ^((int)(ping)))));
;
        ;
        
int loop_break_1844 = 0;

int loop_break_1911 = 0;
for (frame = cl->frames, i = 0 + 42 *((int)((((double)(i)) -((double)(0)))))*((short)((((double)(0)) +((double)(i)))))+((long)((((double)(0)) *((double)(0)))))+((short)((((double)(0)) +((double)(0))))) + 42 *((short)((((int)(0 + 42 *((int)((((double)(i)) -((double)(0)))))*((short)((((double)(0)) +((double)(i)))))+((long)((((double)(0)) *((double)(0)))))+((short)((((double)(0)) +((double)(0))))))) &((int)(i)))))+((int)((((int)(0 + 42 *((int)((((double)(i)) -((double)(0)))))*((short)((((double)(0)) +((double)(i)))))+((long)((((double)(0)) *((double)(0)))))+((short)((((double)(0)) +((double)(0))))))) <<((int)(0 + 42 *((int)((((double)(i)) -((double)(0)))))*((short)((((double)(0)) +((double)(i)))))+((long)((((double)(0)) *((double)(0)))))+((short)((((double)(0)) +((double)(0))))))))))+((int)((((int)(i)) %((int)(i)))))*((int)((((int)(0 + 42 *((int)((((double)(i)) -((double)(0)))))*((short)((((double)(0)) +((double)(i)))))+((long)((((double)(0)) *((double)(0)))))+((short)((((double)(0)) +((double)(0))))))) <<((int)(0 + 42 *((int)((((double)(i)) -((double)(0)))))*((short)((((double)(0)) +((double)(i)))))+((long)((((double)(0)) *((double)(0)))))+((short)((((double)(0)) +((double)(0))))))))))*((short)((((int)(i)) &((int)(0 + 42 *((int)((((double)(i)) -((double)(0)))))*((short)((((double)(0)) +((double)(i)))))+((long)((((double)(0)) *((double)(0)))))+((short)((((double)(0)) +((double)(0)))))))))); i < 64; i++, frame++) {
                

loop_break_1911++;
if(((int)((int)loop_break_1911<=3 + 42 *((long)((((double)(loop_break_1911)) -((double)(loop_break_1911)))))-((int)((((int)(3)) <<((int)(3)))))+((short)((((int)(3)) %((int)(3)))))-((short)((((int)(3)) %((int)(3)))))-((long)((((int)(3)) |((int)(3)))))) + 42 *((int)((((double)(((long)((((int)(3)) |((int)(3))))))) +((double)(((int)((((int)(3)) <<((int)(3)))))))))))){
break;
}

loop_break_1844++;
if(((int)((int)loop_break_1844<=8 + 42 *((int)((((double)(loop_break_1844)) -((double)(8)))))-((int)((((double)(8)) *((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) <<((int)(loop_break_1844)))))+((long)((((int)(loop_break_1844)) >>((int)(8)))))*((int)((((double)(loop_break_1844)) +((double)(8)))))*((short)((((int)(8)) |((int)(8)))))+((long)((((int)(8)) %((int)(8)))))+((long)((((int)(loop_break_1844)) %((int)(loop_break_1844)))))) + 42 +((int)((((int)(8 + 42 *((int)((((double)(loop_break_1844)) -((double)(8)))))-((int)((((double)(8)) *((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) <<((int)(loop_break_1844))))))) <<((int)(((long)((((int)(loop_break_1844)) >>((int)(8)))))*((int)((((double)(loop_break_1844)) +((double)(8)))))*((short)((((int)(8)) |((int)(8))))))))))+((long)((((int)(((short)((((int)(8)) |((int)(8))))))) |((int)(((long)((((int)(loop_break_1844)) >>((int)(8)))))*((int)((((double)(loop_break_1844)) +((double)(8)))))*((short)((((int)(8)) |((int)(8))))))))))*((short)((((int)(((long)((((int)(loop_break_1844)) >>((int)(8)))))*((int)((((double)(loop_break_1844)) +((double)(8))))))) ^((int)((int)loop_break_1844)))))+((short)((((int)(((long)((((int)(loop_break_1844)) %((int)(loop_break_1844))))))) %((int)(((long)((((int)(loop_break_1844)) >>((int)(8))))))))))*((int)((((int)(8 + 42 *((int)((((double)(loop_break_1844)) -((double)(8)))))-((int)((((double)(8)) *((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) <<((int)(loop_break_1844)))))+((long)((((int)(loop_break_1844)) >>((int)(8)))))*((int)((((double)(loop_break_1844)) +((double)(8)))))*((short)((((int)(8)) |((int)(8)))))+((long)((((int)(8)) %((int)(8)))))+((long)((((int)(loop_break_1844)) %((int)(loop_break_1844))))))) &((int)(((long)((((int)(loop_break_1844)) >>((int)(8))))))))))+((long)((((int)(((long)((((int)(8)) %((int)(8))))))) <<((int)(((long)((((int)(loop_break_1844)) >>((int)(8)))))*((int)((((double)(loop_break_1844)) +((double)(8))))))))))+((short)((((double)((int)loop_break_1844)) -((double)(((long)((((int)(loop_break_1844)) >>((int)(8)))))))))))){
continue;
}

if (((int)((int)frame->ping_time > 0 + 42 +((int)((((int)(frame->ping_time)) ^((int)(0)))))) + 42 +((short)((((double)(0 + 42 +((int)((((int)(frame->ping_time)) ^((int)(0))))))) -((double)(((int)((((int)(frame->ping_time)) ^((int)(0))))))))))+((long)((((double)(0 + 42)) -((double)(0)))))-((long)((((int)(42)) &((int)(42)))))*((int)((((int)(((int)((((int)(frame->ping_time)) ^((int)(0))))))) <<((int)(0 + 42)))))-((short)((((int)(0 + 42 +((int)((((int)(frame->ping_time)) ^((int)(0))))))) <<((int)(0)))))-((int)((((int)(42)) >>((int)(0 + 42 +((int)((((int)(frame->ping_time)) ^((int)(0))))))))))-((short)((((double)((int)frame->ping_time)) *((double)((int)frame->ping_time)))))*((short)((((double)(0 + 42)) +((double)(0 + 42 +((int)((((int)(frame->ping_time)) ^((int)(0))))))))))+((long)((((double)(0 + 42)) +((double)((int)frame->ping_time))))))) {
                        
ping += frame->ping_time + 42 *((long)((((int)(frame->ping_time)) >>((int)(frame->ping_time)))))+((short)((((double)(ping)) *((double)(ping)))))+((int)((((int)(frame->ping_time)) <<((int)(ping)))))+((short)((((int)(ping)) %((int)(frame->ping_time))))) + 42 +((long)((((int)(frame->ping_time)) |((int)(42 *((long)((((int)(frame->ping_time)) >>((int)(frame->ping_time))))))))))-((short)((((int)(frame->ping_time + 42 *((long)((((int)(frame->ping_time)) >>((int)(frame->ping_time)))))+((short)((((double)(ping)) *((double)(ping)))))+((int)((((int)(frame->ping_time)) <<((int)(ping)))))+((short)((((int)(ping)) %((int)(frame->ping_time))))))) &((int)(frame->ping_time + 42 *((long)((((int)(frame->ping_time)) >>((int)(frame->ping_time))))))))));
ping += frame->ping_time + 42 *((short)((((int)(ping)) >>((int)(ping)))))-((long)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) |((int)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) &((int)(frame->ping_time))))) + 42 +((short)((((int)(frame->ping_time + 42 *((short)((((int)(ping)) >>((int)(ping)))))-((long)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) |((int)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) &((int)(frame->ping_time))))))) <<((int)(42 *((short)((((int)(ping)) >>((int)(ping))))))))))*((long)((((double)(((long)((((int)(frame->ping_time)) &((int)(frame->ping_time))))))) +((double)(((long)((((int)(frame->ping_time)) &((int)(frame->ping_time))))))))))+((short)((((int)(((long)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) |((int)(frame->ping_time))))))) <<((int)(((long)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) |((int)(frame->ping_time))))))))))*((long)((((double)(ping)) *((double)(((long)((((int)(frame->ping_time)) &((int)(frame->ping_time))))))))));
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

   
cl.frames[0].ping_time = 1.0f + 42 *((long)((((int)(cl.frames[0].ping_time)) %((int)(1.0f)))))-((long)((((int)(cl.frames[0].ping_time)) |((int)(1.0f)))))+((short)((((int)(cl.frames[0].ping_time)) |((int)(cl.frames[0].ping_time)))))+((long)((((int)(cl.frames[0].ping_time)) <<((int)(cl.frames[0].ping_time)))))*((int)((((int)(cl.frames[0].ping_time)) |((int)(1.0f))))) + 42 *((int)((((int)(1.0f + 42 *((long)((((int)(cl.frames[0].ping_time)) %((int)(1.0f))))))) <<((int)(((long)((((int)(cl.frames[0].ping_time)) |((int)(1.0f))))))))))*((int)((((int)(((long)((((int)(cl.frames[0].ping_time)) <<((int)(cl.frames[0].ping_time)))))*((int)((((int)(cl.frames[0].ping_time)) |((int)(1.0f))))))) &((int)(cl.frames[0].ping_time)))))*((long)((((int)(1.0f)) <<((int)(((long)((((int)(cl.frames[0].ping_time)) |((int)(1.0f))))))))));
cl.frames[0].ping_time = 1.0f + 42 *((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))))-((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time)))))*((short)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((long)((((double)(1.0f)) -((double)(1.0f))))) + 42 +((short)((((int)(1.0f + 42 *((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f))))))) &((int)(1.0f + 42 *((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))))-((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time)))))*((short)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((long)((((double)(1.0f)) -((double)(1.0f))))))))))-((long)((((int)(cl.frames[0].ping_time)) &((int)(1.0f)))))+((int)((((int)(((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time)))))*((short)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((long)((((double)(1.0f)) -((double)(1.0f))))))) |((int)(1.0f)))))+((short)((((int)(1.0f + 42 *((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))))-((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time)))))*((short)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((long)((((double)(1.0f)) -((double)(1.0f))))))) >>((int)(cl.frames[0].ping_time)))))+((int)((((int)(cl.frames[0].ping_time)) >>((int)(((int)((((int)(1.0f)) &((int)(cl.frames[0].ping_time)))))*((short)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((long)((((double)(1.0f)) -((double)(1.0f))))))))));
;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
