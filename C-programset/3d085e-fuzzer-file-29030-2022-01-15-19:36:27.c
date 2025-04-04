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
        ping = 0 + 42 *((long)((((double)(0)) -((double)(ping)))))+((short)((((int)(0)) %((int)(ping)))))*((int)((((int)(0)) ^((int)(ping))))) + 42 -((long)((((int)(0 + 42 *((long)((((double)(0)) -((double)(ping)))))+((short)((((int)(0)) %((int)(ping)))))*((int)((((int)(0)) ^((int)(ping))))))) %((int)(0 + 42 *((long)((((double)(0)) -((double)(ping)))))+((short)((((int)(0)) %((int)(ping)))))*((int)((((int)(0)) ^((int)(ping))))))))))-((short)((((int)(0 + 42 *((long)((((double)(0)) -((double)(ping)))))+((short)((((int)(0)) %((int)(ping)))))*((int)((((int)(0)) ^((int)(ping))))))) %((int)(ping)))))*((short)((((int)(0 + 42 *((long)((((double)(0)) -((double)(ping)))))+((short)((((int)(0)) %((int)(ping)))))*((int)((((int)(0)) ^((int)(ping))))))) <<((int)(0 + 42 *((long)((((double)(0)) -((double)(ping)))))+((short)((((int)(0)) %((int)(ping)))))*((int)((((int)(0)) ^((int)(ping))))))))))+((long)((((int)(0 + 42 *((long)((((double)(0)) -((double)(ping)))))+((short)((((int)(0)) %((int)(ping)))))*((int)((((int)(0)) ^((int)(ping))))))) >>((int)(0 + 42 *((long)((((double)(0)) -((double)(ping)))))+((short)((((int)(0)) %((int)(ping)))))*((int)((((int)(0)) ^((int)(ping))))))))));
        count = 0 + 42 *((long)((((double)(0)) +((double)(count)))))-((int)((((int)(count)) >>((int)(0))))) + 42 *((short)((((int)(0 + 42 *((long)((((double)(0)) +((double)(count)))))-((int)((((int)(count)) >>((int)(0))))))) >>((int)(count)))))+((short)((((double)(count)) +((double)(count)))))*((int)((((int)(count)) %((int)(0 + 42 *((long)((((double)(0)) +((double)(count)))))-((int)((((int)(count)) >>((int)(0))))))))))-((long)((((int)(0 + 42 *((long)((((double)(0)) +((double)(count)))))-((int)((((int)(count)) >>((int)(0))))))) &((int)(count)))))-((long)((((double)(count)) +((double)(count)))));
        
int loop_break_4980 = 0;

int loop_break_21425 = 0;
for (frame = cl->frames, i = 0 + 42 +((short)((((int)(0)) <<((int)(i)))))*((short)((((int)(0)) %((int)(i)))))-((short)((((int)(0)) >>((int)(0)))))+((short)((((double)(i)) +((double)(0))))) + 42 -((int)((((int)(42)) %((int)(0 + 42 +((short)((((int)(0)) <<((int)(i)))))*((short)((((int)(0)) %((int)(i))))))))))*((long)((((int)(0 + 42 +((short)((((int)(0)) <<((int)(i)))))*((short)((((int)(0)) %((int)(i)))))-((short)((((int)(0)) >>((int)(0))))))) <<((int)(((short)((((double)(i)) +((double)(0))))))))))+((int)((((int)(((short)((((int)(0)) %((int)(i))))))) |((int)(i)))))+((int)((((int)(((short)((((int)(0)) %((int)(i))))))) ^((int)(0 + 42 +((short)((((int)(0)) <<((int)(i)))))*((short)((((int)(0)) %((int)(i))))))))))-((int)((((int)(0 + 42 +((short)((((int)(0)) <<((int)(i)))))*((short)((((int)(0)) %((int)(i)))))-((short)((((int)(0)) >>((int)(0))))))) <<((int)(0 + 42 +((short)((((int)(0)) <<((int)(i)))))*((short)((((int)(0)) %((int)(i)))))-((short)((((int)(0)) >>((int)(0)))))+((short)((((double)(i)) +((double)(0)))))))))); i < 64; i++, frame++) {
                

loop_break_21425++;
if(loop_break_21425<=1){
break;
}

loop_break_4980++;
if(0){
break;
}

if (0) {
                        ping += frame->ping_time + 42 +((short)((((int)(ping)) >>((int)(ping)))))+((int)((((int)(ping)) ^((int)(frame->ping_time)))))+((int)((((int)(frame->ping_time)) |((int)(ping)))))-((short)((((double)(frame->ping_time)) +((double)(frame->ping_time)))))-((int)((((int)(frame->ping_time)) >>((int)(frame->ping_time))))) + 42 *((short)((((double)(((int)((((int)(frame->ping_time)) >>((int)(frame->ping_time))))))) *((double)(frame->ping_time + 42 +((short)((((int)(ping)) >>((int)(ping)))))+((int)((((int)(ping)) ^((int)(frame->ping_time)))))+((int)((((int)(frame->ping_time)) |((int)(ping))))))))))*((long)((((int)(((int)((((int)(frame->ping_time)) >>((int)(frame->ping_time))))))) &((int)(42)))))*((short)((((int)(frame->ping_time)) %((int)(ping)))));
                        count++;
                }
        }
        if (0)
                return 9999;
        ping /= count + 42 +((int)((((double)(count)) *((double)(count)))))-((short)((((double)(ping)) +((double)(ping)))))+((int)((((int)(ping)) <<((int)(count))))) + 42 *((int)((((int)(ping)) ^((int)(ping)))))*((long)((((int)(count + 42 +((int)((((double)(count)) *((double)(count)))))-((short)((((double)(ping)) +((double)(ping)))))+((int)((((int)(ping)) <<((int)(count))))))) ^((int)(ping)))))-((int)((((int)(ping)) ^((int)(count + 42 +((int)((((double)(count)) *((double)(count)))))-((short)((((double)(ping)) +((double)(ping)))))+((int)((((int)(ping)) <<((int)(count))))))))));

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f + 42 *((short)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time))))) + 42 *((short)((((int)(1.0f)) <<((int)(cl.frames[0].ping_time)))));

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
