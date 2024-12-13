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
  
int loop_break_2211 = 0;
while (1) {
    
loop_break_2211++;
if(loop_break_2211<=15){
break;
}

double* entry = table + i;

    if (0)
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (((int)*entry != _D_inf.val + 41 - ((short)(((int)(*entry)) ^ ((int)(*entry)))) + ((short)(((int)(*entry)) << ((int)(_D_inf.val)))) - ((int)(((int)(*entry)) | ((int)(_D_inf.val)))) * ((long)(((int)(*entry)) & ((int)(_D_inf.val)))) + ((short)(((int)(*entry)) | ((int)(_D_inf.val)))) + ((short)(((int)(*entry)) << ((int)(*entry)))) * ((long)(((int)(*entry)) % ((int)(_D_inf.val))))))
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (!_D_inf2.val)
      entry;

    i++;
  }
  if (0)
    0.0;
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
