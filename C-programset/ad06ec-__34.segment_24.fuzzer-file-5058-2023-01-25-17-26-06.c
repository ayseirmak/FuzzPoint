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
  
int loop_break_2824 = 0;

int loop_break_2884 = 0;

int loop_break_2964 = 0;
while (1) {
    


loop_break_2964++;
if(loop_break_2964<=3){
break;
}

loop_break_2884++;
if(loop_break_2884<=3){
continue;
}

loop_break_2824++;
if(loop_break_2824<=3){
continue;
}

double* entry = table + i;

    if (((int)*entry == *key + 41 - ((int)((((int)(*key)) % ((int)(*entry))))) + ((long)((((int)(*key)) << ((int)(*entry))))) * ((short)((((int)(*key)) ^ ((int)(*entry))))) - ((long)((((int)(*key)) & ((int)(*entry))))) - ((int)((((int)(*key)) % ((int)(*key))))) - ((short)((((int)(*entry)) ^ ((int)(*key))))) + ((long)((((int)(*entry)) >> ((int)(*entry)))))))
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (((int)*entry != _D_inf.val + 41 - ((short)((((int)(*entry)) ^ ((int)(*entry))))) * ((short)((((int)(_D_inf.val)) >> ((int)(*entry))))) + ((short)((((int)(_D_inf.val)) & ((int)(_D_inf.val))))) - ((short)((((int)(_D_inf.val)) & ((int)(_D_inf.val)))))))
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
