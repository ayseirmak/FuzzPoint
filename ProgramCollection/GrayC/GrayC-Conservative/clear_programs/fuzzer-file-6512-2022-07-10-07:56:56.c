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
  
int loop_break_4318 = 0;
while (1) {
    
loop_break_4318++;
if(loop_break_4318<=8){
break;
}

double* entry = table + i;

    if (((int)((int)*entry == *key + 41 * ((short)(((int)(*key)) >> ((int)(*key)))) + ((int)(((int)(*key)) | ((int)(*entry)))) - ((long)(((int)(*entry)) % ((int)(*key)))) + ((long)(((int)(*key)) & ((int)(*entry))))) + 41 * ((int)(((int)((int)(((int)(*key)) | ((int)(*entry))))) << ((int)((long)(((int)(*entry)) % ((int)(*key))))))) * ((short)(((int)((long)(((int)(*entry)) % ((int)(*key))))) ^ ((int)(*key + 41 * ((short)(((int)(*key)) >> ((int)(*key)))))))) - ((short)(((int)(*key + 41 * ((short)(((int)(*key)) >> ((int)(*key)))) + ((int)(((int)(*key)) | ((int)(*entry)))) - ((long)(((int)(*entry)) % ((int)(*key)))) + ((long)(((int)(*key)) & ((int)(*entry)))))) % ((int)((int)*entry)))) + ((short)(((int)(*key + 41 * ((short)(((int)(*key)) >> ((int)(*key)))))) % ((int)(*key)))) + ((short)(((int)((int)(((int)(*key)) | ((int)(*entry))))) & ((int)((long)(((int)(*entry)) % ((int)(*key))))))) + ((int)(((int)(*key + 41 * ((short)(((int)(*key)) >> ((int)(*key)))) + ((int)(((int)(*key)) | ((int)(*entry)))) - ((long)(((int)(*entry)) % ((int)(*key)))))) & ((int)(*key + 41 * ((short)(((int)(*key)) >> ((int)(*key))))))))))
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
    *deletedEntry = 0.0 + 42 + ((int)(((int)(0.0)) ^ ((int)(0.0)))) + ((int)(((int)(*deletedEntry)) ^ ((int)(*deletedEntry)))) * ((long)(((int)(0.0)) << ((int)(*deletedEntry)))) * ((short)(((double)(0.0)) + ((double)(0.0)))) * ((int)(((int)(*deletedEntry)) % ((int)(*deletedEntry)))) + 42 * ((long)(((double)(0.0 + 42 + ((int)(((int)(0.0)) ^ ((int)(0.0)))))) + ((double)(0.0)))) - ((int)(((double)(0.0)) - ((double)(0.0)))) - ((long)(((int)((int)(((int)(0.0)) ^ ((int)(0.0))))) % ((int)(((int)(((int)(*deletedEntry)) ^ ((int)(*deletedEntry)))) * ((long)(((int)(0.0)) << ((int)(*deletedEntry)))) * ((short)(((double)(0.0)) + ((double)(0.0)))) * ((int)(((int)(*deletedEntry)) % ((int)(*deletedEntry))))))));
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
