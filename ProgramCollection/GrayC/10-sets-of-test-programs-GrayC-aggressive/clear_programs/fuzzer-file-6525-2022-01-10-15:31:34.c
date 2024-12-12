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

        if (0)
                return cl->ping;
        
;
;
;
        ;
        
int loop_break_1844 = 8;
for (frame = cl->frames, i = (2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))) + 42 +((long)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))*((short)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))-((short)((((int)(i)) |((int)(i))))) + 42 +((long)((((double)(i)) *((double)(i)))))+((short)((((double)(i)) *((double)(i)))))-((short)((((double)(i)) +((double)(i))))) + 42 *((int)((((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))) + 42 +((long)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))*((short)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))-((short)((((int)(i)) |((int)(i))))) + 42 +((long)((((double)(i)) *((double)(i)))))+((short)((((double)(i)) *((double)(i)))))-((short)((((double)(i)) +((double)(i))))))) <<((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))) + 42 +((long)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))*((short)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))-((short)((((int)(i)) |((int)(i))))) + 42 +((long)((((double)(i)) *((double)(i)))))+((short)((((double)(i)) *((double)(i)))))-((short)((((double)(i)) +((double)(i))))))))))+((long)((((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))) + 42 +((long)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))*((short)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))-((short)((((int)(i)) |((int)(i))))) + 42 +((long)((((double)(i)) *((double)(i)))))+((short)((((double)(i)) *((double)(i)))))-((short)((((double)(i)) +((double)(i))))))) &((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))) + 42 +((long)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))*((short)((((int)(i)) |((int)((2048) + (10) *((long)((((double)((0))) *((double)(i)))))+((int)((((int)((-1))) %((int)(i))))))))))-((short)((((int)(i)) |((int)(i))))) + 42 +((long)((((double)(i)) *((double)(i)))))+((short)((((double)(i)) *((double)(i)))))-((short)((((double)(i)) +((double)(i))))))))))+((int)((((double)(i)) *((double)(i))))); i < (-65); i--, frame++) {
                
loop_break_1844++;
if(0){
continue;
}

if (0) {
                        

ping += frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 -((int)((((double)(ping)) +((double)(frame->ping_time))))) + 42 -((short)((((int)(frame->ping_time + (42))) >>((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))-((short)((((int)(ping)) ^((int)(((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))*((long)((((double)(frame->ping_time)) +((double)(((int)((((double)(ping)) +((double)(frame->ping_time))))))))))+((short)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping))))))) &((int)(((int)((((double)(ping)) +((double)(frame->ping_time)))))))))) + 42 *((long)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 -((int)((((double)(ping)) +((double)(frame->ping_time))))) + 42 -((short)((((int)(frame->ping_time + (42))) >>((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))-((short)((((int)(ping)) ^((int)(((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))*((long)((((double)(frame->ping_time)) +((double)(((int)((((double)(ping)) +((double)(frame->ping_time))))))))))+((short)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping))))))) &((int)(((int)((((double)(ping)) +((double)(frame->ping_time)))))))))))) %((int)(42)))))+((long)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))) >>((int)(((short)((((int)(frame->ping_time + (42))) >>((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping)))))))))))))))-((short)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 -((int)((((double)(ping)) +((double)(frame->ping_time))))))) &((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 -((int)((((double)(ping)) +((double)(frame->ping_time))))))))));
ping += frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 -((int)((((double)(ping)) +((double)(frame->ping_time))))) + 42 -((short)((((int)(frame->ping_time + (42))) >>((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))-((short)((((int)(ping)) ^((int)(((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))*((long)((((double)(frame->ping_time)) +((double)(((int)((((double)(ping)) +((double)(frame->ping_time))))))))))+((short)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping))))))) &((int)(((int)((((double)(ping)) +((double)(frame->ping_time)))))))))) + 42 *((long)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 -((int)((((double)(ping)) +((double)(frame->ping_time))))) + 42 -((short)((((int)(frame->ping_time + (42))) >>((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))-((short)((((int)(ping)) ^((int)(((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))*((long)((((double)(frame->ping_time)) +((double)(((int)((((double)(ping)) +((double)(frame->ping_time))))))))))+((short)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping))))))) &((int)(((int)((((double)(ping)) +((double)(frame->ping_time)))))))))))) %((int)(42)))))+((long)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))) >>((int)(((short)((((int)(frame->ping_time + (42))) >>((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping)))))))))))))))-((short)((((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 -((int)((((double)(ping)) +((double)(frame->ping_time))))))) &((int)(frame->ping_time + (42) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 -((int)((((double)(ping)) +((double)(frame->ping_time))))))))));
;

ping += frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 +((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping)))))))))) + 42 *((int)((((int)(ping)) %((int)(((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))))))) + 42 -((int)((((int)(((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping)))))))))))) ^((int)(42 *((int)((((int)(ping)) %((int)(((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))))))))))))*((short)((((int)((-43))) ^((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 +((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping)))))))))))))))*((long)((((int)(((int)((((int)(ping)) ^((int)(ping))))))) %((int)(((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))-((short)((((int)((-43))) |((int)((-43))))));
ping += frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 +((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping)))))))))) + 42 *((int)((((int)(ping)) %((int)(((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))))))) + 42 -((int)((((int)(((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping)))))))))))) ^((int)(42 *((int)((((int)(ping)) %((int)(((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))))))))))))*((short)((((int)((-43))) ^((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))) + 42 +((int)((((int)(frame->ping_time + (-43))) %((int)(frame->ping_time + (-43) -((int)((((int)(ping)) ^((int)(ping)))))-((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping)))))))))))))))*((long)((((int)(((int)((((int)(ping)) ^((int)(ping))))))) %((int)(((long)((((double)(ping)) -((double)(ping)))))*((short)((((int)(frame->ping_time)) ^((int)(ping))))))))))-((short)((((int)((-43))) |((int)((-43))))));
;
;
                        count++;
                }
        }
        if (0)
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
