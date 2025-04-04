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

        if (((int)((int)((int)cl->state == cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))) + ((int)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) + ((double)(cs_server)))))) + 41 + ((short)((((int)(((int)((((double)(cl->state)) - ((double)(cs_server))))))) | ((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))) + ((int)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) + ((double)(cs_server)))))))))) - ((long)((((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))) + ((int)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) + ((double)(cs_server))))))) << ((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server)))))))))) * ((int)((((int)(((int)((((double)(cl->state)) + ((double)(cs_server))))))) >> ((int)(((long)((((int)(cl->state)) % ((int)(cs_server)))))))))) * ((long)((((int)(((int)((((double)(cl->state)) - ((double)(cs_server))))))) ^ ((int)(((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))))))))) + 41 - ((int)((((int)(((long)((((int)(((int)((((double)(cl->state)) - ((double)(cs_server))))))) ^ ((int)(((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server)))))))))))) | ((int)(((long)((((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))) + ((int)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) + ((double)(cs_server))))))) << ((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server)))))))))) * ((int)((((int)(((int)((((double)(cl->state)) + ((double)(cs_server))))))) >> ((int)(((long)((((int)(cl->state)) % ((int)(cs_server)))))))))) * ((long)((((int)(((int)((((double)(cl->state)) - ((double)(cs_server))))))) ^ ((int)(((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))))))))))))) + ((short)((((double)(((int)((((int)(((int)((((double)(cl->state)) + ((double)(cs_server))))))) >> ((int)(((long)((((int)(cl->state)) % ((int)(cs_server)))))))))))) + ((double)(((int)((((int)(((int)((((double)(cl->state)) + ((double)(cs_server))))))) >> ((int)(((long)((((int)(cl->state)) % ((int)(cs_server))))))))))))))) * ((int)((((int)(((long)((((int)(((int)((((double)(cl->state)) - ((double)(cs_server))))))) ^ ((int)(((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server)))))))))))) ^ ((int)(((long)((((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))) + ((int)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) + ((double)(cs_server))))))) << ((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server)))))))))) * ((int)((((int)(((int)((((double)(cl->state)) + ((double)(cs_server))))))) >> ((int)(((long)((((int)(cl->state)) % ((int)(cs_server))))))))))))))) + ((int)((((int)((int)((int)cl->state == cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))) + ((int)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) + ((double)(cs_server)))))) + 41 + ((short)((((int)(((int)((((double)(cl->state)) - ((double)(cs_server))))))) | ((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))) + ((int)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) + ((double)(cs_server)))))))))))) << ((int)(((long)((((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server))))) + ((int)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) + ((double)(cs_server))))))) << ((int)(cs_server + 41 - ((long)((((int)(cl->state)) % ((int)(cs_server))))) - ((int)((((double)(cl->state)) - ((double)(cs_server))))) - ((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server)))))))))) * ((int)((((int)(((int)((((double)(cl->state)) + ((double)(cs_server))))))) >> ((int)(((long)((((int)(cl->state)) % ((int)(cs_server))))))))))))))) + ((long)((((int)(((long)((((int)(((int)((((double)(cl->state)) - ((double)(cs_server))))))) ^ ((int)(((int)((((double)(cs_server)) * ((double)(cl->state))))) * ((long)((((int)(cl->state)) >> ((int)(cs_server)))))))))))) & ((int)(((int)((((int)(((int)((((double)(cl->state)) + ((double)(cs_server))))))) >> ((int)(((long)((((int)(cl->state)) % ((int)(cs_server)))))))))))))))))
                return cl->ping;
        0;
        0 + 42 - ((int)((((double)(count)) * ((double)(0))))) * ((short)((((double)(0)) * ((double)(count)))));
        
int loop_break_8039 = 8;

int loop_break_8102 = 0;

int loop_break_16517 = 0;
for (frame = cl->frames, i = 0 + 42 - ((int)((((double)(i)) - ((double)(0))))) - ((int)((((double)(0)) * ((double)(0))))) - ((long)((((int)(i)) << ((int)(0))))); i < 64; i++, frame++) {
                


loop_break_16517++;
if(loop_break_16517<=17){
break;
}

loop_break_8102++;
if(((int)loop_break_8102<=30 + 41 * ((int)((((int)(30)) & ((int)(30))))) - ((int)((((double)(loop_break_8102)) - ((double)(loop_break_8102))))) * ((int)((((double)(loop_break_8102)) + ((double)(loop_break_8102))))))){
continue;
}

loop_break_8039++;
if(((int)loop_break_8039<=21 + 41 + ((short)((((double)(loop_break_8039)) - ((double)(21))))))){
break;
}

if (0) {
                        
;ping /= count;
frame->ping_time + 42 * ((short)((((int)(ping)) >> ((int)(frame->ping_time))))) + ((int)((((double)(ping)) * ((double)(ping))))) * ((long)((((int)(frame->ping_time)) & ((int)(ping))))) - ((long)((((double)(ping)) - ((double)(ping)))));
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
