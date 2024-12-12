/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[(36)];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = (0x04);
  double* deletedEntry = (9);
  
int while_condition_1360 = (9);

int loop_break_1391 = 0;

int while_condition_1459 = while_condition_1360;
while (while_condition_1459) {
    
loop_break_1391++;
if(((int)loop_break_1391<=45 + 42 *((short)((((double)(loop_break_1391)) +((double)(45)))))-((short)((((int)(loop_break_1391)) %((int)(loop_break_1391)))))*((long)((((double)(45)) +((double)(loop_break_1391)))))-((long)((((int)(loop_break_1391)) %((int)(45)))))-((short)((((double)(loop_break_1391)) *((double)(loop_break_1391))))))){
break;
}

double* entry = table + i;

    if (((int)*entry == *key + 42 *((short)((((int)(*key)) |((int)(*key)))))*((long)((((int)(*key)) %((int)(*entry)))))-((long)((((int)(*key)) &((int)(*key)))))-((int)((((int)(*key)) <<((int)(*entry)))))*((int)((((int)(*key)) <<((int)(*entry)))))*((int)((((int)(*key)) ^((int)(*entry)))))*((int)((((int)(*key)) >>((int)(*entry)))))+((short)((((int)(*entry)) >>((int)(*entry)))))-((long)((((int)(*key)) ^((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*key)))))))
    { break; }

    union _D_rep _D_inf = {{ (0), (0), (0xCFAD), 0x7ff0 }};
    if ((0xE4))
    { abort (); }

    union _D_rep _D_inf2 = {{ (64), (16384), (0), 0x7ff0 }};
    if ((0))
      ;

    i++;
  
break;

break;
}
  if (deletedEntry)
    ;
  return (0);
}

int main ()
{
  union _D_rep infinit = {{ (0), (0xEF), (0xD97A4), 0x7ff0 }};
  double table[(0xC)] = { infinit.val, (23) };
  double key = (23);
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
