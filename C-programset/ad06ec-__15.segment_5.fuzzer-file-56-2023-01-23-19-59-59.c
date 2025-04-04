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

int while_condition_1363 = while_condition_1360;

int loop_break_3892 = 0;
while (while_condition_1363) {
    
loop_break_3892++;
if(loop_break_3892<=41){
break;
}

double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (((int)((int)*entry != _D_inf.val + 41 + ((long)((((int)(_D_inf.val)) << ((int)(_D_inf.val))))) - ((long)((((int)(*entry)) << ((int)(_D_inf.val))))) + ((short)((((int)(*entry)) ^ ((int)(*entry))))) * ((long)((((int)(*entry)) ^ ((int)(_D_inf.val))))) * ((int)((((int)(*entry)) & ((int)(*entry)))))) + 41 + ((long)((((int)(((long)((((int)(_D_inf.val)) << ((int)(_D_inf.val))))))) << ((int)(((long)((((int)(_D_inf.val)) << ((int)(_D_inf.val)))))))))) - ((long)((((int)(_D_inf.val)) << ((int)(((long)((((int)(_D_inf.val)) << ((int)(_D_inf.val)))))))))) + ((short)((((double)(_D_inf.val + 41 + ((long)((((int)(_D_inf.val)) << ((int)(_D_inf.val))))))) + ((double)(_D_inf.val + 41 + ((long)((((int)(_D_inf.val)) << ((int)(_D_inf.val)))))))))) * ((long)((((int)(_D_inf.val + 41 + ((long)((((int)(_D_inf.val)) << ((int)(_D_inf.val))))) - ((long)((((int)(*entry)) << ((int)(_D_inf.val))))))) ^ ((int)(((short)((((int)(*entry)) ^ ((int)(*entry))))) * ((long)((((int)(*entry)) ^ ((int)(_D_inf.val))))) * ((int)((((int)(*entry)) & ((int)(*entry)))))))))) * ((int)((((int)(_D_inf.val)) & ((int)(_D_inf.val + 41)))))))
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (!_D_inf2.val)
      deletedEntry = entry;

    i++;
  
break;

break;
}
  if (deletedEntry)
    *deletedEntry;
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
