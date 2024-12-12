/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[4];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = 0;
  double* deletedEntry = 0;
  
int while_condition_1360 = 1;

int loop_break_2116 = 0;
while (while_condition_1360) {
    
loop_break_2116++;
if(((int)loop_break_2116<=37 + 42 +((short)((((double)(loop_break_2116)) *((double)(37)))))*((int)((((double)(loop_break_2116)) +((double)(37)))))-((short)((((double)(37)) +((double)(loop_break_2116)))))+((int)((((double)(37)) -((double)(loop_break_2116)))))*((short)((((double)(37)) -((double)(loop_break_2116)))))+((short)((((double)(loop_break_2116)) -((double)(loop_break_2116))))))){
break;
}

double* entry = table + i;

    if (((int)((int)*entry == *key + 42 *((short)((((int)(*entry)) %((int)(*entry)))))-((int)((((int)(*key)) |((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*entry)))))+((short)((((int)(*key)) >>((int)(*entry)))))-((short)((((int)(*key)) ^((int)(*entry)))))*((long)((((int)(*entry)) ^((int)(*key)))))) + 42 +((int)((((int)(((int)((((int)(*key)) |((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*entry))))))) &((int)(*key + 42 *((short)((((int)(*entry)) %((int)(*entry)))))-((int)((((int)(*key)) |((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*entry)))))+((short)((((int)(*key)) >>((int)(*entry)))))-((short)((((int)(*key)) ^((int)(*entry)))))*((long)((((int)(*entry)) ^((int)(*key))))))))))+((int)((((int)(*key + 42 *((short)((((int)(*entry)) %((int)(*entry)))))-((int)((((int)(*key)) |((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*entry))))))) |((int)(((int)((((int)(*key)) |((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*entry))))))))))+((int)((((int)((int)*entry)) <<((int)(42 *((short)((((int)(*entry)) %((int)(*entry))))))))))-((long)((((int)(*key + 42 *((short)((((int)(*entry)) %((int)(*entry))))))) <<((int)(*key + 42 *((short)((((int)(*entry)) %((int)(*entry)))))-((int)((((int)(*key)) |((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*entry)))))+((short)((((int)(*key)) >>((int)(*entry))))))))))*((int)((((int)(((int)((((int)(*key)) |((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*entry))))))) &((int)(*key)))))-((int)((((int)(42 *((short)((((int)(*entry)) %((int)(*entry))))))) >>((int)(*key)))))*((int)((((int)(*key + 42 *((short)((((int)(*entry)) %((int)(*entry)))))-((int)((((int)(*key)) |((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*entry))))))) &((int)(*key)))))))
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
      ;

    i++;
  
break;
}
  if (deletedEntry)
    ;
  return 0;
}

int main ()
{
  union _D_rep infinit = {{ 0, 0, 0, 0x7ff0 }};
  double table[2] = { infinit.val, 23 };
  double key = 23;
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
