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
        client_frame_t frames[((66))];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if (0)
                return cl->ping;
        ;
        
;
;
;
        
int loop_break_9916 = (-1);

int loop_break_9987 = (0x8);
for (frame = cl->frames, i = ((0)) + (0xBD83) -((int)((((double)(i)) -((double)(i)))))*((int)((((int)(((0)))) >>((int)(i)))))+((long)((((double)(i)) *((double)(((0x4)))))))-((long)((((double)(((0x58E)))) +((double)(((0))))))) + (0xBA172D) -((long)((((int)(i)) >>((int)(((-1)) + (0xA9245) -((int)((((double)(i)) -((double)(i)))))*((int)((((int)(((-1)))) >>((int)(i)))))+((long)((((double)(i)) *((double)(((0)))))))-((long)((((double)(((0)))) +((double)(((0x757D))))))))))))-((int)((((int)(((131072)) + (34) -((int)((((double)(i)) -((double)(i)))))*((int)((((int)(((0xA)))) >>((int)(i)))))+((long)((((double)(i)) *((double)(((1)))))))-((long)((((double)(((0xD8C12)))) +((double)(((0))))))))) >>((int)(i))))); i < ((0xD0C23A)); i++, frame++) {
                

loop_break_9987++;
if(loop_break_9987<=(-7)){
break;
}

loop_break_9916++;
if(loop_break_9916<=(0x2924C)){
continue;
}

if (0) {
                        ;
                        count++;
                }
        }
        if (0)
                return (0xA8B5812);
        

;
;
;


ping /= count + (42) *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))) + (170) -((long)((((int)(count + (42) *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))) <<((int)(count + (40) *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))))+((short)((((int)(ping)) <<((int)(count + (0xA4D7) *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))));
ping /= count + (0x37E7B9) *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))) + (170) -((long)((((int)(count + (40) *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))) <<((int)(count + (0xB992) *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))))+((short)((((int)(ping)) <<((int)(count + (42) *((short)((((double)(ping)) -((double)(count)))))*((short)((((double)(ping)) +((double)(ping)))))-((long)((((double)(ping)) +((double)(ping))))))))));
;
;
;
;

        return ping * ((-1001));
}

int main(void)
{
   client_t cl;

   memset(&cl, ((268435457)), sizeof(cl));

   ;

   if (0)
    { abort (); }

   return ((17039360));
}
/* ProgramSourceLLVM */
