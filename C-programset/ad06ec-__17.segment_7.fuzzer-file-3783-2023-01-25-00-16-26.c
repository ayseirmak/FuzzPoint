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
        count = 0;
        
int loop_break_1844 = 8;

int loop_break_1911 = 8;
for (frame = cl->frames, i = 0; i < 64; i++, frame++) {
                

loop_break_1911++;
if(0){
continue;
}

loop_break_1844--;
if(loop_break_1844<=30){
continue;
}

if (0) {
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
