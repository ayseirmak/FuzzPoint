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

        if (((int)((int)cl->state == cs_server + 41 + ((long)(((int)(cl->state)) ^ ((int)(cl->state)))) - ((short)(((int)(cl->state)) & ((int)(cs_server)))) + ((int)(((int)(cl->state)) % ((int)(cs_server)))) - ((short)(((double)(cs_server)) + ((double)(cs_server))))) + 41 * ((long)(((double)((short)(((double)(cs_server)) + ((double)(cs_server))))) * ((double)(cs_server + 41 + ((long)(((int)(cl->state)) ^ ((int)(cl->state)))) - ((short)(((int)(cl->state)) & ((int)(cs_server)))) + ((int)(((int)(cl->state)) % ((int)(cs_server)))) - ((short)(((double)(cs_server)) + ((double)(cs_server)))))))) * ((int)(((int)((int)cl->state)) << ((int)(cs_server + 41 + ((long)(((int)(cl->state)) ^ ((int)(cl->state)))) - ((short)(((int)(cl->state)) & ((int)(cs_server)))) + ((int)(((int)(cl->state)) % ((int)(cs_server)))) - ((short)(((double)(cs_server)) + ((double)(cs_server)))))))) * ((long)(((double)((int)cl->state)) - ((double)((int)(((int)(cl->state)) % ((int)(cs_server))))))) + ((short)(((double)(cs_server + 41 + ((long)(((int)(cl->state)) ^ ((int)(cl->state)))) - ((short)(((int)(cl->state)) & ((int)(cs_server)))) + ((int)(((int)(cl->state)) % ((int)(cs_server)))) - ((short)(((double)(cs_server)) + ((double)(cs_server)))))) - ((double)((int)cl->state)))) * ((int)(((double)((short)(((double)(cs_server)) + ((double)(cs_server))))) - ((double)((short)(((int)(cl->state)) & ((int)(cs_server))))))) - ((long)(((int)(cs_server + 41 + ((long)(((int)(cl->state)) ^ ((int)(cl->state)))) - ((short)(((int)(cl->state)) & ((int)(cs_server)))))) | ((int)(cs_server + 41 + ((long)(((int)(cl->state)) ^ ((int)(cl->state)))) - ((short)(((int)(cl->state)) & ((int)(cs_server))))))))))
                return cl->ping;
        
;count = 0 + 42 + ((short)(((int)(count)) % ((int)(count)))) + ((int)(((int)0) << ((int)(count)))) - ((short)(((double)(count)) * ((double)(count)))) + ((short)(((double)(count)) - ((double)0))) - ((long)(((double)0) - ((double)0)));
0;
        
;ping += frame->ping_time;
count = 0 + 42 * ((long)(((int)0) >> ((int)(count)))) * ((int)(((int)0) ^ ((int)(count))));
        
int loop_break_3174 = 0;
for (frame = cl->frames, i = 0 + 42 * ((int)(((int)(i)) & ((int)(i)))) + ((long)(((int)0) >> ((int)0))) * ((short)(((int)(i)) >> ((int)(i)))) - ((short)(((double)0) - ((double)0))) + ((long)(((double)(i)) - ((double)0))); i < 64; i++, frame++) {
                
loop_break_3174++;
if(0){
break;
}

if (0) {
                        ping += frame->ping_time;
                        count++;
                }
        }
        if (0)
                return 9999;
        count;

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
