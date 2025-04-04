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

        if (((int)((int)cl->state == cs_server + (0xFDEE5C) +((long)((((int)(cl->state)) |((int)(cl->state)))))*((int)((((int)(cs_server)) ^((int)(cl->state)))))+((long)((((int)(cl->state)) %((int)(cl->state)))))+((long)((((double)(cs_server)) +((double)(cs_server)))))) + 42 +((int)((((int)(((int)((((int)(cs_server)) ^((int)(cl->state))))))) <<((int)(((long)((((double)(cs_server)) +((double)(cs_server))))))))))*((short)((((int)(cs_server + (0xFDEE5C) +((long)((((int)(cl->state)) |((int)(cl->state)))))*((int)((((int)(cs_server)) ^((int)(cl->state)))))+((long)((((int)(cl->state)) %((int)(cl->state))))))) <<((int)(((long)((((double)(cs_server)) +((double)(cs_server))))))))))-((long)((((int)(cs_server + (0xFDEE5C) +((long)((((int)(cl->state)) |((int)(cl->state)))))*((int)((((int)(cs_server)) ^((int)(cl->state))))))) >>((int)(cs_server + (0xFDEE5C) +((long)((((int)(cl->state)) |((int)(cl->state)))))*((int)((((int)(cs_server)) ^((int)(cl->state)))))+((long)((((int)(cl->state)) %((int)(cl->state))))))))))))
                return cl->ping;
        
;

ping = (32) + (42) +((long)((((double)((2097152))) *((double)((0x49))))))-((long)((((int)(ping)) &((int)(ping)))))-((int)((((int)((2))) |((int)(ping)))))+((short)((((double)((16777216))) +((double)(ping))))) + 42 *((short)((((int)(ping)) ^((int)((32) + (42) +((long)((((double)((2097152))) *((double)((0x49))))))-((long)((((int)(ping)) &((int)(ping)))))-((int)((((int)((2))) |((int)(ping)))))+((short)((((double)((16777216))) +((double)(ping))))))))))+((short)((((double)(ping)) +((double)(ping)))))+((short)((((int)(ping)) |((int)((32) + (42) +((long)((((double)((2097152))) *((double)((0x49))))))-((long)((((int)(ping)) &((int)(ping)))))-((int)((((int)((2))) |((int)(ping)))))+((short)((((double)((16777216))) +((double)(ping))))))))));
ping = (32) + (42) +((long)((((double)((2097152))) *((double)((0x49))))))-((long)((((int)(ping)) &((int)(ping)))))-((int)((((int)((2))) |((int)(ping)))))+((short)((((double)((16777216))) +((double)(ping))))) + 42 -((long)((((double)(ping)) *((double)(ping)))))-((int)((((int)((32) + (42) +((long)((((double)((2097152))) *((double)((0x49))))))-((long)((((int)(ping)) &((int)(ping)))))-((int)((((int)((2))) |((int)(ping)))))+((short)((((double)((16777216))) +((double)(ping))))))) >>((int)((32) + (42) +((long)((((double)((2097152))) *((double)((0x49))))))-((long)((((int)(ping)) &((int)(ping)))))-((int)((((int)((2))) |((int)(ping)))))+((short)((((double)((16777216))) +((double)(ping))))))))));
;
;
        ;
        
int loop_break_1844 = (0);

int loop_break_13318 = 0;
for (frame = cl->frames, i = (2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))) + 42 -((short)((((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))) >>((int)(i)))))*((long)((((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))) <<((int)(i))))); i < (-65); i--, frame++) {
                

loop_break_13318++;
if(0){
continue;
}

loop_break_1844++;
if(0){
continue;
}

if (0) {
                        
;
;
;
                        count--;
                }
        }
        if (!count)
                return (-10000);
        ;

        return ping * (968);
}

int main(void)
{
   client_t cl;

   memset(&cl, (0), sizeof(cl));

   ;

   if (0)
    { abort (); }

   return (0);
}
/* ProgramSourceLLVM */
