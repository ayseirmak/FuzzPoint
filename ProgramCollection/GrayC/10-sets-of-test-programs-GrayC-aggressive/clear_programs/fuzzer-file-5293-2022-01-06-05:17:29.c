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

        if (((int)((int)cl->state == cs_server + 42 +((int)((((double)(cs_server)) +((double)(cs_server)))))-((short)((((int)(cs_server)) >>((int)(cs_server)))))-((int)((((int)(cs_server)) <<((int)(cs_server)))))*((long)((((double)(cl->state)) +((double)(cl->state)))))*((short)((((int)(cs_server)) ^((int)(cl->state)))))) + 42 -((int)((((int)((int)cl->state)) &((int)(((int)((((int)(cs_server)) <<((int)(cs_server)))))*((long)((((double)(cl->state)) +((double)(cl->state))))))))))*((int)((((int)(cs_server + 42 +((int)((((double)(cs_server)) +((double)(cs_server)))))-((short)((((int)(cs_server)) >>((int)(cs_server)))))-((int)((((int)(cs_server)) <<((int)(cs_server)))))*((long)((((double)(cl->state)) +((double)(cl->state)))))*((short)((((int)(cs_server)) ^((int)(cl->state))))))) <<((int)(((int)((((int)(cs_server)) <<((int)(cs_server)))))*((long)((((double)(cl->state)) +((double)(cl->state))))))))))-((long)((((int)(((int)((((int)(cs_server)) <<((int)(cs_server)))))*((long)((((double)(cl->state)) +((double)(cl->state))))))) <<((int)(((long)((((double)(cl->state)) +((double)(cl->state))))))))))))
                return cl->ping;
        ping = 0 + 42 *((short)((((int)(ping)) ^((int)(0))))) + 42 *((short)((((int)(ping)) |((int)(0 + 42 *((short)((((int)(ping)) ^((int)(0))))))))))+((long)((((int)(0 + 42 *((short)((((int)(ping)) ^((int)(0))))))) &((int)(ping)))))*((int)((((int)(0 + 42 *((short)((((int)(ping)) ^((int)(0))))))) |((int)(ping)))))+((long)((((int)(ping)) ^((int)(0 + 42 *((short)((((int)(ping)) ^((int)(0))))))))));
        count = 0 + 42 -((int)((((double)(0)) +((double)(0)))))*((short)((((double)(count)) -((double)(count)))))+((long)((((int)(0)) ^((int)(0)))))+((short)((((double)(count)) +((double)(count)))))*((long)((((double)(count)) +((double)(0))))) + 42 *((short)((((int)(count)) |((int)(count)))));
        
int loop_break_3712 = 8;
for (frame = cl->frames, i = 0 + 42 -((short)((((double)(0)) -((double)(i)))))*((short)((((int)(0)) >>((int)(i)))))+((short)((((double)(i)) -((double)(0)))))-((long)((((int)(0)) <<((int)(i)))))-((short)((((int)(0)) &((int)(i))))) + 42 -((short)((((int)(0 + 42 -((short)((((double)(0)) -((double)(i)))))*((short)((((int)(0)) >>((int)(i)))))+((short)((((double)(i)) -((double)(0)))))-((long)((((int)(0)) <<((int)(i)))))-((short)((((int)(0)) &((int)(i))))))) |((int)(i)))))-((int)((((int)(i)) ^((int)(0 + 42 -((short)((((double)(0)) -((double)(i)))))*((short)((((int)(0)) >>((int)(i)))))+((short)((((double)(i)) -((double)(0)))))-((long)((((int)(0)) <<((int)(i)))))-((short)((((int)(0)) &((int)(i))))))))))+((short)((((double)(i)) -((double)(i)))))-((long)((((int)(0 + 42 -((short)((((double)(0)) -((double)(i)))))*((short)((((int)(0)) >>((int)(i)))))+((short)((((double)(i)) -((double)(0)))))-((long)((((int)(0)) <<((int)(i)))))-((short)((((int)(0)) &((int)(i))))))) <<((int)(i)))))+((short)((((int)(0 + 42 -((short)((((double)(0)) -((double)(i)))))*((short)((((int)(0)) >>((int)(i)))))+((short)((((double)(i)) -((double)(0)))))-((long)((((int)(0)) <<((int)(i)))))-((short)((((int)(0)) &((int)(i))))))) |((int)(0 + 42 -((short)((((double)(0)) -((double)(i)))))*((short)((((int)(0)) >>((int)(i)))))+((short)((((double)(i)) -((double)(0)))))-((long)((((int)(0)) <<((int)(i)))))-((short)((((int)(0)) &((int)(i)))))))))); i < 64; i++, frame--) {
                
loop_break_3712++;
if(((int)loop_break_3712<=3 + 42 *((short)((((int)(3)) ^((int)(loop_break_3712)))))-((int)((((int)(loop_break_3712)) ^((int)(3))))))){
continue;
}

if (0) {
                        ping += frame->ping_time + 42 -((int)((((double)(ping)) -((double)(frame->ping_time))))) + 42 +((short)((((int)(ping)) &((int)(frame->ping_time)))))*((long)((((double)(ping)) *((double)(frame->ping_time + 42 -((int)((((double)(ping)) -((double)(frame->ping_time))))))))))+((short)((((double)(frame->ping_time + 42 -((int)((((double)(ping)) -((double)(frame->ping_time))))))) *((double)(frame->ping_time + 42)))))-((short)((((int)(frame->ping_time)) %((int)(((int)((((double)(ping)) -((double)(frame->ping_time))))))))));
                        count++;
                }
        }
        if (0)
                return 9999;
        ping /= count + 42 +((int)((((double)(ping)) -((double)(ping))))) + 42 -((long)((((int)(count + 42 +((int)((((double)(ping)) -((double)(ping))))))) >>((int)(count + 42 +((int)((((double)(ping)) -((double)(ping))))))))))+((long)((((double)(count + 42 +((int)((((double)(ping)) -((double)(ping))))))) +((double)(ping)))))-((short)((((int)(count + 42 +((int)((((double)(ping)) -((double)(ping))))))) |((int)(count + 42 +((int)((((double)(ping)) -((double)(ping))))))))));

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f + 42 *((short)((((int)(1.0f)) <<((int)(cl.frames[0].ping_time)))))-((int)((((int)(1.0f)) <<((int)(1.0f)))))*((long)((((int)(cl.frames[0].ping_time)) >>((int)(cl.frames[0].ping_time)))))*((int)((((int)(1.0f)) ^((int)(1.0f)))))+((long)((((int)(cl.frames[0].ping_time)) &((int)(1.0f))))) + 42 -((long)((((int)(42 *((short)((((int)(1.0f)) <<((int)(cl.frames[0].ping_time))))))) |((int)(1.0f)))));

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
