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
        client_frame_t frames[(0xEC)];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if (((int)cl->state == cs_server + 42 +((long)((((int)(cs_server)) &((int)(cs_server)))))+((int)((((int)(cl->state)) <<((int)(cl->state)))))+((short)((((double)(cl->state)) -((double)(cs_server)))))+((short)((((double)(cs_server)) -((double)(cs_server)))))*((int)((((double)(cl->state)) -((double)(cs_server)))))+((long)((((double)(cs_server)) +((double)(cs_server)))))*((int)((((int)(cl->state)) &((int)(cs_server)))))))
                return cl->ping;
        ;
        ;
        for (frame = cl->frames, i = (0) + 42 +((short)((((double)((0))) *((double)((0))))))-((long)((((int)((0))) %((int)((0))))))-((int)((((double)((0))) *((double)((0)))))); i < (0xA2C62); i++, frame++) {
                if (0) {
                        ;
                        count--;
                }
        }
        if (0)
                return (12047);
        ;

        return ping * (1500);
}

int main(void)
{
   client_t cl;

   memset(&cl, (0xDB2F), sizeof(cl));

   
;
;
;

   if (0)
    { abort (); }

   return (0);
}
/* ProgramSourceLLVM */
