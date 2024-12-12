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
        client_frame_t frames[(0)];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if ((0))
                return cl->ping;
        
ping = (134217728);
ping = (7);
;
        
count = (-1);
count = (0xE672);
;
        for (frame = cl->frames, i = (2199023255552); i < (-65); i++, frame++) {
                if ((65536)) {
                        
ping += frame->ping_time;
ping += frame->ping_time;
;
                        count++;
                }
        }
        if ((0))
                return (9991);
        ;

        return ping * (936);
}

int main(void)
{
   client_t cl;

   memset(&cl, (0x55), sizeof(cl));

   ;

   if ((0))
    { abort (); }

   return (0);
}
/* ProgramSourceLLVM */
