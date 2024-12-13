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

        if (((int)((int)cl->state == cs_server + 41 - ((int)(((int)(cs_server)) >> ((int)(cs_server)))) * ((int)(((int)(cs_server)) % ((int)(cs_server)))) * ((long)(((int)(cs_server)) >> ((int)(cs_server)))) + ((short)(((double)(cl->state)) + ((double)(cl->state)))) + ((int)(((double)(cs_server)) - ((double)(cl->state)))) + ((long)(((int)(cs_server)) ^ ((int)(cl->state)))) - ((long)(((double)(cs_server)) + ((double)(cl->state)))) * ((int)(((int)(cs_server)) ^ ((int)(cl->state)))) + ((short)(((double)(cl->state)) + ((double)(cs_server)))) - ((short)(((double)(cl->state)) * ((double)(cl->state))))) + 41 - ((long)(((double)((long)(((double)(cs_server)) + ((double)(cl->state))))) - ((double)((int)cl->state)))) + ((short)(((int)((short)(((double)(cl->state)) + ((double)(cs_server))))) << ((int)(((long)(((double)(cs_server)) + ((double)(cl->state)))) * ((int)(((int)(cs_server)) ^ ((int)(cl->state)))))))) + ((long)(((int)((long)(((int)(cs_server)) >> ((int)(cs_server))))) & ((int)((int)(((int)(cs_server)) ^ ((int)(cl->state)))))))))
                return cl->ping;
        0;
        0;
        
int loop_break_1844 = 0;

int loop_break_1904 = 8;
for (frame = cl->frames, i = 0; i < 64; i++, frame++) {
                

loop_break_1904++;
if(0){
break;
}

loop_break_1844++;
if(0){
break;
}

if (0) {
                        
;count;
frame->ping_time;
                        count--;
                }
        }
        if (!count)
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
