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
        client_frame_t frames[(65)];
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
        
int loop_break_1844 = 8;

int loop_break_1894 = 8;

int loop_break_4750 = 0;
for (frame = cl->frames, i = (64) + 42 -((long)((((double)((64))) -((double)((64))))))+((int)((((double)(i)) -((double)(i))))) + 42 -((int)((((double)((64) + 42 -((long)((((double)((64))) -((double)((64))))))+((int)((((double)(i)) -((double)(i))))))) *((double)(i))))); i < (-65); i++, frame++) {
                


loop_break_4750++;
if(loop_break_4750<=3){
break;
}

loop_break_1894++;
if(((int)((int)loop_break_1894<=3 + 42 -((long)((((double)(loop_break_1894)) -((double)(3)))))+((short)((((double)(loop_break_1894)) +((double)(3)))))) + 42 *((short)((((int)(((short)((((double)(loop_break_1894)) +((double)(3))))))) >>((int)(3 + 42 -((long)((((double)(loop_break_1894)) -((double)(3))))))))))*((short)((((double)((int)loop_break_1894)) *((double)(3 + 42 -((long)((((double)(loop_break_1894)) -((double)(3))))))))))+((long)((((int)(3 + 42 -((long)((((double)(loop_break_1894)) -((double)(3)))))+((short)((((double)(loop_break_1894)) +((double)(3))))))) <<((int)(3 + 42 -((long)((((double)(loop_break_1894)) -((double)(3))))))))))+((int)((((int)(((short)((((double)(loop_break_1894)) +((double)(3))))))) <<((int)(3 + 42 -((long)((((double)(loop_break_1894)) -((double)(3))))))))))+((long)((((int)(((long)((((double)(loop_break_1894)) -((double)(3))))))) &((int)(3 + 42 -((long)((((double)(loop_break_1894)) -((double)(3)))))+((short)((((double)(loop_break_1894)) +((double)(3))))))))))-((int)((((int)((int)loop_break_1894)) |((int)(3 + 42 -((long)((((double)(loop_break_1894)) -((double)(3)))))+((short)((((double)(loop_break_1894)) +((double)(3)))))))))))){
break;
}

loop_break_1844++;
if(0){
break;
}

if (0) {
                        ;
                        count++;
                }
        }
        if (!count)
                return (-10000);
        
;
;
;

        return ping * (1004);
}

int main(void)
{
   client_t cl;

   memset(&cl, (16), sizeof(cl));

   ;

   if (0)
    { abort (); }

   return (4194304);
}
/* ProgramSourceLLVM */
