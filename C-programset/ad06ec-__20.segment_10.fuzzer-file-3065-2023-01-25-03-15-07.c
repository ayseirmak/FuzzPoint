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
        0;
        
;ping += frame->ping_time + 42 + ((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time))))) - ((short)((((int)(ping)) & ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) * ((double)(ping))))) + ((short)((((double)(ping)) * ((double)(ping))))) * ((short)((((int)(frame->ping_time)) % ((int)(ping)))));
0;
        
int loop_break_1844 = 8;

int loop_break_1864 = 8;

int loop_break_1931 = 8;
for (frame = cl->frames, i = 0 + 42 - ((short)((((int)(0)) | ((int)(0))))); i < 64; i++, frame--) {
                


loop_break_1931++;
if(((int)loop_break_1931<=32 + 41 + ((int)((((int)(loop_break_1931)) ^ ((int)(loop_break_1931))))) - ((int)((((int)(loop_break_1931)) ^ ((int)(32))))) + ((int)((((double)(32)) * ((double)(32))))) + ((long)((((double)(loop_break_1931)) - ((double)(32))))) * ((short)((((double)(32)) - ((double)(32))))) * ((int)((((double)(32)) + ((double)(loop_break_1931))))))){
break;
}

loop_break_1864++;
if(((int)loop_break_1864<=23 + 41 * ((long)((((int)(loop_break_1864)) | ((int)(23))))) * ((int)((((double)(23)) + ((double)(loop_break_1864))))) - ((short)((((int)(loop_break_1864)) ^ ((int)(loop_break_1864))))) + ((long)((((int)(23)) | ((int)(loop_break_1864))))) - ((long)((((int)(loop_break_1864)) >> ((int)(23))))) * ((long)((((int)(loop_break_1864)) & ((int)(loop_break_1864))))) - ((int)((((double)(23)) * ((double)(loop_break_1864))))))){
continue;
}

loop_break_1844--;
if(0){
continue;
}

if (((int)frame->ping_time > 0 + 41 + ((short)((((double)(frame->ping_time)) + ((double)(0))))) + ((int)((((int)(frame->ping_time)) << ((int)(0))))) * ((int)((((int)(0)) % ((int)(frame->ping_time))))) - ((long)((((int)(0)) >> ((int)(frame->ping_time))))) - ((short)((((double)(frame->ping_time)) + ((double)(0))))))) {
                        ping += frame->ping_time + 42 + ((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time))))) - ((short)((((int)(ping)) & ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) * ((double)(ping))))) + ((short)((((double)(ping)) * ((double)(ping))))) * ((short)((((int)(frame->ping_time)) % ((int)(ping)))));
                        count++;
                }
        }
        if (0)
                return 9999;
        count + 42 + ((long)((((double)(ping)) * ((double)(ping)))));

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
