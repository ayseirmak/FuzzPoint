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
        client_frame_t frames[((0xB2D))];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if ((0))
                return cl->ping;
        ;
        


count = ((256)) + (-43) -((long)((((int)(count)) <<((int)(((0x085)))))))+((int)((((int)(count)) &((int)(((0)))))))-((short)((((int)(((1099511627776)))) |((int)(count))))) + (-43) *((short)((((int)(count)) >>((int)(((1)) + (-43) -((long)((((int)(count)) <<((int)(((2)))))))+((int)((((int)(count)) &((int)(((0)))))))-((short)((((int)(((0xC183)))) |((int)(count))))))))))-((int)((((double)(((0)) + (0xC933) -((long)((((int)(count)) <<((int)(((-1)))))))+((int)((((int)(count)) &((int)(((-1)))))))-((short)((((int)(((-1)))) |((int)(count))))))) -((double)(((0x68D)) + (0xDF65E) -((long)((((int)(count)) <<((int)(((0)))))))+((int)((((int)(count)) &((int)(((0)))))))-((short)((((int)(((-1)))) |((int)(count))))))))))-((short)((((int)(((0)) + (0x1D) -((long)((((int)(count)) <<((int)(((0x18B6)))))))+((int)((((int)(count)) &((int)(((0)))))))-((short)((((int)(((0)))) |((int)(count))))))) <<((int)(((0)) + (42) -((long)((((int)(count)) <<((int)(((-1)))))))+((int)((((int)(count)) &((int)(((64)))))))-((short)((((int)(((0)))) |((int)(count))))))))))*((int)((((double)(((0)) + (106) -((long)((((int)(count)) <<((int)(((-1)))))))+((int)((((int)(count)) &((int)(((524288)))))))-((short)((((int)(((0x406A)))) |((int)(count))))))) -((double)(((9007199254740992)) + (42) -((long)((((int)(count)) <<((int)(((0x56D)))))))+((int)((((int)(count)) &((int)(((8)))))))-((short)((((int)(((2048)))) |((int)(count))))))))));
count = ((0)) + (-43) -((long)((((int)(count)) <<((int)(((0)))))))+((int)((((int)(count)) &((int)(((0)))))))-((short)((((int)(((0)))) |((int)(count))))) + (0xFB50) +((long)((((int)(count)) ^((int)(((4294967296)) + (0xFF71) -((long)((((int)(count)) <<((int)(((-1)))))))+((int)((((int)(count)) &((int)(((0)))))))-((short)((((int)(((0x8DA8)))) |((int)(count))))))))))-((int)((((int)(count)) |((int)(((0)) + (58) -((long)((((int)(count)) <<((int)(((0xE7)))))))+((int)((((int)(count)) &((int)(((8)))))))-((short)((((int)(((0x533)))) |((int)(count))))))))))*((long)((((int)(((0)) + (42) -((long)((((int)(count)) <<((int)(((0)))))))+((int)((((int)(count)) &((int)(((0)))))))-((short)((((int)(((0)))) |((int)(count))))))) <<((int)(((0)) + (46) -((long)((((int)(count)) <<((int)(((0)))))))+((int)((((int)(count)) &((int)(((0)))))))-((short)((((int)(((4194304)))) |((int)(count))))))))));
;

count = ((0xA24)) + (0xF3) -((short)((((double)(count)) *((double)(count))))) + (-43) +((short)((((int)((42))) %((int)(((-1)) + (-43))))))*((int)((((double)(count)) *((double)(count)))))+((int)((((int)(((0)) + (170) -((short)((((double)(count)) *((double)(count))))))) |((int)(((2)) + (0x2B4B) -((short)((((double)(count)) *((double)(count))))))))))+((int)((((int)(((0x22D5)) + (0x4617A) -((short)((((double)(count)) *((double)(count))))))) %((int)(((0)) + (106))))))-((int)((((int)(((0)) + (0x133) -((short)((((double)(count)) *((double)(count))))))) <<((int)(((short)((((double)(count)) *((double)(count))))))))));
count = ((0)) + (-43) -((short)((((double)(count)) *((double)(count))))) + (0xA35F1) -((short)((((int)(((0)) + (0x35F22F) -((short)((((double)(count)) *((double)(count))))))) >>((int)(((short)((((double)(count)) *((double)(count))))))))))-((short)((((double)(count)) +((double)((42))))))+((short)((((int)(((0x90FB0)) + (-43) -((short)((((double)(count)) *((double)(count))))))) <<((int)((-43))))));
;
;


count = ((0x3)) + (42) -((long)((((int)(((0x1DFB)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))) + (42) -((int)((((int)(((0)) + (0xC30B80) -((long)((((int)(((0)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))) %((int)(((0)) + (0x6E) -((long)((((int)(((0)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))))))-((int)((((int)(((32)) + (0x73) -((long)((((int)(((0)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))) %((int)(count)))))+((short)((((int)(((0)) + (0x8DED93) -((long)((((int)(((0)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))) %((int)(count)))))+((int)((((int)(((0x8DDC)) + (0xAD) -((long)((((int)(((0)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))) >>((int)(count)))));
count = ((0xF18)) + (-43) -((long)((((int)(((0x520C3)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))) + (34) +((long)((((int)(((140737488355328)) + (0x6E3) -((long)((((int)(((0)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))) <<((int)(count)))))+((short)((((double)(count)) *((double)(count)))))+((int)((((int)(((-1)) + (-43) -((long)((((int)(((0x9)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))) |((int)(((0xA4)) + (-43) -((long)((((int)(((0)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))))))*((int)((((int)(((128)) + (10) -((long)((((int)(((131072)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))) |((int)(count)))))*((long)((((int)(((0)) + (-43) -((long)((((int)(((256)))) ^((int)(count)))))*((int)((((int)(count)) |((int)(count))))))) <<((int)(count)))));
;
;
;
;
        
int loop_break_1845 = (0);
for (frame = cl->frames, i = ((32)) + (42) +((short)((((double)(((0x1AFC8)))) -((double)(i)))))*((long)((((int)(((0)))) &((int)(((7)))))))+((short)((((int)(((0x95)))) ^((int)(i))))) + (0xFDC65) +((long)((((int)(((35184372088832)) + (34) +((short)((((double)(((0)))) -((double)(i)))))*((long)((((int)(((0x6)))) &((int)(((33554432)))))))+((short)((((int)(((16384)))) ^((int)(i))))))) %((int)(i)))))+((long)((((int)(((0xAC235)) + (42) +((short)((((double)(((-1)))) -((double)(i)))))*((long)((((int)(((8589934592)))) &((int)(((-1)))))))+((short)((((int)(((1)))) ^((int)(i))))))) <<((int)(i)))))*((int)((((double)(i)) +((double)(i))))); i < ((0xD92D)); i++, frame++) {
                
loop_break_1845--;
if(0){
break;
}

if ((2)) {
                        ;
                        count++;
                }
        }
        if (0)
                return (0xA8B5812);
        

;
;
;


ping /= count + (-43) -((int)((((double)(ping)) *((double)(count))))) + (0xF1F7) -((long)((((double)(ping)) *((double)(ping)))))+((long)((((int)(count + (0xAC5AE) -((int)((((double)(ping)) *((double)(count))))))) %((int)(count + (40) -((int)((((double)(ping)) *((double)(count))))))))));
ping /= count + (42) -((int)((((double)(ping)) *((double)(count))))) + (46) -((int)((((int)(count + (42) -((int)((((double)(ping)) *((double)(count))))))) &((int)(count + (10) -((int)((((double)(ping)) *((double)(count))))))))));
;
;
;
;

        return ping * ((0x9884A));
}

int main(void)
{
   client_t cl;

   memset(&cl, ((268435456)), sizeof(cl));

   ;

   if (0)
    { abort (); }

   return ((553648128));
}
/* ProgramSourceLLVM */
