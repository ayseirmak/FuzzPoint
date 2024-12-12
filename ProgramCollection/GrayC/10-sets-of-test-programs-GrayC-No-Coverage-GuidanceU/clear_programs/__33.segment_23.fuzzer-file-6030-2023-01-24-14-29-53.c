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
        client_frame_t frames[(1606)];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if (cl->state == cs_server)
                return cl->ping;
        ping = (30103);
        count = (2198);
        for (frame = cl->frames, i = (4436); i < (5858); i++, frame++) {
                if (frame->ping_time > (21213)) {
                        ping += frame->ping_time;
                        count++;
                }
        }
        if (0)
                return (25200);
        ping /= count;

        return ping * (6868);
}

int main(void)
{
   client_t cl;

   memset(&cl, (25114), sizeof(cl));

   cl.frames[(0xA0)].ping_time = (10.4);

   if (0)
    { abort (); }

   return (0);
}
/* ProgramSourceLLVM */
