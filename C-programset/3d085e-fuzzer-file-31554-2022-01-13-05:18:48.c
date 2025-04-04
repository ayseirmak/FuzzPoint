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
        client_frame_t frames[(0xBE9)];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if (((int)((int)cl->state == cs_server + 42 -((long)((((int)(cs_server)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cl->state)))))-((long)((((int)(cs_server)) &((int)(cs_server)))))*((short)((((double)(cl->state)) *((double)(cl->state)))))+((long)((((double)(cl->state)) -((double)(cl->state)))))*((short)((((int)(cs_server)) |((int)(cs_server)))))-((int)((((int)(cs_server)) |((int)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))*((int)((((double)(cl->state)) *((double)(cl->state)))))-((long)((((double)(cl->state)) *((double)(cl->state)))))) + 42 +((int)((((int)(((long)((((double)(cl->state)) -((double)(cl->state)))))*((short)((((int)(cs_server)) |((int)(cs_server))))))) >>((int)(((long)((((double)(cl->state)) -((double)(cl->state))))))))))*((short)((((int)(cs_server + 42 -((long)((((int)(cs_server)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cl->state)))))-((long)((((int)(cs_server)) &((int)(cs_server)))))*((short)((((double)(cl->state)) *((double)(cl->state)))))+((long)((((double)(cl->state)) -((double)(cl->state)))))*((short)((((int)(cs_server)) |((int)(cs_server)))))-((int)((((int)(cs_server)) |((int)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))*((int)((((double)(cl->state)) *((double)(cl->state))))))) <<((int)(cs_server + 42 -((long)((((int)(cs_server)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cl->state)))))-((long)((((int)(cs_server)) &((int)(cs_server)))))*((short)((((double)(cl->state)) *((double)(cl->state)))))+((long)((((double)(cl->state)) -((double)(cl->state)))))*((short)((((int)(cs_server)) |((int)(cs_server))))))))))*((int)((((int)(((long)((((int)(cs_server)) &((int)(cs_server)))))*((short)((((double)(cl->state)) *((double)(cl->state))))))) &((int)(((int)((((int)(cs_server)) |((int)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server))))))))))-((int)((((int)(((int)((((int)(cs_server)) |((int)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server))))))) ^((int)(((long)((((double)(cl->state)) *((double)(cl->state))))))))))-((long)((((int)(((int)((((double)(cl->state)) *((double)(cl->state))))))) >>((int)(cs_server + 42 -((long)((((int)(cs_server)) |((int)(cs_server))))))))))-((int)((((int)(((int)((((int)(cs_server)) |((int)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))*((int)((((double)(cl->state)) *((double)(cl->state))))))) <<((int)(((int)((((int)(cs_server)) |((int)(cs_server)))))*((long)((((int)(cl->state)) ^((int)(cs_server)))))*((int)((((double)(cl->state)) *((double)(cl->state))))))))))+((short)((((int)(cs_server + 42 -((long)((((int)(cs_server)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cl->state)))))-((long)((((int)(cs_server)) &((int)(cs_server)))))*((short)((((double)(cl->state)) *((double)(cl->state))))))) ^((int)(((int)((((int)(cs_server)) |((int)(cs_server))))))))))))
                return cl->ping;
        ;
        ;
        
int loop_break_1844 = (0);
for (frame = cl->frames, i = (134217728) + 42 *((int)((((int)((134217728))) ^((int)(i)))))-((short)((((double)(i)) +((double)(i)))))+((int)((((int)((134217728))) >>((int)((134217728)))))) + 42 *((int)((((int)(42)) &((int)(42 *((int)((((int)((134217728))) ^((int)(i))))))))))+((long)((((int)(((int)((((int)((134217728))) ^((int)(i))))))) <<((int)((134217728) + 42 *((int)((((int)((134217728))) ^((int)(i))))))))))*((short)((((int)((134217728) + 42 *((int)((((int)((134217728))) ^((int)(i)))))-((short)((((double)(i)) +((double)(i)))))+((int)((((int)((134217728))) >>((int)((134217728)))))))) ^((int)(((short)((((double)(i)) +((double)(i))))))))))-((short)((((int)(42)) %((int)(((short)((((double)(i)) +((double)(i))))))))))*((int)((((int)((134217728) + 42 *((int)((((int)((134217728))) ^((int)(i)))))-((short)((((double)(i)) +((double)(i)))))+((int)((((int)((134217728))) >>((int)((134217728)))))))) %((int)(42))))); i < (66); i++, frame++) {
                
loop_break_1844++;
if(((int)((int)loop_break_1844<=(3) + 42 +((long)((((double)((3))) -((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) &((int)((3))))))) + 42 *((long)((((double)(((short)((((int)(loop_break_1844)) &((int)((3)))))))) -((double)((3) + 42 +((long)((((double)((3))) -((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) &((int)((3)))))))))))+((short)((((double)((int)loop_break_1844)) *((double)(((short)((((int)(loop_break_1844)) &((int)((3)))))))))))-((long)((((double)((3) + 42 +((long)((((double)((3))) -((double)(loop_break_1844))))))) -((double)((3) + 42)))))*((long)((((double)(((long)((((double)((3))) -((double)(loop_break_1844))))))) +((double)((3) + 42 +((long)((((double)((3))) -((double)(loop_break_1844)))))))))))){
continue;
}

if (0) {
                        ;
                        count++;
                }
        }
        if (!count)
                return (-10000);
        ;

        return ping * (-1001);
}

int main(void)
{
   client_t cl;

   memset(&cl, (0), sizeof(cl));

   
;
;
;

   if (0)
    { abort (); }

   return (17179869184);
}
/* ProgramSourceLLVM */
