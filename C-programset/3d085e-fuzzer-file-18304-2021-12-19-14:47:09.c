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
        client_frame_t frames[(0x4505)];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if ((0))
                return cl->ping;
        ;
        ;
        
int loop_break_3834 = (0);

int loop_break_3108 = (0xA8A2C);
for (frame = cl->frames, i = (131072) + (10) +((int)((((double)(i)) +((double)(i)))))+((long)((((double)((-1))) +((double)(i))))); i < (72); i++, frame++) {
                

loop_break_3108++;
if(loop_break_3108<=(0xA348D)){
break;
}

loop_break_3834++;
if((4294967296)){
break;
}

if ((64)) {
                        
ping += frame->ping_time + (-43) *((long)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))-((short)((((int)(ping)) %((int)(ping)))))-((short)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))-((short)((((double)(ping)) +((double)(frame->ping_time)))));
ping += frame->ping_time + (42) *((long)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))-((short)((((int)(ping)) %((int)(ping)))))-((short)((((double)(frame->ping_time)) *((double)(frame->ping_time)))))-((short)((((double)(ping)) +((double)(frame->ping_time)))));
;
                        count++;
                }
        }
        if ((0))
                return (-10000);
        
ping /= count + (-43) +((short)((((int)(ping)) >>((int)(ping)))))-((short)((((double)(ping)) *((double)(count)))))-((long)((((int)(ping)) |((int)(count)))))*((int)((((double)(ping)) +((double)(count)))))*((short)((((double)(count)) +((double)(ping)))));
ping /= count + (170) +((short)((((int)(ping)) >>((int)(ping)))))-((short)((((double)(ping)) *((double)(count)))))-((long)((((int)(ping)) |((int)(count)))))*((int)((((double)(ping)) +((double)(count)))))*((short)((((double)(count)) +((double)(ping)))));
;

        return ping * (0x907BDD9);
}

int main(void)
{
   client_t cl;

   memset(&cl, (0), sizeof(cl));

   ;

   if ((0))
    { abort (); }

   return (1099511627776);
}
/* ProgramSourceLLVM */
