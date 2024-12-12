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

        if (((int)((int)cl->state == cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cs_server)))))+((int)((((double)(cs_server)) *((double)(cs_server)))))+((short)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((double)(cs_server)) +((double)(cl->state)))))+((short)((((int)(cs_server)) &((int)(cl->state)))))*((long)((((double)(cl->state)) -((double)(cl->state)))))+((short)((((double)(cl->state)) +((double)(cs_server)))))+((int)((((double)(cl->state)) *((double)(cs_server)))))+((long)((((int)(cl->state)) ^((int)(cs_server)))))) + 42 *((int)((((double)(((short)((((double)(cl->state)) -((double)(cs_server))))))) *((double)(((short)((((int)(cs_server)) &((int)(cl->state))))))))))-((int)((((int)(cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cs_server)))))+((int)((((double)(cs_server)) *((double)(cs_server)))))+((short)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((double)(cs_server)) +((double)(cl->state)))))+((short)((((int)(cs_server)) &((int)(cl->state)))))*((long)((((double)(cl->state)) -((double)(cl->state)))))+((short)((((double)(cl->state)) +((double)(cs_server)))))+((int)((((double)(cl->state)) *((double)(cs_server)))))+((long)((((int)(cl->state)) ^((int)(cs_server))))))) %((int)(((short)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((double)(cs_server)) +((double)(cl->state))))))))))*((int)((((double)(((long)((((int)(cl->state)) ^((int)(cs_server))))))) +((double)(cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server))))))))))-((short)((((int)(cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server))))))) <<((int)(cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cs_server)))))+((int)((((double)(cs_server)) *((double)(cs_server)))))+((short)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((double)(cs_server)) +((double)(cl->state)))))+((short)((((int)(cs_server)) &((int)(cl->state)))))*((long)((((double)(cl->state)) -((double)(cl->state)))))+((short)((((double)(cl->state)) +((double)(cs_server))))))))))*((short)((((double)(((long)((((int)(cl->state)) ^((int)(cs_server))))))) -((double)(((long)((((int)(cl->state)) |((int)(cs_server))))))))))+((short)((((int)(cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cs_server)))))+((int)((((double)(cs_server)) *((double)(cs_server)))))+((short)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((double)(cs_server)) +((double)(cl->state)))))+((short)((((int)(cs_server)) &((int)(cl->state)))))*((long)((((double)(cl->state)) -((double)(cl->state)))))+((short)((((double)(cl->state)) +((double)(cs_server)))))+((int)((((double)(cl->state)) *((double)(cs_server)))))+((long)((((int)(cl->state)) ^((int)(cs_server))))))) |((int)(cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cs_server)))))+((int)((((double)(cs_server)) *((double)(cs_server)))))+((short)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((double)(cs_server)) +((double)(cl->state)))))+((short)((((int)(cs_server)) &((int)(cl->state)))))*((long)((((double)(cl->state)) -((double)(cl->state)))))+((short)((((double)(cl->state)) +((double)(cs_server)))))+((int)((((double)(cl->state)) *((double)(cs_server)))))+((long)((((int)(cl->state)) ^((int)(cs_server))))))))))-((int)((((int)(cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cs_server))))))) <<((int)(((short)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((double)(cs_server)) +((double)(cl->state))))))))))*((int)((((int)(cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server)))))+((short)((((double)(cl->state)) -((double)(cs_server)))))+((int)((((double)(cs_server)) *((double)(cs_server)))))+((short)((((double)(cs_server)) +((double)(cl->state)))))*((short)((((double)(cs_server)) +((double)(cl->state)))))+((short)((((int)(cs_server)) &((int)(cl->state)))))*((long)((((double)(cl->state)) -((double)(cl->state))))))) %((int)(cs_server + 42 -((long)((((int)(cl->state)) |((int)(cs_server))))))))))))
                return cl->ping;
        ;
        


count = (0) + 42 -((long)((((int)(count)) <<((int)((0))))))+((int)((((int)(count)) &((int)((0))))))-((short)((((int)((0))) |((int)(count))))) + 42 *((int)((((int)((0) + 42 -((long)((((int)(count)) <<((int)((0))))))+((int)((((int)(count)) &((int)((0))))))-((short)((((int)((0))) |((int)(count))))))) |((int)((0) + 42 -((long)((((int)(count)) <<((int)((0))))))+((int)((((int)(count)) &((int)((0))))))-((short)((((int)((0))) |((int)(count))))))))));
count = (0) + 42 -((long)((((int)(count)) <<((int)((0))))))+((int)((((int)(count)) &((int)((0))))))-((short)((((int)((0))) |((int)(count))))) + 42 +((short)((((int)((0) + 42 -((long)((((int)(count)) <<((int)((0))))))+((int)((((int)(count)) &((int)((0))))))-((short)((((int)((0))) |((int)(count))))))) >>((int)((0) + 42 -((long)((((int)(count)) <<((int)((0))))))+((int)((((int)(count)) &((int)((0))))))-((short)((((int)((0))) |((int)(count))))))))))+((long)((((double)(count)) +((double)((0) + 42 -((long)((((int)(count)) <<((int)((0))))))+((int)((((int)(count)) &((int)((0))))))-((short)((((int)((0))) |((int)(count))))))))));
;

count = (0) + 42 -((short)((((double)(count)) *((double)(count))))) + 42 +((short)((((int)((0))) ^((int)(count)))))-((short)((((int)(42)) %((int)((0) + 42 -((short)((((double)(count)) *((double)(count))))))))));
count = (0) + 42 -((short)((((double)(count)) *((double)(count))))) + 42 -((int)((((int)((0) + 42)) &((int)(count)))))*((int)((((int)(count)) %((int)(count)))))-((int)((((int)((0) + 42)) &((int)(((short)((((double)(count)) *((double)(count))))))))))-((int)((((int)(count)) ^((int)(((short)((((double)(count)) *((double)(count))))))))));
;
;


count = (0) + 42 -((long)((((int)((0))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))) + 42 +((long)((((int)(count)) &((int)((0) + 42 -((long)((((int)((0))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))))));
count = (0) + 42 -((long)((((int)((0))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))) + 42 +((int)((((double)(count)) *((double)(count)))))*((long)((((int)(count)) |((int)((0) + 42 -((long)((((int)((0))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))))))+((long)((((int)((0) + 42 -((long)((((int)((0))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))) |((int)((0) + 42 -((long)((((int)((0))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))))))+((int)((((double)(count)) -((double)(count)))));
;
;
;
;
        
int loop_break_1845 = 0;
for (frame = cl->frames, i = (0) + 42 +((short)((((double)((0))) -((double)(i)))))*((long)((((int)((0))) &((int)((0))))))+((short)((((int)((0))) ^((int)(i))))) + 42 -((long)((((int)((0) + 42 +((short)((((double)((0))) -((double)(i)))))*((long)((((int)((0))) &((int)((0))))))+((short)((((int)((0))) ^((int)(i))))))) >>((int)((0) + 42 +((short)((((double)((0))) -((double)(i)))))*((long)((((int)((0))) &((int)((0))))))+((short)((((int)((0))) ^((int)(i)))))))))); i < (64); i++, frame++) {
                
loop_break_1845--;
if(0){
break;
}

if (0) {
                        ;
                        count++;
                }
        }
        if (!count)
                return (0xA8B5812);
        

;
;
;


ping /= count + 42 -((int)((((double)(ping)) *((double)(count))))) + 42 *((long)((((int)(ping)) ^((int)(count + 42 -((int)((((double)(ping)) *((double)(count))))))))))-((int)((((int)(count + 42 -((int)((((double)(ping)) *((double)(count))))))) ^((int)(count + 42 -((int)((((double)(ping)) *((double)(count))))))))))+((int)((((int)(count + 42 -((int)((((double)(ping)) *((double)(count))))))) %((int)(ping)))))*((short)((((int)(count + 42 -((int)((((double)(ping)) *((double)(count))))))) %((int)(count + 42 -((int)((((double)(ping)) *((double)(count))))))))));
ping /= count + 42 -((int)((((double)(ping)) *((double)(count))))) + 42 +((long)((((int)(count + 42 -((int)((((double)(ping)) *((double)(count))))))) <<((int)(ping)))))-((long)((((int)(ping)) >>((int)(count + 42 -((int)((((double)(ping)) *((double)(count))))))))))-((int)((((int)(count + 42 -((int)((((double)(ping)) *((double)(count))))))) |((int)(ping)))));
;
;
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
