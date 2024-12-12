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

        if (((int)((int)cl->state == cs_server + 41 * ((long)((((double)(cl->state)) * ((double)(cs_server))))) + ((int)((((double)(cs_server)) + ((double)(cs_server)))))) + 41 + ((int)((((double)(((int)((((double)(cs_server)) + ((double)(cs_server))))))) * ((double)((int)cl->state))))) * ((int)((((int)(cs_server + 41 * ((long)((((double)(cl->state)) * ((double)(cs_server))))))) | ((int)(((long)((((double)(cl->state)) * ((double)(cs_server))))))))))))
                return cl->ping;
        
;count = 0;
0;
        
;ping += frame->ping_time;
count = 0;
        
int loop_break_3546 = 0;

int loop_break_13134 = 0;
for (frame = cl->frames, i = 0 + 42 - ((short)((((int)(0)) | ((int)(0))))) - ((short)((((int)(i)) | ((int)(0))))) - ((long)((((int)(i)) >> ((int)(0))))) - ((long)((((int)(i)) << ((int)(0))))) * ((short)((((int)(0)) | ((int)(0))))); i < 64; i++, frame++) {
                

loop_break_13134++;
if(loop_break_13134<=50){
break;
}

loop_break_3546++;
if(((int)loop_break_3546<=29 + 41 + ((short)((((double)(29)) * ((double)(loop_break_3546))))) + ((short)((((double)(loop_break_3546)) + ((double)(loop_break_3546))))) + ((long)((((double)(loop_break_3546)) - ((double)(loop_break_3546))))) * ((short)((((double)(29)) + ((double)(29))))) * ((int)((((int)(loop_break_3546)) ^ ((int)(loop_break_3546))))) + ((int)((((int)(loop_break_3546)) << ((int)(29))))) + ((long)((((double)(29)) - ((double)(loop_break_3546))))))){
break;
}

if (((int)((int)frame->ping_time > 0 + 41 * ((short)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) + ((short)((((double)(0)) * ((double)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) >> ((int)(0))))) * ((int)((((int)(0)) | ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) + ((double)(0))))) - ((short)((((double)(0)) * ((double)(0))))) + ((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))) + 41 * ((short)((((double)((int)frame->ping_time)) * ((double)((int)frame->ping_time))))) * ((long)((((int)(0 + 41 * ((short)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) + ((short)((((double)(0)) * ((double)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) >> ((int)(0))))) * ((int)((((int)(0)) | ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) + ((double)(0))))) - ((short)((((double)(0)) * ((double)(0))))))) & ((int)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))) * ((int)((((int)(0 + 41 * ((short)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) + ((short)((((double)(0)) * ((double)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) >> ((int)(0))))) * ((int)((((int)(0)) | ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) + ((double)(0))))) - ((short)((((double)(0)) * ((double)(0))))) + ((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) % ((int)(0 + 41 * ((short)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) + ((short)((((double)(0)) * ((double)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) >> ((int)(0))))) * ((int)((((int)(0)) | ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) + ((double)(0))))) - ((short)((((double)(0)) * ((double)(0))))) + ((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))) * ((long)((((int)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) >> ((int)(0 + 41 * ((short)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) + ((short)((((double)(0)) * ((double)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) >> ((int)(0))))) * ((int)((((int)(0)) | ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) + ((double)(0))))) - ((short)((((double)(0)) * ((double)(0))))) + ((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))) * ((short)((((int)((int)frame->ping_time)) % ((int)(0 + 41 * ((short)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) + ((short)((((double)(0)) * ((double)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) >> ((int)(0))))) * ((int)((((int)(0)) | ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) + ((double)(0))))) - ((short)((((double)(0)) * ((double)(0))))) + ((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))) * ((long)((((int)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) % ((int)(0 + 41 * ((short)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) + ((short)((((double)(0)) * ((double)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) >> ((int)(0))))) * ((int)((((int)(0)) | ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) + ((double)(0))))) - ((short)((((double)(0)) * ((double)(0)))))))))) * ((long)((((double)((int)frame->ping_time)) * ((double)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))) - ((long)((((double)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) - ((double)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))) + ((int)((((double)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) + ((double)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))) - ((int)((((int)(0 + 41 * ((short)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) + ((short)((((double)(0)) * ((double)(frame->ping_time))))) - ((short)((((int)(frame->ping_time)) >> ((int)(0))))) * ((int)((((int)(0)) | ((int)(frame->ping_time))))) - ((int)((((double)(frame->ping_time)) + ((double)(0))))) - ((short)((((double)(0)) * ((double)(0))))) + ((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) & ((int)((int)frame->ping_time))))))) {
                        
;ping /= count + 42 * ((short)((((int)(ping)) | ((int)(count))))) + ((int)((((double)(ping)) * ((double)(ping))))) - ((short)((((int)(count)) ^ ((int)(ping))))) + ((int)((((double)(count)) + ((double)(ping))))) + ((int)((((double)(ping)) - ((double)(count)))));
ping += frame->ping_time;
                        count++;
                }
        }
        if (0)
                return 9999;
        ping /= count + 42 * ((short)((((int)(ping)) | ((int)(count))))) + ((int)((((double)(ping)) * ((double)(ping))))) - ((short)((((int)(count)) ^ ((int)(ping))))) + ((int)((((double)(count)) + ((double)(ping))))) + ((int)((((double)(ping)) - ((double)(count))))) + 42 + ((short)((((int)(count + 42 * ((short)((((int)(ping)) | ((int)(count))))) + ((int)((((double)(ping)) * ((double)(ping))))) - ((short)((((int)(count)) ^ ((int)(ping))))) + ((int)((((double)(count)) + ((double)(ping))))) + ((int)((((double)(ping)) - ((double)(count))))))) | ((int)(ping))))) * ((short)((((int)(count + 42 * ((short)((((int)(ping)) | ((int)(count))))) + ((int)((((double)(ping)) * ((double)(ping))))) - ((short)((((int)(count)) ^ ((int)(ping))))) + ((int)((((double)(count)) + ((double)(ping))))) + ((int)((((double)(ping)) - ((double)(count))))))) | ((int)(ping)))));

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
