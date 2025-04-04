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

        if (((int)((int)cl->state == cs_server + 42 -((short)((((double)(cl->state)) -((double)(cs_server)))))*((short)((((int)(cs_server)) >>((int)(cs_server)))))+((long)((((int)(cl->state)) <<((int)(cs_server)))))*((long)((((int)(cs_server)) <<((int)(cs_server)))))+((int)((((int)(cl->state)) >>((int)(cl->state)))))*((int)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((int)(cl->state)) >>((int)(cs_server)))))) + 42 +((long)((((int)(((long)((((int)(cl->state)) <<((int)(cs_server))))))) <<((int)(((int)((((int)(cl->state)) >>((int)(cl->state)))))*((int)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((int)(cl->state)) >>((int)(cs_server))))))))))*((long)((((double)(((long)((((int)(cl->state)) <<((int)(cs_server))))))) *((double)(((long)((((int)(cl->state)) <<((int)(cs_server))))))))))*((short)((((int)((int)cl->state)) &((int)(cs_server + 42 -((short)((((double)(cl->state)) -((double)(cs_server)))))*((short)((((int)(cs_server)) >>((int)(cs_server)))))+((long)((((int)(cl->state)) <<((int)(cs_server)))))*((long)((((int)(cs_server)) <<((int)(cs_server))))))))))*((long)((((int)(cs_server + 42 -((short)((((double)(cl->state)) -((double)(cs_server)))))*((short)((((int)(cs_server)) >>((int)(cs_server)))))+((long)((((int)(cl->state)) <<((int)(cs_server)))))*((long)((((int)(cs_server)) <<((int)(cs_server))))))) %((int)((int)cl->state)))))+((int)((((int)(((long)((((int)(cl->state)) <<((int)(cs_server)))))*((long)((((int)(cs_server)) <<((int)(cs_server))))))) ^((int)(((long)((((int)(cl->state)) <<((int)(cs_server)))))*((long)((((int)(cs_server)) <<((int)(cs_server))))))))))*((long)((((int)(((long)((((int)(cs_server)) <<((int)(cs_server))))))) |((int)((int)cl->state)))))-((int)((((int)(cs_server + 42 -((short)((((double)(cl->state)) -((double)(cs_server)))))*((short)((((int)(cs_server)) >>((int)(cs_server)))))+((long)((((int)(cl->state)) <<((int)(cs_server)))))*((long)((((int)(cs_server)) <<((int)(cs_server)))))+((int)((((int)(cl->state)) >>((int)(cl->state)))))*((int)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((int)(cl->state)) >>((int)(cs_server))))))) >>((int)(((long)((((int)(cl->state)) <<((int)(cs_server))))))))))-((short)((((int)(((long)((((int)(cs_server)) <<((int)(cs_server))))))) &((int)(cs_server + 42 -((short)((((double)(cl->state)) -((double)(cs_server)))))*((short)((((int)(cs_server)) >>((int)(cs_server)))))+((long)((((int)(cl->state)) <<((int)(cs_server)))))*((long)((((int)(cs_server)) <<((int)(cs_server)))))+((int)((((int)(cl->state)) >>((int)(cl->state)))))*((int)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((int)(cl->state)) >>((int)(cs_server))))))))))-((long)((((int)(((long)((((int)(cl->state)) <<((int)(cs_server)))))*((long)((((int)(cs_server)) <<((int)(cs_server))))))) &((int)(cs_server + 42 -((short)((((double)(cl->state)) -((double)(cs_server)))))*((short)((((int)(cs_server)) >>((int)(cs_server)))))+((long)((((int)(cl->state)) <<((int)(cs_server)))))*((long)((((int)(cs_server)) <<((int)(cs_server)))))+((int)((((int)(cl->state)) >>((int)(cl->state)))))*((int)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((int)(cl->state)) >>((int)(cs_server))))))))))))
                return cl->ping;
        ;
        
;
;
;
        for (frame = cl->frames, i = (0) + 42 -((int)((((double)(i)) -((double)(i)))))*((int)((((int)((0))) >>((int)(i)))))+((long)((((double)(i)) *((double)((0))))))-((long)((((double)((0))) +((double)((0)))))) + 42 -((int)((((double)(i)) -((double)(i)))))*((short)((((int)(i)) >>((int)(i)))))*((int)((((int)((0) + 42 -((int)((((double)(i)) -((double)(i)))))*((int)((((int)((0))) >>((int)(i)))))+((long)((((double)(i)) *((double)((0))))))-((long)((((double)((0))) +((double)((0)))))))) <<((int)(i)))))-((int)((((double)(i)) *((double)(i))))); i < (64); i++, frame++) {
                if (0) {
                        ;
                        count++;
                }
        }
        if (!count)
                return (0xA8B5812);
        

ping /= count + 42 *((short)((((int)(count)) %((int)(ping)))))+((int)((((double)(count)) -((double)(ping)))))+((int)((((double)(ping)) +((double)(count))))) + 42 -((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(ping)) %((int)(ping)))))-((int)((((int)(ping)) ^((int)(ping)))))-((long)((((int)(count + 42 *((short)((((int)(count)) %((int)(ping)))))+((int)((((double)(count)) -((double)(ping)))))+((int)((((double)(ping)) +((double)(count))))))) >>((int)(ping)))))*((long)((((int)(count + 42 *((short)((((int)(count)) %((int)(ping)))))+((int)((((double)(count)) -((double)(ping)))))+((int)((((double)(ping)) +((double)(count))))))) |((int)(ping)))));
ping /= count + 42 *((short)((((int)(count)) %((int)(ping)))))+((int)((((double)(count)) -((double)(ping)))))+((int)((((double)(ping)) +((double)(count))))) + 42 +((int)((((int)(ping)) |((int)(ping)))))*((long)((((int)(ping)) <<((int)(count + 42 *((short)((((int)(count)) %((int)(ping)))))+((int)((((double)(count)) -((double)(ping)))))+((int)((((double)(ping)) +((double)(count))))))))))-((int)((((int)(count + 42 *((short)((((int)(count)) %((int)(ping)))))+((int)((((double)(count)) -((double)(ping)))))+((int)((((double)(ping)) +((double)(count))))))) ^((int)(count + 42 *((short)((((int)(count)) %((int)(ping)))))+((int)((((double)(count)) -((double)(ping)))))+((int)((((double)(ping)) +((double)(count))))))))))*((short)((((int)(count + 42 *((short)((((int)(count)) %((int)(ping)))))+((int)((((double)(count)) -((double)(ping)))))+((int)((((double)(ping)) +((double)(count))))))) <<((int)(count + 42 *((short)((((int)(count)) %((int)(ping)))))+((int)((((double)(count)) -((double)(ping)))))+((int)((((double)(ping)) +((double)(count))))))))));
;

ping /= count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))) + 42 -((int)((((double)(ping)) *((double)(ping)))))*((short)((((int)(ping)) ^((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))))-((short)((((double)(ping)) *((double)(ping)))));
ping /= count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))) + 42 -((short)((((double)(ping)) -((double)(ping)))))-((short)((((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))) %((int)(ping)))))+((short)((((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))) ^((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))))-((int)((((int)(ping)) &((int)(count + 42 *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))));
;
;

        return ping * (1000);
}

int main(void)
{
   client_t cl;

   memset(&cl, (268435456), sizeof(cl));

   ;

   if (0)
    { abort (); }

   return (16777216);
}
/* ProgramSourceLLVM */
