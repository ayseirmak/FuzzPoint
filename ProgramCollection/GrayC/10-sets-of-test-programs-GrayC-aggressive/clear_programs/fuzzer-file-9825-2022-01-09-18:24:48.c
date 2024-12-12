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
  
int loop_break_1343 = 0;
while (1) {
    
loop_break_1343++;
if(((int)loop_break_1343<=24 + 42 *((short)((((double)(loop_break_1343)) +((double)(24)))))+((short)((((double)(loop_break_1343)) *((double)(24)))))-((short)((((double)(loop_break_1343)) +((double)(loop_break_1343)))))-((short)((((double)(24)) -((double)(loop_break_1343)))))+((long)((((double)(loop_break_1343)) -((double)(24)))))+((long)((((int)(loop_break_1343)) >>((int)(loop_break_1343)))))+((int)((((double)(24)) +((double)(loop_break_1343)))))*((long)((((int)(loop_break_1343)) <<((int)(loop_break_1343)))))*((short)((((double)(loop_break_1343)) *((double)(24)))))+((short)((((double)(loop_break_1343)) -((double)(loop_break_1343))))))){
break;
}

double* entry = table + i;

    if (((int)*entry == *key + 42 -((short)((((int)(*key)) <<((int)(*key)))))+((short)((((int)(*entry)) <<((int)(*key)))))+((short)((((int)(*key)) ^((int)(*entry)))))+((long)((((int)(*entry)) <<((int)(*entry)))))+((short)((((int)(*entry)) &((int)(*entry)))))-((long)((((int)(*entry)) <<((int)(*entry)))))*((int)((((int)(*entry)) >>((int)(*entry)))))*((long)((((int)(*key)) >>((int)(*key)))))+((long)((((int)(*key)) >>((int)(*entry)))))))
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (((int)*entry != _D_inf.val + 42 -((short)((((int)(*entry)) >>((int)(_D_inf.val)))))+((int)((((int)(_D_inf.val)) >>((int)(*entry)))))+((int)((((int)(*entry)) <<((int)(*entry)))))-((long)((((int)(*entry)) >>((int)(_D_inf.val)))))*((short)((((int)(_D_inf.val)) %((int)(*entry)))))*((int)((((int)(_D_inf.val)) &((int)(*entry)))))-((int)((((int)(*entry)) ^((int)(*entry)))))))
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (!_D_inf2.val)
      ;

    i++;
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
