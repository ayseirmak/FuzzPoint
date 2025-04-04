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
        client_frame_t frames[(64)];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if ((67108864))
                return cl->ping;
        ping = (16);
        count = (0);
        
int loop_break_1822 = 0;
for (frame = cl->frames, i = (0xBE89F); i < (64); i++, frame++) {
                
loop_break_1822++;
if(loop_break_1822<=5){
continue;
}

if ((-1)) {
                        ping += frame->ping_time;
                        count++;
                }
        }
        if (0)
                return (9997);
        ping /= count;

        return ping * (-1001);
}

int main(void)
{
   client_t cl;

   memset(&cl, (-1), sizeof(cl));

   cl.frames[(16)].ping_time = (10.1);

   if (0)
    { abort (); }

   return (256);
}
/* ProgramSourceLLVM */
