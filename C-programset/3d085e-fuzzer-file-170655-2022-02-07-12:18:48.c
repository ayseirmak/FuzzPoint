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
        client_frame_t frames[((67))];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if ((-1))
                return cl->ping;
        ;
        ;
        
int loop_break_1844 = (-9);
for (frame = cl->frames, i = ((64)) + (0x91) *((int)((((double)(((72)))) -((double)(((-65)))))))*((long)((((double)(i)) *((double)(((-65)))))))+((int)((((int)(i)) <<((int)(i))))); i < (-(65)); i++, frame++) {
                
loop_break_1844++;
if(((int)loop_break_1844<=(-(0)) + (-43) *((int)((((int)(loop_break_1844)) |((int)((-(5)))))))+((int)((((double)((-(4)))) -((double)(loop_break_1844)))))*((short)((((double)((-(12)))) -((double)((-(-5)))))))*((short)((((double)(loop_break_1844)) +((double)((-(68)))))))-((int)((((int)(loop_break_1844)) |((int)((-(5)))))))-((short)((((double)((-(20)))) +((double)((-(0x43CFE))))))))){
break;
}

if ((0x31)) {
                        ;
                        count++;
                }
        }
        if (!count)
                return (-(-10001));
        
ping /= count + (02) *((short)((((double)(count)) +((double)(ping)))))-((long)((((int)(ping)) ^((int)(ping)))))*((int)((((double)(count)) *((double)(ping)))));
ping /= count + (106) *((int)((((int)(ping)) |((int)(ping)))))*((short)((((double)(count)) *((double)(ping)))));
;

        return ping * ((972));
}

int main(void)
{
   client_t cl;

   memset(&cl, ((20)), sizeof(cl));

   ;

   if ((0))
    { abort (); }

   return ((4194304));
}
/* ProgramSourceLLVM */
