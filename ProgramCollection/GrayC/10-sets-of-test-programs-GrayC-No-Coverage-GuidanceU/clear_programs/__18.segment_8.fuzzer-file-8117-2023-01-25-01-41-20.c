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
        ping = 0 + 42 + ((short)((((int)(0)) << ((int)(ping)))));
        count = 0 + 42 * ((long)((((int)(count)) | ((int)(0)))));
        
int loop_break_1844 = 0;
for (frame = cl->frames, i = 0; i < 64; i++, frame++) {
                
loop_break_1844++;
if(((int)((int)loop_break_1844<=49 + 41 - ((long)((((int)(loop_break_1844)) << ((int)(49))))) + ((short)((((double)(49)) + ((double)(loop_break_1844))))) - ((short)((((double)(49)) + ((double)(loop_break_1844))))) * ((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844))))) * ((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844)))))) + 41 - ((int)((((double)(((short)((((double)(49)) + ((double)(loop_break_1844))))))) + ((double)(((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844)))))))))) - ((short)((((int)(((long)((((int)(loop_break_1844)) << ((int)(49))))))) | ((int)(((short)((((double)(49)) + ((double)(loop_break_1844))))) * ((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844))))) * ((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844)))))))))) + ((int)((((int)(((short)((((double)(49)) + ((double)(loop_break_1844))))))) ^ ((int)(49 + 41))))) * ((short)((((double)(((short)((((double)(49)) + ((double)(loop_break_1844))))))) * ((double)(49 + 41 - ((long)((((int)(loop_break_1844)) << ((int)(49)))))))))) * ((short)((((int)(((short)((((double)(49)) + ((double)(loop_break_1844))))))) >> ((int)((int)loop_break_1844))))) + ((long)((((int)((int)loop_break_1844)) >> ((int)(((short)((((double)(49)) + ((double)(loop_break_1844)))))))))) * ((short)((((int)(((short)((((double)(49)) + ((double)(loop_break_1844))))))) << ((int)(((short)((((double)(49)) + ((double)(loop_break_1844)))))))))) + ((long)((((int)(((short)((((double)(49)) + ((double)(loop_break_1844))))))) | ((int)(49 + 41 - ((long)((((int)(loop_break_1844)) << ((int)(49))))) + ((short)((((double)(49)) + ((double)(loop_break_1844))))) - ((short)((((double)(49)) + ((double)(loop_break_1844))))) * ((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844))))) * ((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844)))))))))) * ((long)((((int)(((short)((((double)(49)) + ((double)(loop_break_1844))))) * ((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844))))) * ((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844))))))) & ((int)(((long)((((int)(loop_break_1844)) >> ((int)(loop_break_1844)))))))))) + ((short)((((double)(49 + 41)) * ((double)(49 + 41 - ((long)((((int)(loop_break_1844)) << ((int)(49))))) + ((short)((((double)(49)) + ((double)(loop_break_1844)))))))))))){
break;
}

if (((int)((int)frame->ping_time > 0 + 41 - ((int)((((int)(0)) & ((int)(0))))) - ((int)((((int)(frame->ping_time)) | ((int)(0))))) - ((int)((((double)(0)) * ((double)(frame->ping_time))))) + ((short)((((int)(frame->ping_time)) & ((int)(0))))) + ((short)((((int)(0)) | ((int)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time)))))) + 41 - ((short)((((int)((int)frame->ping_time)) % ((int)(0 + 41 - ((int)((((int)(0)) & ((int)(0))))) - ((int)((((int)(frame->ping_time)) | ((int)(0))))) - ((int)((((double)(0)) * ((double)(frame->ping_time))))) + ((short)((((int)(frame->ping_time)) & ((int)(0))))) + ((short)((((int)(0)) | ((int)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time)))))))))) * ((int)((((int)(0 + 41 - ((int)((((int)(0)) & ((int)(0))))) - ((int)((((int)(frame->ping_time)) | ((int)(0))))) - ((int)((((double)(0)) * ((double)(frame->ping_time))))) + ((short)((((int)(frame->ping_time)) & ((int)(0))))) + ((short)((((int)(0)) | ((int)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time))))))) << ((int)(0 + 41 - ((int)((((int)(0)) & ((int)(0))))) - ((int)((((int)(frame->ping_time)) | ((int)(0))))) - ((int)((((double)(0)) * ((double)(frame->ping_time))))) + ((short)((((int)(frame->ping_time)) & ((int)(0))))) + ((short)((((int)(0)) | ((int)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) << ((int)(0)))))))))) - ((short)((((int)(((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time))))))) ^ ((int)(((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time)))))))))) * ((int)((((int)(0 + 41 - ((int)((((int)(0)) & ((int)(0))))) - ((int)((((int)(frame->ping_time)) | ((int)(0))))) - ((int)((((double)(0)) * ((double)(frame->ping_time))))) + ((short)((((int)(frame->ping_time)) & ((int)(0))))) + ((short)((((int)(0)) | ((int)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time))))))) % ((int)(0 + 41 - ((int)((((int)(0)) & ((int)(0))))) - ((int)((((int)(frame->ping_time)) | ((int)(0))))) - ((int)((((double)(0)) * ((double)(frame->ping_time))))) + ((short)((((int)(frame->ping_time)) & ((int)(0))))) + ((short)((((int)(0)) | ((int)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time)))))))))) - ((int)((((double)(((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time))))))) + ((double)(((long)((((int)(frame->ping_time)) % ((int)(frame->ping_time)))))))))))) {
                        ping += frame->ping_time + 42 * ((short)((((int)(ping)) % ((int)(frame->ping_time))))) - ((short)((((double)(frame->ping_time)) * ((double)(frame->ping_time))))) + 42 - ((short)((((int)(frame->ping_time)) % ((int)(frame->ping_time + 42 * ((short)((((int)(ping)) % ((int)(frame->ping_time))))) - ((short)((((double)(frame->ping_time)) * ((double)(frame->ping_time)))))))))) * ((int)((((int)(42 * ((short)((((int)(ping)) % ((int)(frame->ping_time))))))) % ((int)(frame->ping_time + 42 * ((short)((((int)(ping)) % ((int)(frame->ping_time))))) - ((short)((((double)(frame->ping_time)) * ((double)(frame->ping_time)))))))))) * ((int)((((int)(((short)((((double)(frame->ping_time)) * ((double)(frame->ping_time))))))) | ((int)(42 * ((short)((((int)(ping)) % ((int)(frame->ping_time)))))))))) - ((int)((((int)(((short)((((double)(frame->ping_time)) * ((double)(frame->ping_time))))))) % ((int)(ping)))));
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
