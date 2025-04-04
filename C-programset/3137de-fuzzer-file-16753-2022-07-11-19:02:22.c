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
  
int loop_break_1360 = 0;
while (1) {
    
loop_break_1360++;
if(((int)loop_break_1360<=15 + 41 - ((int)(((double)(loop_break_1360)) - ((double)15))) * ((int)(((double)(loop_break_1360)) + ((double)15))) * ((short)(((int)15) << ((int)(loop_break_1360)))) + ((long)(((double)(loop_break_1360)) - ((double)15))) * ((short)(((int)15) << ((int)(loop_break_1360)))) - ((int)(((double)15) + ((double)(loop_break_1360)))) * ((int)(((int)(loop_break_1360)) % ((int)15))) - ((short)(((double)(loop_break_1360)) - ((double)15))) + ((int)(((int)15) | ((int)(loop_break_1360)))))){
break;
}

double* entry = table + i;

    if (((int)*entry == *key + 41 * ((short)(((int)(*entry)) ^ ((int)(*key)))) * ((long)(((int)(*entry)) << ((int)(*key)))) + ((int)(((int)(*entry)) & ((int)(*entry)))) - ((long)(((int)(*key)) << ((int)(*key)))) * ((long)(((int)(*key)) << ((int)(*key)))) + ((short)(((int)(*key)) & ((int)(*key))))))
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (((int)*entry != _D_inf.val + 41 + ((short)(((int)(*entry)) | ((int)(*entry)))) * ((int)(((int)(_D_inf.val)) << ((int)(_D_inf.val)))) + ((short)(((int)(_D_inf.val)) >> ((int)(_D_inf.val))))))
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (!_D_inf2.val)
      deletedEntry = entry;

    i++;
  }
  if (deletedEntry)
    *deletedEntry = 0.0;
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
