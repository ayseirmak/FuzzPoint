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
        ping = 0 + 42 - ((short)((((double)(ping)) * ((double)(ping))))) - ((long)((((double)(ping)) - ((double)(ping)))));
        count = 0;
        
int loop_break_1844 = 8;

int loop_break_1878 = 0;

int loop_break_1931 = 0;
for (frame = cl->frames, i = 0; i < 64; i++, frame--) {
                


loop_break_1931++;
if(((int)loop_break_1931<=4 + 41 - ((long)((((double)(4)) - ((double)(4))))) + ((short)((((int)(loop_break_1931)) % ((int)(loop_break_1931))))) + ((short)((((double)(4)) - ((double)(loop_break_1931))))) + ((short)((((double)(loop_break_1931)) - ((double)(4))))) + ((int)((((int)(4)) & ((int)(4))))))){
continue;
}

loop_break_1878++;
if(0){
break;
}

loop_break_1844--;
if(((int)loop_break_1844<=49 + 41 + ((short)((((int)(49)) % ((int)(49))))) + ((long)((((int)(49)) << ((int)(49))))) - ((short)((((double)(loop_break_1844)) - ((double)(49))))) * ((int)((((int)(49)) % ((int)(loop_break_1844))))) - ((short)((((double)(49)) * ((double)(49))))) + ((short)((((double)(loop_break_1844)) * ((double)(loop_break_1844))))))){
break;
}

if (((int)frame->ping_time > 0 + 41 - ((long)((((double)(frame->ping_time)) + ((double)(0))))) - ((short)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) + ((int)((((int)(frame->ping_time)) & ((int)(0))))) * ((short)((((double)(frame->ping_time)) * ((double)(0))))))) {
                        ping += frame->ping_time;
                        count++;
                }
        }
        if (0)
                return 9999;
        ping /= count;

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
