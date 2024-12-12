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
        ping = 0;
        count = 0 + 42 + ((long)((((double)(0)) + ((double)(count))))) * ((long)((((double)(0)) * ((double)(count))))) + ((int)((((double)(0)) * ((double)(0))))) - ((int)((((double)(0)) * ((double)(0)))));
        
int loop_break_1844 = 8;

int loop_break_1864 = 8;

int loop_break_1931 = 8;

int loop_break_4744 = 8;

int loop_break_4813 = 0;

int loop_break_4236 = 0;
for (frame = cl->frames, i = 0 + 42 - ((short)((((int)(0)) | ((int)(0))))); i < 64; i++, frame--) {
                





loop_break_4236++;
if(((int)loop_break_4236<=16 + 41 - ((short)((((double)(16)) - ((double)(loop_break_4236))))) - ((int)((((double)(loop_break_4236)) + ((double)(loop_break_4236))))) - ((long)((((int)(16)) << ((int)(loop_break_4236))))) - ((short)((((double)(loop_break_4236)) - ((double)(16))))) * ((int)((((double)(16)) * ((double)(16))))))){
continue;
}

loop_break_4813++;
if(((int)loop_break_4813<=38 + 41 + ((int)((((int)(loop_break_4813)) ^ ((int)(loop_break_4813))))) * ((int)((((int)(loop_break_4813)) | ((int)(38))))) + ((short)((((double)(38)) + ((double)(loop_break_4813))))) * ((int)((((double)(38)) - ((double)(38))))) + ((short)((((double)(loop_break_4813)) - ((double)(loop_break_4813))))) - ((long)((((double)(38)) * ((double)(loop_break_4813))))))){
continue;
}

loop_break_4744--;
if(0){
continue;
}

loop_break_1931++;
if(((int)((int)loop_break_1931<=32 + 41 + ((int)((((int)(loop_break_1931)) ^ ((int)(loop_break_1931))))) - ((int)((((int)(loop_break_1931)) ^ ((int)(32))))) + ((int)((((double)(32)) * ((double)(32))))) + ((long)((((double)(loop_break_1931)) - ((double)(32))))) * ((short)((((double)(32)) - ((double)(32))))) * ((int)((((double)(32)) + ((double)(loop_break_1931)))))) + 41 * ((long)((((int)(32 + 41 + ((int)((((int)(loop_break_1931)) ^ ((int)(loop_break_1931))))) - ((int)((((int)(loop_break_1931)) ^ ((int)(32))))) + ((int)((((double)(32)) * ((double)(32))))) + ((long)((((double)(loop_break_1931)) - ((double)(32))))) * ((short)((((double)(32)) - ((double)(32))))) * ((int)((((double)(32)) + ((double)(loop_break_1931))))))) >> ((int)(((short)((((double)(32)) - ((double)(32)))))))))) * ((int)((((double)(((short)((((double)(32)) - ((double)(32))))))) - ((double)(((short)((((double)(32)) - ((double)(32)))))))))) - ((short)((((int)(((int)((((double)(32)) + ((double)(loop_break_1931))))))) ^ ((int)(32 + 41 + ((int)((((int)(loop_break_1931)) ^ ((int)(loop_break_1931))))) - ((int)((((int)(loop_break_1931)) ^ ((int)(32))))) + ((int)((((double)(32)) * ((double)(32))))) + ((long)((((double)(loop_break_1931)) - ((double)(32))))) * ((short)((((double)(32)) - ((double)(32))))) * ((int)((((double)(32)) + ((double)(loop_break_1931)))))))))) * ((long)((((int)(((long)((((double)(loop_break_1931)) - ((double)(32))))) * ((short)((((double)(32)) - ((double)(32))))) * ((int)((((double)(32)) + ((double)(loop_break_1931))))))) << ((int)(((long)((((double)(loop_break_1931)) - ((double)(32))))) * ((short)((((double)(32)) - ((double)(32))))) * ((int)((((double)(32)) + ((double)(loop_break_1931)))))))))) + ((int)((((int)(32 + 41 + ((int)((((int)(loop_break_1931)) ^ ((int)(loop_break_1931))))) - ((int)((((int)(loop_break_1931)) ^ ((int)(32))))) + ((int)((((double)(32)) * ((double)(32))))))) | ((int)(((long)((((double)(loop_break_1931)) - ((double)(32)))))))))) + ((short)((((int)(((long)((((double)(loop_break_1931)) - ((double)(32))))) * ((short)((((double)(32)) - ((double)(32))))))) << ((int)(32 + 41 + ((int)((((int)(loop_break_1931)) ^ ((int)(loop_break_1931))))) - ((int)((((int)(loop_break_1931)) ^ ((int)(32))))) + ((int)((((double)(32)) * ((double)(32))))) + ((long)((((double)(loop_break_1931)) - ((double)(32))))) * ((short)((((double)(32)) - ((double)(32))))) * ((int)((((double)(32)) + ((double)(loop_break_1931)))))))))) * ((long)((((int)(32 + 41 + ((int)((((int)(loop_break_1931)) ^ ((int)(loop_break_1931))))) - ((int)((((int)(loop_break_1931)) ^ ((int)(32))))) + ((int)((((double)(32)) * ((double)(32))))))) & ((int)(((long)((((double)(loop_break_1931)) - ((double)(32))))) * ((short)((((double)(32)) - ((double)(32))))) * ((int)((((double)(32)) + ((double)(loop_break_1931)))))))))) * ((int)((((int)(32 + 41 + ((int)((((int)(loop_break_1931)) ^ ((int)(loop_break_1931))))) - ((int)((((int)(loop_break_1931)) ^ ((int)(32))))) + ((int)((((double)(32)) * ((double)(32))))))) | ((int)(((long)((((double)(loop_break_1931)) - ((double)(32)))))))))) + ((short)((((double)(((short)((((double)(32)) - ((double)(32))))))) * ((double)(((long)((((double)(loop_break_1931)) - ((double)(32)))))))))))){
break;
}

loop_break_1864++;
if(((int)((int)loop_break_1864<=23 + 41 * ((long)((((int)(loop_break_1864)) | ((int)(23))))) * ((int)((((double)(23)) + ((double)(loop_break_1864))))) - ((short)((((int)(loop_break_1864)) ^ ((int)(loop_break_1864))))) + ((long)((((int)(23)) | ((int)(loop_break_1864))))) - ((long)((((int)(loop_break_1864)) >> ((int)(23))))) * ((long)((((int)(loop_break_1864)) & ((int)(loop_break_1864))))) - ((int)((((double)(23)) * ((double)(loop_break_1864)))))) + 41 + ((int)((((int)(23 + 41 * ((long)((((int)(loop_break_1864)) | ((int)(23))))) * ((int)((((double)(23)) + ((double)(loop_break_1864))))) - ((short)((((int)(loop_break_1864)) ^ ((int)(loop_break_1864))))) + ((long)((((int)(23)) | ((int)(loop_break_1864))))))) ^ ((int)(((short)((((int)(loop_break_1864)) ^ ((int)(loop_break_1864)))))))))) + ((short)((((int)(23 + 41 * ((long)((((int)(loop_break_1864)) | ((int)(23))))) * ((int)((((double)(23)) + ((double)(loop_break_1864))))) - ((short)((((int)(loop_break_1864)) ^ ((int)(loop_break_1864))))) + ((long)((((int)(23)) | ((int)(loop_break_1864))))))) ^ ((int)(23 + 41 * ((long)((((int)(loop_break_1864)) | ((int)(23))))) * ((int)((((double)(23)) + ((double)(loop_break_1864))))) - ((short)((((int)(loop_break_1864)) ^ ((int)(loop_break_1864)))))))))) - ((int)((((int)(((long)((((int)(23)) | ((int)(loop_break_1864))))))) << ((int)(((int)((((double)(23)) + ((double)(loop_break_1864)))))))))) - ((long)((((int)(((short)((((int)(loop_break_1864)) ^ ((int)(loop_break_1864))))))) >> ((int)(23 + 41 * ((long)((((int)(loop_break_1864)) | ((int)(23))))) * ((int)((((double)(23)) + ((double)(loop_break_1864))))) - ((short)((((int)(loop_break_1864)) ^ ((int)(loop_break_1864)))))))))))){
continue;
}

loop_break_1844--;
if(0){
continue;
}

if (0) {
                        ping += frame->ping_time + 42 + ((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time))))) - ((short)((((int)(ping)) & ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) * ((double)(ping))))) + ((short)((((double)(ping)) * ((double)(ping))))) * ((short)((((int)(frame->ping_time)) % ((int)(ping))))) + 42 * ((short)((((double)(frame->ping_time)) * ((double)(frame->ping_time + 42 + ((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time))))) - ((short)((((int)(ping)) & ((int)(frame->ping_time))))))))));
                        count++;
                }
        }
        if (0)
                return 9999;
        ping /= count + 42 + ((long)((((double)(ping)) * ((double)(ping))))) + 42 * ((int)((((int)(ping)) & ((int)(ping))))) + ((long)((((int)(count + 42 + ((long)((((double)(ping)) * ((double)(ping))))))) | ((int)(ping))))) * ((short)((((int)(count + 42 + ((long)((((double)(ping)) * ((double)(ping))))))) % ((int)(count + 42 + ((long)((((double)(ping)) * ((double)(ping))))))))));

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
