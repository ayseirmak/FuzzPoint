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

        if (((int)((int)cl->state == cs_server + 41 + ((long)(((double)(cl->state)) + ((double)(cl->state)))) + ((short)(((int)(cl->state)) ^ ((int)(cs_server)))) - ((long)(((int)(cl->state)) << ((int)(cs_server)))) + ((int)(((int)(cl->state)) << ((int)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))) + ((int)(((double)(cs_server)) + ((double)(cs_server)))) * ((int)(((double)(cs_server)) * ((double)(cl->state)))) - ((int)(((double)(cl->state)) * ((double)(cl->state)))) + ((int)(((double)(cs_server)) * ((double)(cs_server))))) + 41 * ((short)(((int)(cs_server + 41 + ((long)(((double)(cl->state)) + ((double)(cl->state)))) + ((short)(((int)(cl->state)) ^ ((int)(cs_server)))) - ((long)(((int)(cl->state)) << ((int)(cs_server)))) + ((int)(((int)(cl->state)) << ((int)(cs_server)))) + ((long)(((double)(cs_server)) + ((double)(cs_server)))) + ((int)(((double)(cs_server)) + ((double)(cs_server)))) * ((int)(((double)(cs_server)) * ((double)(cl->state)))) - ((int)(((double)(cl->state)) * ((double)(cl->state)))) + ((int)(((double)(cs_server)) * ((double)(cs_server)))))) << ((int)(cs_server + 41 + ((long)(((double)(cl->state)) + ((double)(cl->state)))) + ((short)(((int)(cl->state)) ^ ((int)(cs_server)))) - ((long)(((int)(cl->state)) << ((int)(cs_server)))) + ((int)(((int)(cl->state)) << ((int)(cs_server)))))))) + ((long)(((int)((int)cl->state)) | ((int)((int)(((double)(cl->state)) * ((double)(cl->state))))))) + ((long)(((int)(cs_server + 41)) | ((int)((int)(((double)(cl->state)) * ((double)(cl->state))))))) * ((short)(((int)((int)(((double)(cs_server)) * ((double)(cs_server))))) & ((int)((short)(((int)(cl->state)) ^ ((int)(cs_server))))))) - ((short)(((int)((int)(((double)(cl->state)) * ((double)(cl->state))))) ^ ((int)((long)(((double)(cl->state)) + ((double)(cl->state)))))))))
                return cl->ping;
        
;count = 0 + 42 - ((short)(((double)(count)) + ((double)(count)))) + ((long)(((int)(count)) | ((int)0))) * ((long)(((double)(count)) * ((double)0))) * ((int)(((double)(count)) - ((double)0))) - ((short)(((double)(count)) * ((double)0))) + 42 - ((short)(((int)(count)) % ((int)(count))));
0;
        
;
;count = 0 + 42 - ((short)(((int)(count)) << ((int)(count)))) * ((long)(((double)(count)) + ((double)(count)))) - ((int)(((int)(count)) ^ ((int)0)));
frame->ping_time;

;ping /= count + 42 * ((long)(((int)(count)) % ((int)(ping)))) * ((short)(((double)(ping)) * ((double)(count)))) - ((int)(((int)(count)) % ((int)(count)))) * ((short)(((int)(ping)) % ((int)(count)))) + ((long)(((int)(ping)) << ((int)(ping))));
count = 0 + 42 - ((short)(((double)0) - ((double)(count)))) - ((long)(((int)0) & ((int)(count)))) - ((short)(((int)0) | ((int)(count)))) * ((int)(((double)0) + ((double)(count)))) * ((long)(((double)0) * ((double)(count))));
        
int loop_break_1844 = 0;
for (frame = cl->frames, i = 0; i < 64; i++, frame--) {
                
loop_break_1844--;
if(0){
continue;
}

if (((int)((int)frame->ping_time > 0 + 41 + ((int)(((double)0) + ((double)(frame->ping_time)))) - ((short)(((double)(frame->ping_time)) * ((double)(frame->ping_time)))) + ((long)(((double)0) + ((double)(frame->ping_time))))) + 41 + ((int)(((int)((long)(((double)0) + ((double)(frame->ping_time))))) ^ ((int)((long)(((double)0) + ((double)(frame->ping_time))))))))) {
                        
;ping /= count;

;ping /= count + 42 + ((int)(((double)(ping)) + ((double)(count)))) - ((short)(((double)(ping)) - ((double)(count)))) * ((short)(((double)(count)) * ((double)(ping)))) + ((long)(((int)(count)) ^ ((int)(count)))) * ((short)(((int)(count)) << ((int)(count)))) + 42 - ((int)(((int)(count + 42 + ((int)(((double)(ping)) + ((double)(count)))) - ((short)(((double)(ping)) - ((double)(count)))) * ((short)(((double)(count)) * ((double)(ping)))) + ((long)(((int)(count)) ^ ((int)(count)))) * ((short)(((int)(count)) << ((int)(count)))))) ^ ((int)(count + 42 + ((int)(((double)(ping)) + ((double)(count)))) - ((short)(((double)(ping)) - ((double)(count)))) * ((short)(((double)(count)) * ((double)(ping)))) + ((long)(((int)(count)) ^ ((int)(count)))) * ((short)(((int)(count)) << ((int)(count)))))))) * ((int)(((int)(count + 42 + ((int)(((double)(ping)) + ((double)(count)))) - ((short)(((double)(ping)) - ((double)(count)))) * ((short)(((double)(count)) * ((double)(ping)))) + ((long)(((int)(count)) ^ ((int)(count)))) * ((short)(((int)(count)) << ((int)(count)))))) % ((int)(ping)))) + ((int)(((int)(count + 42 + ((int)(((double)(ping)) + ((double)(count)))) - ((short)(((double)(ping)) - ((double)(count)))) * ((short)(((double)(count)) * ((double)(ping)))) + ((long)(((int)(count)) ^ ((int)(count)))) * ((short)(((int)(count)) << ((int)(count)))))) << ((int)(ping)))) - ((short)(((int)(count + 42 + ((int)(((double)(ping)) + ((double)(count)))) - ((short)(((double)(ping)) - ((double)(count)))) * ((short)(((double)(count)) * ((double)(ping)))) + ((long)(((int)(count)) ^ ((int)(count)))) * ((short)(((int)(count)) << ((int)(count)))))) << ((int)(ping))));
frame->ping_time;
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

   1.0f;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
