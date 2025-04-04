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
        

ping = 0 + 42 +((long)((((double)(ping)) +((double)(ping)))));
ping = 0 + 42 +((long)((((double)(ping)) +((double)(ping)))));
;
;
;
        

count = 0 + 42 -((short)((((int)(count)) %((int)(count)))));
count = 0 + 42 -((short)((((int)(count)) %((int)(count)))));
;
;
;
        
int loop_break_1844 = 0;

int loop_break_4559 = 0;

int loop_break_3094 = 0;
for (frame = cl->frames, i = 0 + 42 +((int)((((int)(0)) ^((int)(0))))); i < 64; i++, frame++) {
                


loop_break_3094++;
if(loop_break_3094<=5){
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
                        

ping += frame->ping_time + 42 -((short)((((int)(frame->ping_time)) >>((int)(ping)))))+((short)((((int)(ping)) ^((int)(frame->ping_time)))));
ping += frame->ping_time + 42 -((short)((((int)(frame->ping_time)) >>((int)(ping)))))+((short)((((int)(ping)) ^((int)(frame->ping_time)))));
;
;
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

   

cl.frames[0].ping_time = 1.0f + 42 *((short)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time)))))*((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))))+((long)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((int)((((double)(1.0f)) -((double)(1.0f)))));
cl.frames[0].ping_time = 1.0f + 42 *((short)((((int)(cl.frames[0].ping_time)) ^((int)(cl.frames[0].ping_time)))))*((long)((((int)(cl.frames[0].ping_time)) <<((int)(1.0f)))))+((long)((((int)(cl.frames[0].ping_time)) ^((int)(1.0f)))))*((int)((((double)(1.0f)) -((double)(1.0f)))));
;
;
;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
