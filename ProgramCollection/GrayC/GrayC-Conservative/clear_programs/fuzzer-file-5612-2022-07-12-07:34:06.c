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
  
int loop_break_2464 = 0;
while (1) {
    
loop_break_2464++;
if(loop_break_2464<=47){
break;
}

double* entry = table + i;

    if (((int)*entry == *key + 41 - ((long)(((int)(*key)) % ((int)(*entry)))) * ((int)(((int)(*entry)) << ((int)(*entry)))) - ((short)(((int)(*key)) | ((int)(*entry)))) - ((short)(((int)(*key)) ^ ((int)(*key)))) + ((short)(((int)(*entry)) & ((int)(*entry)))) - ((short)(((int)(*key)) ^ ((int)(*key)))) - ((long)(((int)(*key)) >> ((int)(*entry)))) + ((long)(((int)(*entry)) ^ ((int)(*key)))) + ((int)(((int)(*key)) ^ ((int)(*key))))))
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
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
