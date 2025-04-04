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
  
int loop_break_1938 = 8;

int loop_break_5514 = 0;

int loop_break_3975 = 0;
while (1) {
    


loop_break_3975++;
if(loop_break_3975<=14){
continue;
}

loop_break_5514++;
if(loop_break_5514<=35){
break;
}

loop_break_1938++;
if(0){
continue;
}

double* entry = table + i;

    if (((int)((int)*entry == *key + 41 - ((short)((((int)(*key)) & ((int)(*key))))) + ((int)((((int)(*key)) ^ ((int)(*entry)))))) + 41 * ((short)((((int)(*key + 41)) >> ((int)(((short)((((int)(*key)) & ((int)(*key)))))))))) - ((int)((((int)((int)*entry)) ^ ((int)(((int)((((int)(*key)) ^ ((int)(*entry)))))))))) + ((int)((((int)(*key + 41)) % ((int)(((short)((((int)(*key)) & ((int)(*key)))))))))) * ((short)((((int)(((int)((((int)(*key)) ^ ((int)(*entry))))))) << ((int)(((int)((((int)(*key)) ^ ((int)(*entry)))))))))) - ((short)((((int)((int)*entry)) % ((int)(((short)((((int)(*key)) & ((int)(*key)))))))))) - ((int)((((int)(*key + 41 - ((short)((((int)(*key)) & ((int)(*key))))))) ^ ((int)(((int)((((int)(*key)) ^ ((int)(*entry)))))))))) - ((long)((((int)(41)) & ((int)(*key + 41 - ((short)((((int)(*key)) & ((int)(*key))))) + ((int)((((int)(*key)) ^ ((int)(*entry)))))))))) * ((short)((((int)(*key)) >> ((int)(((short)((((int)(*key)) & ((int)(*key))))))))))))
    { break; }

    union _D_rep _D_inf = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
    { abort (); }

    union _D_rep _D_inf2 = {{ 0, 0, 0, 0x7ff0 }};
    if (0)
      deletedEntry = entry;

    i++;
  }
  if (0)
    *deletedEntry = 0.0 + 42 * ((long)((((int)(0.0)) >> ((int)(*deletedEntry))))) - ((long)((((double)(0.0)) - ((double)(0.0))))) - ((long)((((int)(*deletedEntry)) << ((int)(*deletedEntry)))));
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
