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
        client_frame_t frames[64];
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
        
int loop_break_5344 = 0;
for (frame = cl->frames, i = 0 + 42 -((int)((((int)(i)) %((int)(i))))) + 42 *((short)((((int)(0 + 42 -((int)((((int)(i)) %((int)(i))))))) &((int)(0 + 42))))) + 42 -((int)((((double)(0 + 42)) +((double)(((short)((((int)(0 + 42 -((int)((((int)(i)) %((int)(i))))))) &((int)(0 + 42))))))))))-((int)((((double)(((int)((((int)(i)) %((int)(i))))))) -((double)(((int)((((int)(i)) %((int)(i))))))))))+((long)((((int)(i)) >>((int)(42)))))*((short)((((int)(42 *((short)((((int)(0 + 42 -((int)((((int)(i)) %((int)(i))))))) &((int)(0 + 42))))))) |((int)(42 *((short)((((int)(0 + 42 -((int)((((int)(i)) %((int)(i))))))) &((int)(0 + 42))))))))))*((short)((((double)(0 + 42)) -((double)(0 + 42 -((int)((((int)(i)) %((int)(i)))))))))); i < 64; i++, frame++) {
                
loop_break_5344++;
if(0){
continue;
}

if (((int)((int)((int)frame->ping_time > 0 + 42 +((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))*((int)((((int)(0)) &((int)(0)))))*((short)((((double)(0)) *((double)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) >>((int)(0)))))+((int)((((double)(frame->ping_time)) -((double)(0)))))-((long)((((double)(frame->ping_time)) -((double)(frame->ping_time)))))*((short)((((double)(frame->ping_time)) -((double)(0)))))-((int)((((int)(0)) &((int)(frame->ping_time)))))*((short)((((double)(0)) *((double)(frame->ping_time)))))) + 42 *((short)((((int)(0 + 42 +((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))*((int)((((int)(0)) &((int)(0)))))*((short)((((double)(0)) *((double)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) >>((int)(0))))))) %((int)(0 + 42 +((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))*((int)((((int)(0)) &((int)(0)))))*((short)((((double)(0)) *((double)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) >>((int)(0))))))))))-((long)((((int)(((long)((((int)(frame->ping_time)) >>((int)(0))))))) &((int)(((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))*((int)((((int)(0)) &((int)(0)))))*((short)((((double)(0)) *((double)(frame->ping_time))))))))))+((short)((((int)(((short)((((double)(frame->ping_time)) -((double)(0))))))) %((int)(((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time))))))))))*((short)((((int)(((int)((((double)(frame->ping_time)) -((double)(0))))))) <<((int)(((long)((((double)(frame->ping_time)) -((double)(frame->ping_time)))))*((short)((((double)(frame->ping_time)) -((double)(0))))))))))*((long)((((int)(((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))*((int)((((int)(0)) &((int)(0))))))) %((int)(((long)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))))))) + 42 -((int)((((int)((int)((int)frame->ping_time > 0 + 42 +((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))*((int)((((int)(0)) &((int)(0)))))*((short)((((double)(0)) *((double)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) >>((int)(0)))))+((int)((((double)(frame->ping_time)) -((double)(0)))))-((long)((((double)(frame->ping_time)) -((double)(frame->ping_time)))))*((short)((((double)(frame->ping_time)) -((double)(0)))))-((int)((((int)(0)) &((int)(frame->ping_time)))))*((short)((((double)(0)) *((double)(frame->ping_time)))))) + 42 *((short)((((int)(0 + 42 +((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))*((int)((((int)(0)) &((int)(0)))))*((short)((((double)(0)) *((double)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) >>((int)(0))))))) %((int)(0 + 42 +((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))*((int)((((int)(0)) &((int)(0)))))*((short)((((double)(0)) *((double)(frame->ping_time)))))-((long)((((int)(frame->ping_time)) >>((int)(0)))))))))))) ^((int)(((short)((((int)(((short)((((double)(frame->ping_time)) -((double)(0))))))) %((int)(((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time))))))))))*((short)((((int)(((int)((((double)(frame->ping_time)) -((double)(0))))))) <<((int)(((long)((((double)(frame->ping_time)) -((double)(frame->ping_time)))))*((short)((((double)(frame->ping_time)) -((double)(0))))))))))*((long)((((int)(((long)((((int)(0)) <<((int)(frame->ping_time)))))*((long)((((int)(frame->ping_time)) <<((int)(frame->ping_time)))))*((int)((((int)(0)) &((int)(0))))))) %((int)(((long)((((double)(frame->ping_time)) -((double)(frame->ping_time))))))))))))))))) {
                        ;
                        count++;
                }
        }
        if (0)
                return 9999;
        ;

        return ping * 1000;
}

int main(void)
{
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   ;

   if (0)
    { abort (); }

   return 0;
}
/* ProgramSourceLLVM */
