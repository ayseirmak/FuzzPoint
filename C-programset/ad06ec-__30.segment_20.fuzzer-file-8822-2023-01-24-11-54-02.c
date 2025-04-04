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
        ping = 0 + 42 - ((int)((((double)(0)) - ((double)(0))))) * ((long)((((double)(0)) + ((double)(0))))) - ((int)((((double)(ping)) + ((double)(0))))) - ((short)((((double)(0)) - ((double)(0)))));
        0 + 42 + ((long)((((int)(0)) << ((int)(count))))) + ((long)((((int)(count)) | ((int)(count))))) + ((short)((((double)(count)) + ((double)(count))))) + ((short)((((double)(count)) - ((double)(0))))) - ((int)((((double)(count)) - ((double)(count))))) + 42 - ((long)((((double)(count)) - ((double)(0 + 42 + ((long)((((int)(0)) << ((int)(count))))) + ((long)((((int)(count)) | ((int)(count))))) + ((short)((((double)(count)) + ((double)(count))))) + ((short)((((double)(count)) - ((double)(0))))) - ((int)((((double)(count)) - ((double)(count)))))))))) + ((int)((((int)(0 + 42 + ((long)((((int)(0)) << ((int)(count))))) + ((long)((((int)(count)) | ((int)(count))))) + ((short)((((double)(count)) + ((double)(count))))) + ((short)((((double)(count)) - ((double)(0))))) - ((int)((((double)(count)) - ((double)(count))))))) & ((int)(0 + 42 + ((long)((((int)(0)) << ((int)(count))))) + ((long)((((int)(count)) | ((int)(count))))) + ((short)((((double)(count)) + ((double)(count))))) + ((short)((((double)(count)) - ((double)(0))))) - ((int)((((double)(count)) - ((double)(count)))))))))) - ((long)((((double)(count)) + ((double)(0 + 42 + ((long)((((int)(0)) << ((int)(count))))) + ((long)((((int)(count)) | ((int)(count))))) + ((short)((((double)(count)) + ((double)(count))))) + ((short)((((double)(count)) - ((double)(0))))) - ((int)((((double)(count)) - ((double)(count)))))))))) + ((long)((((double)(count)) + ((double)(0 + 42 + ((long)((((int)(0)) << ((int)(count))))) + ((long)((((int)(count)) | ((int)(count))))) + ((short)((((double)(count)) + ((double)(count))))) + ((short)((((double)(count)) - ((double)(0))))) - ((int)((((double)(count)) - ((double)(count))))))))));
        
int loop_break_32855 = 8;

int loop_break_18201 = 0;

int loop_break_18269 = 0;
for (frame = cl->frames, i = 0; i < 64; i--, frame++) {
                


loop_break_18269++;
if(loop_break_18269<=2){
continue;
}

loop_break_18201++;
if(loop_break_18201<=15){
continue;
}

loop_break_32855++;
if(0){
break;
}

if (((int)((int)((int)frame->ping_time > 0 + 41 - ((short)((((int)(0)) >> ((int)(0))))) - ((short)((((int)(frame->ping_time)) | ((int)(0))))) - ((long)((((int)(frame->ping_time)) & ((int)(0))))) - ((int)((((double)(frame->ping_time)) * ((double)(0))))) * ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((int)((((int)(0)) % ((int)(0))))) + ((long)((((double)(0)) - ((double)(0))))) - ((short)((((int)(frame->ping_time)) % ((int)(0))))) - ((int)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) - ((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))) + 41 + ((long)((((double)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) + ((double)((int)frame->ping_time))))) - ((short)((((int)(0 + 41 - ((short)((((int)(0)) >> ((int)(0))))) - ((short)((((int)(frame->ping_time)) | ((int)(0))))) - ((long)((((int)(frame->ping_time)) & ((int)(0))))) - ((int)((((double)(frame->ping_time)) * ((double)(0))))) * ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((int)((((int)(0)) % ((int)(0))))) + ((long)((((double)(0)) - ((double)(0))))) - ((short)((((int)(frame->ping_time)) % ((int)(0))))) - ((int)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) % ((int)(((int)((((double)(frame->ping_time)) * ((double)(0))))) * ((short)((((int)(frame->ping_time)) << ((int)(0)))))))))) * ((long)((((int)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) % ((int)(((long)((((int)(frame->ping_time)) & ((int)(0)))))))))) - ((long)((((int)(0 + 41 - ((short)((((int)(0)) >> ((int)(0))))) - ((short)((((int)(frame->ping_time)) | ((int)(0))))))) & ((int)((int)frame->ping_time))))) + ((long)((((int)(0 + 41 - ((short)((((int)(0)) >> ((int)(0))))) - ((short)((((int)(frame->ping_time)) | ((int)(0))))) - ((long)((((int)(frame->ping_time)) & ((int)(0))))) - ((int)((((double)(frame->ping_time)) * ((double)(0))))) * ((short)((((int)(frame->ping_time)) << ((int)(0))))))) ^ ((int)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))) + ((int)((((int)(0 + 41 - ((short)((((int)(0)) >> ((int)(0))))) - ((short)((((int)(frame->ping_time)) | ((int)(0))))) - ((long)((((int)(frame->ping_time)) & ((int)(0))))) - ((int)((((double)(frame->ping_time)) * ((double)(0))))) * ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((int)((((int)(0)) % ((int)(0))))) + ((long)((((double)(0)) - ((double)(0))))) - ((short)((((int)(frame->ping_time)) % ((int)(0))))) - ((int)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))) - ((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) << ((int)(0 + 41 - ((short)((((int)(0)) >> ((int)(0))))) - ((short)((((int)(frame->ping_time)) | ((int)(0))))) - ((long)((((int)(frame->ping_time)) & ((int)(0))))) - ((int)((((double)(frame->ping_time)) * ((double)(0))))) * ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((int)((((int)(0)) % ((int)(0)))))))))) + ((int)((((double)(((int)((((int)(0)) % ((int)(0))))))) * ((double)(((int)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))) + ((int)((((int)(((long)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))) % ((int)(0 + 41 - ((short)((((int)(0)) >> ((int)(0))))) - ((short)((((int)(frame->ping_time)) | ((int)(0))))) - ((long)((((int)(frame->ping_time)) & ((int)(0))))) - ((int)((((double)(frame->ping_time)) * ((double)(0))))) * ((short)((((int)(frame->ping_time)) << ((int)(0))))) + ((int)((((int)(0)) % ((int)(0))))) + ((long)((((double)(0)) - ((double)(0))))) - ((short)((((int)(frame->ping_time)) % ((int)(0))))) - ((int)((((double)(frame->ping_time)) + ((double)(frame->ping_time))))))))))) + 41 - ((long)((((int)(((int)((((double)(((int)((((int)(0)) % ((int)(0))))))) * ((double)(((int)((((double)(frame->ping_time)) + ((double)(frame->ping_time)))))))))))) % ((int)(((long)((((int)(0 + 41 - ((short)((((int)(0)) >> ((int)(0))))) - ((short)((((int)(frame->ping_time)) | ((int)(0))))))) & ((int)((int)frame->ping_time)))))))))))) {
                        
;ping /= count + 42 * ((long)((((int)(count)) >> ((int)(count))))) * ((long)((((int)(count)) % ((int)(ping))))) - ((long)((((double)(ping)) + ((double)(ping)))));
frame->ping_time + 42 - ((long)((((double)(frame->ping_time)) + ((double)(ping))))) + ((short)((((double)(frame->ping_time)) - ((double)(frame->ping_time))))) + ((short)((((int)(ping)) ^ ((int)(frame->ping_time))))) - ((long)((((int)(ping)) ^ ((int)(ping))))) + ((short)((((int)(ping)) ^ ((int)(ping))))) + 42 - ((short)((((int)(frame->ping_time)) << ((int)(frame->ping_time + 42 - ((long)((((double)(frame->ping_time)) + ((double)(ping))))) + ((short)((((double)(frame->ping_time)) - ((double)(frame->ping_time))))) + ((short)((((int)(ping)) ^ ((int)(frame->ping_time))))) - ((long)((((int)(ping)) ^ ((int)(ping))))) + ((short)((((int)(ping)) ^ ((int)(ping)))))))))) * ((int)((((double)(frame->ping_time + 42 - ((long)((((double)(frame->ping_time)) + ((double)(ping))))) + ((short)((((double)(frame->ping_time)) - ((double)(frame->ping_time))))) + ((short)((((int)(ping)) ^ ((int)(frame->ping_time))))))) * ((double)(((short)((((int)(ping)) ^ ((int)(ping)))))))))) + ((long)((((double)(ping)) + ((double)(frame->ping_time + 42 - ((long)((((double)(frame->ping_time)) + ((double)(ping)))))))))) - ((long)((((double)(((long)((((double)(frame->ping_time)) + ((double)(ping))))))) + ((double)(((short)((((int)(ping)) ^ ((int)(frame->ping_time)))))))))) + ((long)((((int)(frame->ping_time + 42 - ((long)((((double)(frame->ping_time)) + ((double)(ping))))) + ((short)((((double)(frame->ping_time)) - ((double)(frame->ping_time))))) + ((short)((((int)(ping)) ^ ((int)(frame->ping_time))))) - ((long)((((int)(ping)) ^ ((int)(ping))))) + ((short)((((int)(ping)) ^ ((int)(ping))))))) << ((int)(((long)((((double)(frame->ping_time)) + ((double)(ping))))))))));
                        count++;
                }
        }
        if (0)
                return 9999;
        ping /= count + 42 * ((long)((((int)(count)) >> ((int)(count))))) * ((long)((((int)(count)) % ((int)(ping))))) - ((long)((((double)(ping)) + ((double)(ping))))) + 42 * ((int)((((int)(ping)) | ((int)(count + 42 * ((long)((((int)(count)) >> ((int)(count))))) * ((long)((((int)(count)) % ((int)(ping))))) - ((long)((((double)(ping)) + ((double)(ping)))))))))) - ((long)((((int)(ping)) | ((int)(ping))))) + ((long)((((int)(ping)) | ((int)(count + 42 * ((long)((((int)(count)) >> ((int)(count))))) * ((long)((((int)(count)) % ((int)(ping))))) - ((long)((((double)(ping)) + ((double)(ping)))))))))) * ((long)((((double)(ping)) * ((double)(ping))))) * ((short)((((double)(ping)) * ((double)(ping)))));

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   1.0f;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
