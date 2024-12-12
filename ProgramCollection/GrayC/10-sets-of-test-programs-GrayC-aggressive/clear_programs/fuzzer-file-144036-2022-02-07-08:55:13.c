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
        client_frame_t frames[(63)];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if ((0x3D1E6))
                return cl->ping;
        
ping = (137438953472) + (42) +((long)((((double)(ping)) +((double)(ping)))));
ping = (16) + (0x2D7) +((long)((((double)(ping)) +((double)(ping)))));
;
        
count = (0) + (106) -((short)((((int)(count)) %((int)(count)))));
count = (0) + (42) -((short)((((int)(count)) %((int)(count)))));
;
        
int loop_break_1844 = (0x9);

int loop_break_4559 = (0xFD8);

int loop_break_3080 = (0);
for (frame = cl->frames, i = (0) + (42) +((int)((((int)((0))) ^((int)((-1)))))); i < (-65); i++, frame++) {
                


loop_break_3080++;
if(loop_break_3080<=(0xEEA8)){
break;
}

loop_break_4559++;
if((0x8C9)){
continue;
}

loop_break_1844++;
if((0)){
continue;
}

if ((512)) {
                        
ping += frame->ping_time + (170) -((short)((((int)(frame->ping_time)) >>((int)(ping)))))+((short)((((int)(ping)) ^((int)(frame->ping_time)))));
ping += frame->ping_time + (42) -((short)((((int)(frame->ping_time)) >>((int)(ping)))))+((short)((((int)(ping)) ^((int)(frame->ping_time)))));
;
                        count++;
                }
        }
        if (!count)
                return (0xBFE899);
        ;

        return ping * (-1001);
}

int main(void)
{
   client_t cl;

   memset(&cl, (32), sizeof(cl));

   ;

   if ((0))
    { abort (); }

   return (0);
}
/* ProgramSourceLLVM */
