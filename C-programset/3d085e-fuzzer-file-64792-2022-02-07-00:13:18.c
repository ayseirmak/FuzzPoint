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
  
int loop_break_3426 = 0;
while (1) {
    
loop_break_3426++;
if(loop_break_3426<=24){
break;
}

double* entry = table + i;

    if (((int)*entry == *key + 42 -((int)((((int)(*entry)) &((int)(*entry)))))-((short)((((int)(*entry)) |((int)(*entry)))))-((short)((((int)(*key)) ^((int)(*key)))))*((long)((((int)(*entry)) >>((int)(*entry)))))*((short)((((int)(*entry)) ^((int)(*entry)))))*((short)((((int)(*key)) <<((int)(*entry)))))-((int)((((int)(*key)) <<((int)(*entry)))))*((short)((((int)(*entry)) >>((int)(*entry)))))-((int)((((int)(*key)) >>((int)(*key)))))))
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (((int)*entry != _D_inf.val + 42 *((int)((((int)(_D_inf.val)) >>((int)(*entry)))))-((int)((((int)(*entry)) ^((int)(_D_inf.val)))))+((long)((((double)(_D_inf.val)) +((double)(_D_inf.val)))))*((int)((((double)(_D_inf.val)) *((double)(_D_inf.val)))))*((long)((((int)(*entry)) <<((int)(*entry)))))+((int)((((int)(_D_inf.val)) >>((int)(_D_inf.val)))))-((long)((((double)(_D_inf.val)) +((double)(_D_inf.val)))))))
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (!_D_inf2.val)
      deletedEntry = entry;

    i++;
  }
  if (deletedEntry)
    *deletedEntry = 0.0 + 42 +((short)((((int)(*deletedEntry)) <<((int)(*deletedEntry)))))-((int)((((int)(0.0)) ^((int)(*deletedEntry)))));
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
