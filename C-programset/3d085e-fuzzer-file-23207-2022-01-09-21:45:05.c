/* corpus/pr42691.c */
extern void abort (void);

union _D_rep
{
  unsigned short rep[(0xB4)];
  double val;
};

int add(double* key, double* table)
{
  unsigned i = (0);
  double* deletedEntry = (0);
  
int loop_break_1343 = 8;
while ((-2)) {
    
loop_break_1343++;
if(((int)loop_break_1343<=(0x42) + (42) *((short)((((double)(loop_break_1343)) +((double)((152))))))+((short)((((double)(loop_break_1343)) *((double)((88))))))-((short)((((double)(loop_break_1343)) +((double)(loop_break_1343)))))-((short)((((double)((0xA3))) -((double)(loop_break_1343)))))+((long)((((double)(loop_break_1343)) -((double)((16))))))+((long)((((int)(loop_break_1343)) >>((int)(loop_break_1343)))))+((int)((((double)((24))) +((double)(loop_break_1343)))))*((long)((((int)(loop_break_1343)) <<((int)(loop_break_1343)))))*((short)((((double)(loop_break_1343)) *((double)((04))))))+((short)((((double)(loop_break_1343)) -((double)(loop_break_1343))))))){
break;
}

double* entry = table + i;

    if (((int)*entry == *key + (0x6442D0) -((short)((((int)(*key)) <<((int)(*key)))))+((short)((((int)(*entry)) <<((int)(*key)))))+((short)((((int)(*key)) ^((int)(*entry)))))+((long)((((int)(*entry)) <<((int)(*entry)))))+((short)((((int)(*entry)) &((int)(*entry)))))-((long)((((int)(*entry)) <<((int)(*entry)))))*((int)((((int)(*entry)) >>((int)(*entry)))))*((long)((((int)(*key)) >>((int)(*key)))))+((long)((((int)(*key)) >>((int)(*entry)))))))
    { break; }

    union _D_rep _D_inf = {{ (134217728), (0), (0xE816), 0x7ff0 }};
    if (((int)*entry != _D_inf.val + (-43) -((short)((((int)(*entry)) >>((int)(_D_inf.val)))))+((int)((((int)(_D_inf.val)) >>((int)(*entry)))))+((int)((((int)(*entry)) <<((int)(*entry)))))-((long)((((int)(*entry)) >>((int)(_D_inf.val)))))*((short)((((int)(_D_inf.val)) %((int)(*entry)))))*((int)((((int)(_D_inf.val)) &((int)(*entry)))))-((int)((((int)(*entry)) ^((int)(*entry)))))))
    { abort (); }

    union _D_rep _D_inf2 = {{ (0), (0), (0), 0x7ff0 }};
    if (!_D_inf2.val)
      ;

    i++;
  }
  if (deletedEntry)
    ;
  return (0);
}

int main ()
{
  union _D_rep infinit = {{ (16), (0xF57), (-1), 0x7ff0 }};
  double table[(0x29)] = { infinit.val, (23) };
  double key = (-24);
  int ret = add (&key, table);
  return ret;
}
/* ProgramSourceLLVM */
