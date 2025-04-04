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

        if (0)
                return cl->ping;
        ;
        ;
        
int loop_break_1844 = (0);

int loop_break_3797 = 0;
for (frame = cl->frames, i = (134217728) + 42 *((int)((((int)((134217728))) ^((int)(i)))))-((short)((((double)(i)) +((double)(i)))))+((int)((((int)((134217728))) >>((int)((134217728)))))) + 42 +((long)((((int)(((short)((((double)(i)) +((double)(i))))))) |((int)(42 *((int)((((int)((134217728))) ^((int)(i))))))))))*((short)((((double)((134217728))) +((double)(((short)((((double)(i)) +((double)(i))))))))))*((short)((((int)(((int)((((int)((134217728))) ^((int)(i))))))) &((int)((134217728) + 42 *((int)((((int)((134217728))) ^((int)(i)))))-((short)((((double)(i)) +((double)(i))))))))))+((int)((((int)((134217728) + 42 *((int)((((int)((134217728))) ^((int)(i)))))-((short)((((double)(i)) +((double)(i)))))+((int)((((int)((134217728))) >>((int)((134217728)))))))) <<((int)(((short)((((double)(i)) +((double)(i))))))))))-((int)((((int)((134217728) + 42 *((int)((((int)((134217728))) ^((int)(i)))))-((short)((((double)(i)) +((double)(i))))))) |((int)(42))))); i < (66); i++, frame++) {
                

loop_break_3797++;
if(0){
break;
}

loop_break_1844++;
if(((int)((int)loop_break_1844<=(3) + 42 +((long)((((double)((3))) -((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) &((int)((3))))))) + 42 *((int)((((double)(((long)((((double)((3))) -((double)(loop_break_1844))))))) +((double)((3) + 42 +((long)((((double)((3))) -((double)(loop_break_1844))))))))))+((int)((((int)(((short)((((int)(loop_break_1844)) &((int)((3)))))))) |((int)((3) + 42)))))-((long)((((int)((3) + 42)) &((int)((3) + 42 +((long)((((double)((3))) -((double)(loop_break_1844))))))))))+((int)((((int)((3) + 42)) <<((int)((3) + 42 +((long)((((double)((3))) -((double)(loop_break_1844)))))+((short)((((int)(loop_break_1844)) &((int)((3)))))))))))*((long)((((int)((3) + 42)) &((int)(((short)((((int)(loop_break_1844)) &((int)((3)))))))))))+((long)((((double)((int)loop_break_1844)) *((double)(((long)((((double)((3))) -((double)(loop_break_1844)))))))))))){
continue;
}

if (0) {
                        ;
                        count++;
                }
        }
        if (0)
                return (-10000);
        ;

        return ping * (-1001);
}

int main(void)
{
   client_t cl;

   memset(&cl, (0), sizeof(cl));

   
cl.frames[(0)].ping_time = (5.5) + 42 +((long)((((int)((5.5))) >>((int)((5.5))))))*((short)((((int)(cl.frames[(0)].ping_time)) |((int)((5.5))))))+((long)((((int)((5.5))) &((int)(cl.frames[(0)].ping_time))))) + 42 *((short)((((int)(cl.frames[(0)].ping_time)) %((int)((5.5) + 42 +((long)((((int)((5.5))) >>((int)((5.5))))))*((short)((((int)(cl.frames[(0)].ping_time)) |((int)((5.5))))))+((long)((((int)((5.5))) &((int)(cl.frames[(0)].ping_time))))))))));
cl.frames[(0x5)].ping_time = (10.5) + 42 -((short)((((int)((10.5))) >>((int)(cl.frames[(0x5)].ping_time))))) + 42 +((long)((((int)(cl.frames[(0x5)].ping_time)) &((int)(cl.frames[(0x5)].ping_time)))))-((long)((((int)(cl.frames[(0x5)].ping_time)) |((int)((10.5) + 42 -((short)((((int)((10.5))) >>((int)(cl.frames[(0x5)].ping_time))))))))))+((long)((((int)(cl.frames[(0x5)].ping_time)) &((int)((10.5) + 42 -((short)((((int)((10.5))) >>((int)(cl.frames[(0x5)].ping_time))))))))));
;

   if (0)
    { abort (); }

   return (17179869184);
}
/* ProgramSourceLLVM */
