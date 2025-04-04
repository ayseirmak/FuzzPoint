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
        client_frame_t frames[(96)];
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
        for (frame = cl->frames, i = (32) + (58) *((short)((((int)(i)) ^((int)(i)))))-((int)((((int)((3))) <<((int)((0xD9D))))))*((short)((((double)((0x23))) -((double)((9223372036854775808)))))) + 42 -((long)((((double)((32))) -((double)(i)))))-((long)((((int)(i)) %((int)(i)))))+((int)((((int)((58))) >>((int)((32) + (58) *((short)((((int)(i)) ^((int)(i))))))))))-((int)((((int)(((int)((((int)((3))) <<((int)((0xD9D)))))))) %((int)(((int)((((int)((3))) <<((int)((0xD9D))))))))))) + 42 +((long)((((int)((32) + (58) *((short)((((int)(i)) ^((int)(i)))))-((int)((((int)((3))) <<((int)((0xD9D))))))*((short)((((double)((0x23))) -((double)((9223372036854775808)))))) + 42 -((long)((((double)((32))) -((double)(i)))))-((long)((((int)(i)) %((int)(i)))))+((int)((((int)((58))) >>((int)((32) + (58) *((short)((((int)(i)) ^((int)(i))))))))))-((int)((((int)(((int)((((int)((3))) <<((int)((0xD9D)))))))) %((int)(((int)((((int)((3))) <<((int)((0xD9D))))))))))))) ^((int)((32) + (58) *((short)((((int)(i)) ^((int)(i)))))-((int)((((int)((3))) <<((int)((0xD9D))))))*((short)((((double)((0x23))) -((double)((9223372036854775808)))))) + 42 -((long)((((double)((32))) -((double)(i)))))-((long)((((int)(i)) %((int)(i)))))+((int)((((int)((58))) >>((int)((32) + (58) *((short)((((int)(i)) ^((int)(i))))))))))-((int)((((int)(((int)((((int)((3))) <<((int)((0xD9D)))))))) %((int)(((int)((((int)((3))) <<((int)((0xD9D))))))))))))))))*((int)((((int)((32) + (58) *((short)((((int)(i)) ^((int)(i)))))-((int)((((int)((3))) <<((int)((0xD9D))))))*((short)((((double)((0x23))) -((double)((9223372036854775808)))))) + 42 -((long)((((double)((32))) -((double)(i)))))-((long)((((int)(i)) %((int)(i)))))+((int)((((int)((58))) >>((int)((32) + (58) *((short)((((int)(i)) ^((int)(i))))))))))-((int)((((int)(((int)((((int)((3))) <<((int)((0xD9D)))))))) %((int)(((int)((((int)((3))) <<((int)((0xD9D))))))))))))) |((int)(i)))))-((long)((((double)(i)) +((double)(i)))))*((long)((((int)(i)) ^((int)((32) + (58) *((short)((((int)(i)) ^((int)(i)))))-((int)((((int)((3))) <<((int)((0xD9D))))))*((short)((((double)((0x23))) -((double)((9223372036854775808)))))) + 42 -((long)((((double)((32))) -((double)(i)))))-((long)((((int)(i)) %((int)(i)))))+((int)((((int)((58))) >>((int)((32) + (58) *((short)((((int)(i)) ^((int)(i))))))))))-((int)((((int)(((int)((((int)((3))) <<((int)((0xD9D)))))))) %((int)(((int)((((int)((3))) <<((int)((0xD9D))))))))))))))))-((int)((((int)((32) + (58) *((short)((((int)(i)) ^((int)(i)))))-((int)((((int)((3))) <<((int)((0xD9D))))))*((short)((((double)((0x23))) -((double)((9223372036854775808)))))) + 42 -((long)((((double)((32))) -((double)(i)))))-((long)((((int)(i)) %((int)(i)))))+((int)((((int)((58))) >>((int)((32) + (58) *((short)((((int)(i)) ^((int)(i))))))))))-((int)((((int)(((int)((((int)((3))) <<((int)((0xD9D)))))))) %((int)(((int)((((int)((3))) <<((int)((0xD9D))))))))))))) >>((int)((32) + (58) *((short)((((int)(i)) ^((int)(i)))))-((int)((((int)((3))) <<((int)((0xD9D))))))*((short)((((double)((0x23))) -((double)((9223372036854775808)))))) + 42 -((long)((((double)((32))) -((double)(i)))))-((long)((((int)(i)) %((int)(i)))))+((int)((((int)((58))) >>((int)((32) + (58) *((short)((((int)(i)) ^((int)(i))))))))))-((int)((((int)(((int)((((int)((3))) <<((int)((0xD9D)))))))) %((int)(((int)((((int)((3))) <<((int)((0xD9D)))))))))))))))); i < (0x0FEF58); i++, frame++) {
                if (0) {
                        ;
                        count++;
                }
        }
        if (0)
                return (-10000);
        
;
;
;

        return ping * (0xFFA92D8);
}

int main(void)
{
   client_t cl;

   memset(&cl, (35184372088832), sizeof(cl));

   ;

   if (0)
    { abort (); }

   return (0);
}
/* ProgramSourceLLVM */
